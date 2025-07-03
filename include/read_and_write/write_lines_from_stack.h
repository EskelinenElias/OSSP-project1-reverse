#ifndef WRITE_LINES_FROM_STACK_H
#define WRITE_LINES_FROM_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../constants.h"
#include "../stack/pull_from_linked_stack.h"

// Function to write lines from a stack to a file stream
int write_lines_from_stack(linked_stack_t* stack, FILE* stream); 

#endif // WRITE_LINES_FROM_STACK_H