#include "../../include/stack/free_linked_stack.h"

// Function to free linked stack 
int free_linked_stack(linked_stack_t* stack) {
    
    // Input validation
    if (!stack) {
        
        // Invalid input
        fprintf(stderr, "Failed to free linked stack: invalid input\n");
        return ERROR;
    }
    
    // Free all elements in the stack
    linked_node_t* current_node = stack->top; 
    while (current_node) {
        
        // Get pointer to the next node in the stack 
        linked_node_t* next_node = current_node->next;
        
        // Free data stored in the node
        free(current_node->line);
        
        // Free the node itself
        free(current_node);
        
        // Swap the next node with the current node
        current_node = next_node;
    }
    
    // Free memory allocated for the stack itself
    free(stack);
    
    // Successfully freed linked stack
    return SUCCESS;
}

// EOF