/*
 * Copyright 2019 Elías Serrano. All rights reserved.
 * License: https://github.com/feserr/JsToCpp-Networking#license
 */

#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <string>
#include <thread>

// Echoes back all received WebSocket messages
void do_session(boost::asio::ip::tcp::socket& socket) {
  try {
    // Construct the stream by moving in the socket
    boost::beast::websocket::stream<boost::asio::ip::tcp::socket> ws{
        std::move(socket)};

    // Set a decorator to change the Server of the handshake
    ws.set_option(boost::beast::websocket::stream_base::decorator(
        [](boost::beast::websocket::response_type& res) {
          res.set(boost::beast::http::field::server,
                  std::string(BOOST_BEAST_VERSION_STRING) +
                      " websocket-server-sync");
        }));

    // Accept the websocket handshake
    ws.accept();

    for (;;) {
      // This buffer will hold the incoming message
      boost::beast::flat_buffer buffer;

      // Read a message
      ws.read(buffer);

      // Echo the message back
      ws.text(ws.got_text());
      // ws.write(buffer.data());
      ws.write(boost::asio::buffer(std::string("Hello from server!")));

      // Discard all of the bytes stored in the dynamic buffer
      buffer.consume(buffer.size());
    }
  } catch (boost::beast::system_error const& se) {
    // This indicates that the session was closed
    if (se.code() != boost::beast::websocket::error::closed)
      std::cerr << "Error: " << se.code().message() << std::endl;
  } catch (std::exception const& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}

int main(int argc, char** argv) {
  try {
    // Check command line arguments.
    if (argc != 3) {
      std::cerr << "Usage: " << argv[0] << " <address> <port>\n"
                << "Example:\n"
                << "    websocket-server-sync 0.0.0.0 8080\n";
      return EXIT_FAILURE;
    }

    auto const address = boost::beast::net::ip::make_address(argv[1]);
    auto const port = static_cast<uint16_t>(std::atoi(argv[2]));

    // The io_context is required for all I/O
    boost::beast::net::io_context ioc{1};

    // The acceptor receives incoming connections
    boost::asio::ip::tcp::acceptor acceptor{ioc, {address, port}};
    for (;;) {
      // This will receive the new connection
      boost::asio::ip::tcp::socket socket{ioc};

      // Block until we get a connection
      acceptor.accept(socket);

      // Launch the session, transferring ownership of the socket
      std::thread{std::bind(&do_session, std::move(socket))}.detach();
    }
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return 0;
}
