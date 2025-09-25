#include <iostream>
#include <sys/wait.h>
#include <chrono>
#include <unistd.h>
#include <thread>

int main(int argc, char *argv[])
{
    const int COUNT = 1000000;
    //create start time point
    auto start = std::chrono::high_resolution_clock::now();
    int pipefd[2];              // pipefd[0] for reading, pipefd[1] for writing

    // Create a pipe
    if (pipe(pipefd) == -1)
    {
        std::cerr << "Pipe creation failed. Exiting..." << std::endl;
        return 1;
    }

    // fork
    pid_t pid;
    if ((pid = fork()) > 0)
    {                     // Parent process
        close(pipefd[0]); // Close read end for parent process
        for (int i = 0; i < COUNT; ++i)
        {
            std::cout << "Producer: " << i << std::endl;
            write(pipefd[1], &i, sizeof(i)); // Write to pipe
            std::this_thread::sleep_for(std::chrono::microseconds(1)); // used for simple synchronization
        }
        close(pipefd[1]); // Close write end
        wait(NULL);       // Wait for child process to finish
    }
    else if (pid == 0)
    {                     // Child process
        close(pipefd[1]); // Close write end for child process
        for (int i = 0; i < COUNT; ++i)
        {
            int value;
            read(pipefd[0], &value, sizeof(value)); // Read from pipe
            std::cout << "Consumer: " << value << std::endl;
        }
        close(pipefd[0]); // Close read end
        exit(0);          // Exit child process
    }
    else
    {
        std::cerr << "Fork failed!" << std::endl;
        return 1;
    }
    //create end time point
    auto end = std::chrono::high_resolution_clock::now();
    //calculate duration
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end -
                                                    start);
    std::cout << "Execution time: " << duration.count() << "ms" << std::endl;
    return 0;
}