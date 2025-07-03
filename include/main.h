#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "utilities/are_hardlinked.h"
#include "stack/init_linked_stack.h"
#include "stack/free_linked_stack.h"
#include "read_and_write/read_lines_to_stack.h"
#include "read_and_write/write_lines_from_stack.h"

#include "constants.h"

// Main function
int main(int argc, char *argv[]); 

#endif // MAIN_H