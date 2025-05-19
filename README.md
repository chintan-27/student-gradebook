# Student Gradebook CLI Tool

This project was built to practice low-level C++ development and toolchain setup before diving into more advanced topics. The goal was to set up a proper C++ dev environment (with `clang++`, `CMake`, sanitizers, and profilers), understand how to use debugging and memory tools, and build a complete CLI utility using modern C++. The tool reads a CSV file of student scores, calculates their averages, and exports the results. Along the way, we used `AddressSanitizer`, LLDB, `sample`, and Instruments on macOS for debugging and profiling.

---

## Features

- Load student names and scores from a CSV file
- Compute average scores for each student
- Export results to `averages.csv`
- Interactive CLI menu
- Safe memory handling with `new` and `delete`
- Built with CMake and tested under AddressSanitizer

---

## Project Structure

```

Student-Gradebook/
├── include/
│   ├── student.hpp
│   └── csv_utils.hpp
├── src/
│   ├── main.cpp
│   ├── student.cpp
│   └── csv_utils.cpp
├── CMakeLists.txt
└── README.md

````

---

## 🧪 Example Input CSV

```csv
name,math,science,history
Alice,90,85,95
Bob,70,60,65
Charlie,100,100,100
````

---

## ▶️ How to Run

### 1. Build the Project

```bash
mkdir -p build && cd build
cmake ..
make
```

### 2. Run It

```bash
./gradebook ../test_data/students.csv
```

---

## 🛠️ Build & Debug Options

Compile with sanitizer and debug symbols:

```bash
cmake -DCMAKE_BUILD_TYPE=Debug ..
```

Run under address sanitizer:

```bash
./gradebook ../test_data/students.csv
```

Sample performance (macOS only):

```bash
# In another terminal:
sample gradebook -wait 5 -file sample_report.txt
```

---

## License

MIT License

```
Copyright (c) 2025 Chintan Acharya

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

```