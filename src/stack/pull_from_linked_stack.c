#include "../../include/stack/pull_from_linked_stack.h"

// Function to pull item from linked stack 
char* pull_from_linked_stack(linked_stack_t* stack) {
    
    // Input validation
    if (stack == NULL) {
        
        // Invalid input
        fprintf(stderr, "Failed to pull from linked stack: invalid input\n");
        return NULL;
    }
    
    // Check if stack is empty
    if (!stack->top) return NULL; 
    
    // Pull the top node from the stack 
    linked_node_t* top_node = stack->top;
    stack->top = top_node->next; 
    top_node->next = NULL; 
    
    // Get the line from the top node
    char* line = top_node->line;
    top_node->line = NULL; 
    
    // Free the top node
    free(top_node);
    
    // Successfully pulled item from stack
    return line;
}


// EOF