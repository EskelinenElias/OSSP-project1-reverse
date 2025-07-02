#include "../include/read_lines_to_stack.h"

// Function to read lines from a stream to a stack 
linked_stack_t* read_lines_to_stack(FILE* stream) {
    
    // Input validation
    if (!stream) {
        
        // Invalid input
        fprintf(stderr, "Failed to read line: invalid input\n");
        return NULL;
    }
    
    // Initialize linked stack 
    linked_stack_t* stack = init_linked_stack(); 
    if (!stack) {
        
        // Failed to initialize stack 
        fprintf(stderr, "Failed to read line: failed to initialize stack\n");
        return NULL;
    }
    
    // Read lines from the stream and push them to the stack 
    char* line = NULL;
    while ((line = read_line(stream))) {
        
        if (push_to_linked_stack(stack, line) != SUCCESS) {
            
            // Failed to push line to stack 
            fprintf(stderr, "Failed to read line: failed to push line to stack\n");
            free(line);
            free_linked_stack(stack);
            return NULL;
        } 
    }
    
    // Successfully read lines to stack 
    return stack;
}

// EOF