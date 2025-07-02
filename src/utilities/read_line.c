#include "../../include/utilities/read_line.h"

// Function to read a line from a file or input stream
char* read_line(FILE* stream) {
    
    // Input validation
    if (!stream) {
        
        // Invalid input
        fprintf(stderr, "Failed to read line: invalid input\n");
        return NULL;
    }
    
    // Initialize variables
    char* buffer = NULL;
    size_t size = 0;

    // Read line from stream and check for errors
    size_t num_chars = getline(&buffer, &size, stream);
    if (num_chars == -1 && ferror(stream)) {
        
        // Failed to read line
        fprintf(stderr, "Failed to read line: failed to read line\n");
        free(buffer);
        return NULL;
    } 
    
    // Check for EOF or empty line
    if (num_chars <= 0 || feof(stream)) {
        
        // EOF or empty line; free buffer and return NULL
        free(buffer);
        return NULL;
    }

    // Remove trailing newline character
    if (buffer[num_chars - 1] == '\n') buffer[num_chars - 1] = '\0';

    // Successfully read line
    return buffer;
}

// EOF