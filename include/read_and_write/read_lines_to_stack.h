#ifndef READ_LINES_TO_STACK_H
#define READ_LINES_TO_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../constants.h"
#include "../utilities/read_line.h"
#include "../stack/free_linked_stack.h"
#include "../stack/push_to_linked_stack.h"

// Function to read lines from a stream to a stack 
int read_lines_to_stack(linked_stack_t* stack, FILE* stream); 

#endif // READ_LINES_TO_STACK_H