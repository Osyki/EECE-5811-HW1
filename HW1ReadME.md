# HW1 

## Format of Submission

The answer to question 1 and 2 are below. In the folders are the programs written for HW0 modified to include performance measurements and HW1Q2 written in Go. 

## Question 1: Goroutine and Thread

The main difference between Goroutines and Threads is that Goroutines are managed by the Go runtime, while threads are managed by the OS. This means that Goroutines are not hardware dependent and thus are more lightweight than threads. Goroutines hide the complexity of thread creation and management, allocating memory for Goroutines in the heap and can grow/shrink as needed. Other the other hand, threads are allocated in the stack and have a fixed size, requiring more overhead to manage.

###  Sources:
- [Goroutine Documentation](https://go.dev/doc/effective_go#goroutines):
Credible source as it is the official Go documentation.
- [Goroutines vs Threads](https://www.geeksforgeeks.org/go-language/golang-goroutine-vs-thread/):
Credible source as it is a well-known programming education website.
- [Goroutines and Threads](https://medium.com/@sairavitejachintakrindi/goroutines-and-threads-exploring-concurrency-in-go-370d609038c):
Credible source as it is a blog post by a software engineer exploring concurrency in Go.

## Question 2: Process and Thread/Goroutine
Each program is in its own folder along with a README file explaining how to compile and run the program. I modified HW0 to include performance measurements. Each program has a consumer/producer pattern where the parent process (or main goroutine) produces integers from 1 to 1,000,000 and sends them to the child process (or child goroutine) which consumes the integers and prints them. The time taken to execute the program is also printed. Goroutines were executed at almost 2x faster than the processes. I added a sleep of 1 microsecond in the consumer/child process (HW0) to simulate processing time for synchronization purposes. This could be a reason why the performance difference is not less significant.