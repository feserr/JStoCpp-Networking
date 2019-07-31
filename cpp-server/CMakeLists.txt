cmake_minimum_required(VERSION 3.3)

project(cpp_server VERSION 1.0 DESCRIPTION "C++ websocket server")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(TARGET_NAME cpp_server)

# Check and add the C++ version.
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++20" COMPILER_SUPPORTS_CXX20)
CHECK_CXX_COMPILER_FLAG("-std=c++17" COMPILER_SUPPORTS_CXX17)
CHECK_CXX_COMPILER_FLAG("-std=c++14" COMPILER_SUPPORTS_CXX14)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX20)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
elseif(COMPILER_SUPPORTS_CXX17)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
elseif(COMPILER_SUPPORTS_CXX14)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
elseif(COMPILER_SUPPORTS_CXX11)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
  message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++0x and higher support. Please use a different C++ compiler.")
endif()

# Set the source files.
set(SOURCES
  src/main.cpp
)

add_executable(${TARGET_NAME} ${SOURCES})

# Set warning level
if(MSVC)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
  target_compile_options(${TARGET_NAME} PRIVATE /W4 /WX)
else(MSVC)
  target_compile_options(${TARGET_NAME} PRIVATE -Wall -pedantic -Werror)
endif(MSVC)

# Set the debug or relese mode.
if (CMAKE_BUILD_TYPE MATCHES Debug)
  # Debug level
  target_compile_options(${TARGET_NAME} PRIVATE -g)
elseif (CMAKE_BUILD_TYPE MATCHES Release)
  # Optimization level
  target_compile_options(${TARGET_NAME} PRIVATE -O2)
else ()
  message( FATAL_ERROR "Set the build type with -DCMAKE_BUILD_TYPE=<type>")
endif()

FIND_PACKAGE( Boost 1.70 COMPONENTS REQUIRED )

find_path(OPENSSL_INCLUDE_DIR openssl
          HINTS "/usr/local/opt/openssl/include"
          PATH_SUFFIXES libxml2 )

find_library(OPENSSL_LIBRARY NAMES ssl libssl
             HINTS "/usr/local/opt/openssl/lib" )

# Bring the headers into the project.
include_directories(
  ${Boost_INCLUDE_DIR})

target_include_directories(${TARGET_NAME} PRIVATE src)
target_link_libraries(${TARGET_NAME} LINK_PUBLIC
  ${Boost_LIBRARIES} ${OPENSSL_LIBRARY})

