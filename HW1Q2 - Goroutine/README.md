# HW1 Process and Goroutine Communication

Simple program that demonstrates a consumer-producer pattern using Goroutines and pipes in Go. The producer Goroutine writes an an integer (1 to 1000000) to the pipe, and the consumer Goroutine reads from the pipe. Both processes print the data they write/read to/from the pipe. Time is taken to measure performance.

## Compilation and Execution

To compile program (using go), run:

```go build main.go
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
Execution time: 3.95432s
```
## Libraries used:
- `"fmt"`: For input and output operations.
- `"io"`: For pipe operations.
- `"strconv"`: For converting integers to strings.
- `"time"`: For program performance measurement.
- `"sync"`: For synchronizing Goroutines.