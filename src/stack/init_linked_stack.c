#include "../../include/stack/init_linked_stack.h"

// Function to initialize a linked stack
linked_stack_t* init_linked_stack() {
    
    // Allocate memory for linked stack
    linked_stack_t* stack = malloc(sizeof(linked_stack_t));
    if (!stack) {
        
        // Failed to allocate memory for linked stack
        fprintf(stderr, "malloc failed\n");
        return NULL;
    }
    
    // Setup linked stack 
    stack->top = NULL;
    
    // Successfully initialized a stack 
    return stack;
}

// EOF