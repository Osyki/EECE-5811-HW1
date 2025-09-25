# HW0 Inter-process Communication

Simple program that demonstrates a consumer-producer pattern through IPC between parent and child processes using pipes in C++. The parent process writes an integer (1 to 1000000) to the pipe, and the child process reads from the pipe. Both processes print the data they write/read to/from the pipe.

## Compilation and Execution

To compile program (using g++), run:

```
g++ main.cpp -o main
```

To execute the program, run:

```
./main
```

## Expected Output

When you run the program, you should see output similar to the following:

```
Producer: 1
Consumer: 1
Producer: 2
Consumer: 2
Producer: 3
Consumer: 3
Producer: 4
Consumer: 4
Producer: 5
Consumer: 5
...
Producer: 1000000
Consumer: 1000000
Execution time: 9573ms
```
## Libraries used:
- `<iostream>`: For input and output operations.
- `<sys/wait.h>`: For waiting on child processes.
- `<unistd.h>`: For POSIX operating system API, including pipe and fork functions. (Not needed on Windows)
- `<chrono>`: For program performance measurement.
- `<thread>`: For using sleep function to simulate processing time.