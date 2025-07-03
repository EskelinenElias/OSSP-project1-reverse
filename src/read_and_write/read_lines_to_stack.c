#include "../../include/read_and_write/read_lines_to_stack.h"

// Function to read lines from a stream to a stack 
int read_lines_to_stack(linked_stack_t* stack, FILE* stream) {
    
    // Input validation
    if (!stack || !stream) {
        
        // Invalid input
        fprintf(stderr, "Failed to read line: invalid input\n");
        return ERROR;
    }
    
    // Read lines from the stream and push them to the stack 
    char* line = NULL;
    while ((line = read_line(stream))) {
        
        if (push_to_linked_stack(stack, line) != SUCCESS) {
            
            // Failed to push line to stack 
            fprintf(stderr, "Failed to read line: failed to push line to stack\n");
            free(line);
            free_linked_stack(stack);
            return ERROR;
        } 
    }
    
    // Successfully read lines to stack 
    return SUCCESS;
}

// EOF