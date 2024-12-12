#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h> 

#define CHUNK_SIZE 1024 
int count_words_from_input() {
    char buffer[CHUNK_SIZE];
    ssize_t bytes_read;
    int word_count = 0;
    int in_word = 0;
    while ((bytes_read = read(STDIN_FILENO, buffer, CHUNK_SIZE)) > 0) 
    {
        for (ssize_t i = 0; i < bytes_read; i++) {

            if (isspace(buffer[i])) {

                if (in_word) {
                    word_count++;
                    in_word = 0;
                }
            } 
            
            else 
            {
                in_word = 1;
            }
        }
    }

    if (in_word) {
        word_count++;
    }

    return word_count;
}

int main() {
    int word_count = count_words_from_input();
    printf("Number of words: %d\n", word_count);
    return 0;
}

