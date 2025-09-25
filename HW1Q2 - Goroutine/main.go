package main

import (
	"fmt"
	"io"
	"strconv"
	"sync"
	"time"
)

func main() {
	const COUNT = 1000000
	
	start := time.Now()
	defer func() {
		fmt.Println("Execution time:", time.Since(start))
	}()

	r, w := io.Pipe()     // Create r/w pipes for IPC
	var wg sync.WaitGroup // WaitGroup to wait for goroutines to finish
	wg.Add(2)             // 2 goroutines to wait for

	// Producer goroutine
	go func() {
		for i := 1; i <= COUNT; i++ {
			_, err := w.Write([]byte(strconv.Itoa(i) + "\n")) // Write to pipe
			fmt.Println("Producer:", i)                       // Log produced value
			if err != nil {                                   // Handle write error
				fmt.Println("Write error:", err)
				return
			}
		}
		w.Close() // Close the writer when done
		wg.Done() // Mark this goroutine as done
	}()

	go func() {
		buf := make([]byte, 16) // Buffer for reading
		for {
			n, err := r.Read(buf) // Read from pipe
			if err == io.EOF {    // End of data, exit loop
				break
			}
			if err != nil { // Handle read error
				fmt.Println("Read error:", err)
				return
			}
			fmt.Print("Consumer: ", string(buf[:n])) // Log consumed value
		}

		r.Close() // Close the reader when done
		wg.Done() // Mark this goroutine as done

	}()

	wg.Wait()           // Wait for both goroutines to finish
}
