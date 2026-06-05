# 📚 Library Management System (C)

A terminal-based Library Management System written in C. All data is stored in-memory.

## Features

- **Books** — Add, remove, search, display all books
- **Members** — Register/remove members, view all
- **Issue/Return** — Issue books to members, return them, view current issues

## Project Structure

```
library_management/
├── include/
│   ├── book.h       # Book struct & function declarations
│   ├── member.h     # Member struct & function declarations
│   └── issue.h      # Issue/return function declarations
├── src/
│   ├── main.c       # Menu loop & entry point
│   ├── book.c       # Book operations
│   ├── member.c     # Member operations
│   └── issue.c      # Issue & return logic
└── Makefile
```

## Build & Run

```bash
# Compile
make

# Run
./library

# Or do both at once
make run

# Clean build
make clean
```

## Requirements

- GCC (any modern version)
- Linux / macOS / WSL on Windows

## Rules

- A member can only hold **one book** at a time
- A book must be **returned before** the member can be removed
- Books currently **issued cannot be removed**
