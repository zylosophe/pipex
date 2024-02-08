#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void redirect(int a, int b) {
    char buffer[1024];
    ssize_t bytes_read;

    // Read from a and write to b
    while ((bytes_read = read(a, buffer, sizeof(buffer))) > 0) {
        if (write(b, buffer, bytes_read) != bytes_read) {
            perror("write");
            exit(EXIT_FAILURE);
        }
    }

    if (bytes_read == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }
}

int main() {
    // Example usage:
    int pipe_a[2], pipe_b[2];

    // Creating the pipes
    if (pipe(pipe_a) == -1 || pipe(pipe_b) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Redirecting
    redirect(pipe_a[0], pipe_b[1]); // Redirecting from read end of 'a' to write end of 'b'

    // Example data transfer
    char buffer[1024];

    // Writing to 'a'
    write(pipe_a[1], "Hello, World!", 13);

    // Reading from 'b'
    ssize_t bytes_read = read(pipe_b[0], buffer, sizeof(buffer));
    if (bytes_read == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    // Printing what was read
    printf("Received: %.*s\n", (int)bytes_read, buffer);

    return 0;
}
