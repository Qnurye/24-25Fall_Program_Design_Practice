# 24-25Fall_Program_Design_Practice
2024-2025 年程序设计实训

## Tech Stack

- [C 17](https://en.wikipedia.org/wiki/C17_(C_standard_revision))
- [GTK 4.0](https://docs.gtk.org/gtk4/index.html)
- [MariaDB Connector](https://mariadb.com/kb/en/mariadb-connector-c/)

## Getting Started

1. Clone the repository:
   ```
   git clone https://github.com/your-username/24-25Fall_Program_Design_Practice.git
   cd 24-25Fall_Program_Design_Practice
   ```

2. Install dependencies:
   - GTK 4.0
   - MariaDB Connector/C
   - CMake (version 3.10 or higher)

3. Build the project:
   ```
   mkdir build
   cd build
   cmake ..
   make
   ```

4. Run the application:
   ```
   ./Var4
   ```

## Project Structure

- `src/`: Source code
  - `controllers/`: Business logic
  - `models/`: Data models
  - `views/`: UI components
  - `database/`: Database operations
- `docs/`: Documentation
- `sql/`: SQL scripts for database setup
- `config/`: Configuration files

## Development Guidelines

- Follow the MVC (Model-View-Controller) pattern
- Use GTK 4.0 for UI development
- Implement database operations using MariaDB Connector/C

For more detailed development information, see [dev.md](docs/dev.md).

## Contributing

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
