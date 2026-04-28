# C++ Project Instruction Manual

This project uses a simple C++ folder structure:

```txt
project/
├── include/              Header files go here
├── src/                  Source files go here
├── build/                Compiled output goes here
├── .vscode/
│   ├── tasks.json        VS Code build command
│   └── launch.json       VS Code debug/run config
└── compile_flags.txt     clangd configuration for VS Code IntelliSense
```

## 1. Where To Add Header Files

Add all header files inside the `include/` folder.

Example:

```txt
include/Queue.h
```

A header file should contain declarations, such as class definitions, function declarations, and include guards.

Example `include/Queue.h`:

```cpp
#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
private:
    int size;

public:
    Queue();
    void insert_node(int data);
    void delete_node();
    void print_queue();
};

#endif // QUEUE_H
```

## 2. Where To Add Source Files

Add implementation files inside the `src/` folder.

Example:

```txt
src/Queue.cpp
```

The `.cpp` file should include its matching header file by name only.

Example `src/Queue.cpp`:

```cpp
#include <iostream>
#include "Queue.h"

Queue::Queue()
{
    size = 0;
}

void Queue::insert_node(int data)
{
    // Implementation here
}
```

## 3. How To Include Header Files

Because this project is configured to search inside the `include/` folder, always include project headers like this:

```cpp
#include "Queue.h"
```

Do not use relative paths like this:

```cpp
#include "../include/Queue.h"
```

The clean include style works because both the compiler and clangd are configured to know about the `include/` folder.

## 4. How clangd Finds Headers

VS Code uses clangd to show C++ warnings, errors, autocomplete, and red underlines.

clangd reads this file:

```txt
compile_flags.txt
```

Current contents:

```txt
-x
c++
-std=c++17
-Iinclude
```

Meaning:

```txt
-x c++       Treat files, including .h files, as C++
-std=c++17  Use the C++17 standard
-Iinclude   Search the include/ folder for header files
```

This is why clangd understands:

```cpp
#include "Queue.h"
```

If VS Code still shows old red underlines after adding a new header, restart clangd or reload the VS Code window.

## 5. How The Project Is Compiled

The project is compiled by the VS Code build task in:

```txt
.vscode/tasks.json
```

The important part is:

```json
"args": [
  "-std=c++17",
  "-g",
  "-I${workspaceFolder}/include",
  "src/main.cpp",
  "src/LinkedList.cpp",
  "src/Stack.cpp",
  "src/CircularQueue.cpp",
  "-o",
  "build/main"
]
```

Meaning:

```txt
-std=c++17                         Compile using C++17
-g                                 Include debug information
-I${workspaceFolder}/include       Tell the compiler where headers are
src/main.cpp                       Compile main.cpp
src/LinkedList.cpp                 Compile LinkedList.cpp
src/Stack.cpp                      Compile Stack.cpp
src/CircularQueue.cpp              Compile CircularQueue.cpp
-o build/main                      Save output executable as build/main
```

## 6. How To Add A New Class To The Project

Suppose you want to add a new class called `Queue`.

### Step 1: Create the header file

Create:

```txt
include/Queue.h
```

Add the class declaration there.

### Step 2: Create the source file

Create:

```txt
src/Queue.cpp
```

At the top of `Queue.cpp`, include the header:

```cpp
#include "Queue.h"
```

### Step 3: Include it where you use it

If you want to use `Queue` inside `main.cpp`, add:

```cpp
#include "Queue.h"
```

Then use it normally:

```cpp
int main()
{
    Queue q;
    q.insert_node(10);
    return 0;
}
```

### Step 4: Add the new `.cpp` file to the build task

Open:

```txt
.vscode/tasks.json
```

Add the new source file to the `args` list:

```json
"src/Queue.cpp",
```

Example:

```json
"args": [
  "-std=c++17",
  "-g",
  "-I${workspaceFolder}/include",
  "src/main.cpp",
  "src/LinkedList.cpp",
  "src/Stack.cpp",
  "src/CircularQueue.cpp",
  "src/Queue.cpp",
  "-o",
  "build/main"
]
```

This step is necessary because the compiler only compiles the `.cpp` files listed in `tasks.json`.

## 7. Important Rule: Headers Are Included, Source Files Are Compiled

Header files are included with `#include`:

```cpp
#include "Queue.h"
```

Source files are not included with `#include`.

Do not do this:

```cpp
#include "Queue.cpp"
```

Instead, add the `.cpp` file to `.vscode/tasks.json` so it gets compiled with the rest of the project.

## 8. How To Build In VS Code

Use one of these options:

```txt
Terminal > Run Build Task
```

or press:

```txt
Cmd + Shift + B
```

The build task creates the executable here:

```txt
build/main
```

## 9. How To Run Or Debug

The debug configuration is in:

```txt
.vscode/launch.json
```

It runs:

```txt
build/main
```

Before running, it automatically uses the build task:

```json
"preLaunchTask": "build cpp"
```

So when you start debugging, VS Code first compiles the project and then runs the latest executable.

## 10. Common Problems And Fixes

### Problem: Header file has red underline in VS Code

Check that:

```txt
compile_flags.txt
```

contains:

```txt
-Iinclude
```

Also make sure your include looks like:

```cpp
#include "Queue.h"
```

Then restart clangd or reload VS Code.

### Problem: Invalid argument '-std=c++17' not allowed with 'C'

This happens when clangd treats a `.h` file as C instead of C++.

Make sure `compile_flags.txt` contains:

```txt
-x
c++
```

### Problem: Code compiles but linker shows undefined symbols

This usually means you created a `.cpp` file but did not add it to `.vscode/tasks.json`.

Fix it by adding the file:

```json
"src/Queue.cpp",
```

### Problem: Header file not found during build

Make sure `.vscode/tasks.json` contains:

```json
"-I${workspaceFolder}/include",
```

## 11. Quick Checklist For Adding A New File

When adding a new class or module:

```txt
1. Add the header file to include/
2. Add the source file to src/
3. Use #include "FileName.h"
4. Add the new .cpp file to .vscode/tasks.json
5. Build with Cmd + Shift + B
6. Restart clangd if VS Code still shows old warnings
```

