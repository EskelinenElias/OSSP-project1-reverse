#include "../../include/read_and_write/write_lines_from_stack.h"

// Function to write lines from a stack to a file stream
int write_lines_from_stack(linked_stack_t* stack, FILE* stream) {
    
    // Input validation
    if (!stack || !stream) {
        
        // Invalid input
        fprintf(stderr, "Failed to write lines from stack: invalid input\n");
        return ERROR;
    }
    
    // Write lines from stack to file stream
    char* line = NULL; 
    while ((line = pull_from_linked_stack(stack))) {
        
        // Write line to file stream
        fprintf(stream, "%s\n", line);
        
        // Free memory allocated for line
        free(line);
    }
    
    // Successfully wrote lines from stack
    return SUCCESS;
}

// EOF 