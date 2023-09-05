#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define FIFO_NAME "my_fifo"

int main(int argc, char *argv[]) {
    int pipe_fd;
    char *message = "Hello, FIFO!"; // Message to be written into the FIFO

    // Create (or open if it already exists) the FIFO for writing only
    if ((pipe_fd = open(FIFO_NAME, O_WRONLY)) == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Write the message into the FIFO
    if (write(pipe_fd, message, strlen(message)) == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Close the FIFO
    close(pipe_fd);

    printf("Message sent to FIFO: \"%s\"\n", message);

    return 0;
}