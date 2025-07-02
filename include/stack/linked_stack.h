#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in a stack 
typedef struct linked_node_s {
    char* line;
    struct linked_node_s* next;
} linked_node_t;

// Structure to represent a stack
typedef struct {
    linked_node_t* top; 
} linked_stack_t;

#endif // LINKED_STACK_H