# libjdk - Java Management RMI Library

![License](https://img.shields.io/badge/license-GPL%20v2%20with%20Classpath%20Exception-green.svg)
![Platforms](https://img.shields.io/badge/platforms-Windows%20|%20Linux%20|%20macOS-lightgrey.svg)

[**libjdk**](https://github.com/libjdk/libjdk) is a comprehensive C++ implementation of the Java Development Kit (JDK), providing native C++ libraries that mirror the functionality of Java's core libraries and modules. While it provides Java-like APIs, it runs as native C++ code without requiring a Java Virtual Machine.

## Overview

This project provides a complete C++ implementation of Java's management RMI functionality, including:

- **RMI Connector**: Service for remote JMX connections
- **Security Mechanisms**: Authentication and authorization support
- **Protocol Handling**: Implementation of the RMI protocol
- **Serialization Support**: Serialization and deserialization of management objects
- **Firewall Friendly**: Support for connections through firewalls

## Features

- ✅ **Cross-platform Support**: Windows, Linux, and macOS
- ✅ **CMake Build System**: Modern, portable build configuration
- ✅ **Shared/Static Libraries**: Flexible linking options
- ✅ **Comprehensive Testing**: Extensive test suite included
- ✅ **OpenJDK Compatible**: Based on OpenJDK 17.35
- ✅ **GPL Licensed**: Free software with Classpath exception

## Dependencies

- **java.base**: Core Java functionality (required)
- **java.management**: JMX management functionality (required)
- **java.rmi**: Remote Method Invocation support (required)

## Project Structure

```
java.management.rmi/
├── main/                   # Main source code
│   ├── classes/            # Java class implementations
│   ├── include/            # Header files
│   └── dependencies.txt    # Module dependencies
├── test/                   # Test suite
├── legal/                  # Legal notices and licenses
└── CMakeLists.txt          # Build configuration
```

## Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Add tests for new functionality
5. Ensure all tests pass
6. Submit a pull request

## License

This project is licensed under the GNU General Public License v2 with the Classpath exception, allowing linking with proprietary software. See the [LICENSE](LICENSE) file for details.

## Legal Notices

This project includes code from various open source projects. See the [legal/](legal/) directory for detailed licensing information for each component.