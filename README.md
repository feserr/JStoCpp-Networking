JStoCpp-Networking
=======

[![Twitter URL](https://img.shields.io/badge/tweet-feserr-blue.svg?longCache=true&style=for-the-badge)](https://twitter.com/feserr_)
[![GitHub issue last update](https://img.shields.io/badge/updated-July%202019-red.svg?longCache=true&style=for-the-badge)](https://github.com/feserr/JStoCpp-Networking)

# Index

- [About](#about)
- [What's New?](#whats-new)
- [How to Build](#how-to-build)
- [Contributing](#contributing)
- [Bugs?](#bugs)
- [License](#license)

<a name="about"></a>
# JStoCpp-Networking 0.1

Websocket server C++ application that accept and reply to JS websocket.

Version: 0.1 - Released: 31rd July 2019

<a name="whats-new"></a>
## What's new in 0.1?

Initial version.

<a name="how-to-build"></a>
## How to Build

We make a folder and inside this folder we call to `cmake` specifying the build type (Debug or Release) and the type of the project.

For example, we want to build all the playgrounds in `Release` mode using `unix makefiles` inside a folder called `build`, we will do:
```bash
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles" ..
make
```

<a name="contributing"></a>
## Contributing

- If you find a bug then please report it on [GitHub Issues][issues].

- If you have a feature request, or have written a game or demo that shows JStoCpp-Networking in use, then please get in touch. We'd love to hear from you!

- If you issue a Pull Request for JStoCpp-Networking, please only do so against the `dev` branch and **not** against the `master` branch.

<a name="bugs"></a>
## Bugs?

Please add them to the [Issue Tracker][issues] with as much info as possible, especially source code demonstrating the issue.


<a name="license"></a>
## License
-----------------------------------------------------------------------

<a href="http://opensource.org/licenses/BSD-2-Clause" target="_blank">
<img align="right" width="100" height="137"
 src="https://opensource.org/files/OSI_Approved_License.png">
</a>

	BSD 2-Clause License

	Copyright (c) 2019, Elias Serrano
	All rights reserved.

	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions are met:

	1. Redistributions of source code must retain the above copyright notice, this
		list of conditions and the following disclaimer.

	2. Redistributions in binary form must reproduce the above copyright notice,
		this list of conditions and the following disclaimer in the documentation
		and/or other materials provided with the distribution.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
	AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
	DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
	FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
	DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
	SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
	CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
	OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
	OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

[issues]: https://github.com/feserr/JStoCpp-Networking/issues