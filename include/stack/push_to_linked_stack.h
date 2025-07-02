#ifndef PUSH_TO_STACK_H
#define PUSH_TO_STACK_H

#include <stdio.h>
#include <stdlib.h>

#include "../constants.h"

#include "linked_stack.h"

// Function to push new item to stack 
int push_to_linked_stack(linked_stack_t* stack, char* line);

#endif // PUSH_TO_STACK_H