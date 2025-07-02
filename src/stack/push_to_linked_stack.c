#include "../../include/stack/push_to_linked_stack.h"

// Function to push a new element onto the stack
int push_to_linked_stack(linked_stack_t* stack, char* line) {
    
    // Input validation
    if (!stack || !line) {
        
        // Invalid input
        fprintf(stderr, "Invalid input\n");
        return ERROR; 
    }
    
    // Allocate memory for new node
    linked_node_t* new_node = malloc(sizeof(linked_node_t)); 
    if (!new_node) {
        
        // Failed to allocate memory for new node
        fprintf(stderr, "malloc failed\n");
        return ERROR; 
    }
    
    // Put the new node to the top of the stack
    new_node->line = line;
    new_node->next = stack->top;
    stack->top = new_node;
    
    // Successfully pushed the new element onto the stack
    return SUCCESS; 
}

// EOF 