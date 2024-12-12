#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define BUFFER_SIZE 512

void print_error(const char *message) {
    fprintf(stderr, "Error: %s. %s\n", message, strerror(errno));
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 3) 
    {
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *source_file = argv[1];    
    const char *destination_file = argv[2];

    int source_fd = open(source_file, O_RDONLY);
    if (source_fd < 0)
    {
        print_error("Could not open source file");
    }

    int dest_fd = open(destination_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd < 0)
    {
        close(source_fd);
        print_error("Could not open destination file");
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;
    while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0)
    {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written < 0)
        {
            close(source_fd);
            close(dest_fd);
            print_error("Error writing to destination file");
        }
    }

    if (bytes_read < 0)
    {
        close(source_fd);
        close(dest_fd);
        print_error("Error reading from source file");
    }

    if (close(source_fd) < 0) {
        print_error("Error closing source file");
    }
    if (close(dest_fd) < 0) {
        print_error("Error closing destination file");
    }

    printf("File copied successfully from %s to %s.\n", source_file, destination_file);

    return EXIT_SUCCESS;
}

