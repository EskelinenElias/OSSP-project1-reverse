#include "../include/main.h"

// Main function
int main(int argc, char *argv[]) {
    
    // Input validation
    if (argc < 1 || argc > 3) {
        
        // Invalid input
        fprintf(stderr, "usage: reverse <input> <output>\n"); 
        return ERROR; 
    }
    
    // Check that the input file can be accessed for reading
    if (argc >= 2 && (access(argv[1], F_OK) != 0 || access(argv[1], R_OK) != 0)) {
        
        // Cannot access input file
        fprintf(stderr, "reverse: cannot open file '%s'\n", argv[1]);
        return ERROR;
    } 
    
    // Check that the output file can be accessed for writing
    if (argc == 3 && (access(argv[2], F_OK) != 0 || access(argv[2], W_OK) != 0)) {
        
        // Cannot access output file
        fprintf(stderr, "reverse: cannot open file '%s'\n", argv[2]);
        return ERROR;
    }
    
    // Check if input and output are the same file
    if (argc == 3 && are_hardlinked(argv[1], argv[2])) {
        
        // Input and output cannot be the same file
        fprintf(stderr, "reverse: input and output file must differ\n");
        return ERROR;
    }
    
    // Setup the correct output stream
    FILE* output_stream = stdout; 
    if (argc == 3 && !(output_stream = fopen(argv[2], "w"))) {
            
        // Cannot open output file
        fprintf(stderr, "reverse: cannot open file '%s'\n", argv[2]);
        return ERROR;
    }
    
    // Setup the correct input stream
    FILE* input_stream = stdin;
    if (argc >= 2 && !(input_stream = fopen(argv[1], "r"))) {
            
        // Cannot open input file
        fprintf(stderr, "reverse: cannot open file '%s'\n", argv[1]);
        if (argc == 3) fclose(output_stream); 
        return ERROR;
    }
    
    // Initialize the stack
    linked_stack_t* stack = init_linked_stack();
    if (!stack) {
        
        // Failed to initialize stack
        fprintf(stderr, "reverse: cannot initialize stack\n");
        if (argc == 3) fclose(output_stream); 
        if (argc >= 2) fclose(input_stream);
        return ERROR;
    }
            
    // Read lines from input stream to a stack 
    if (read_lines_to_stack(stack, input_stream) != SUCCESS) {
        
        // Cannot read lines from input file
        fprintf(stderr, "reverse: cannot read lines from file '%s'\n", argv[1]);
        free_linked_stack(stack); 
        if (argc == 3) fclose(output_stream); 
        if (argc >= 2) fclose(input_stream);
        return ERROR;
    }
    
    // Write lines from stack to output stream
    if (write_lines_from_stack(stack, output_stream) != SUCCESS) {
        
        // Cannot write lines to output file
        fprintf(stderr, "reverse: cannot write lines to file '%s'\n", argv[2]);
        free_linked_stack(stack); 
        if (argc == 3) fclose(output_stream); 
        if (argc >= 2) fclose(input_stream);
        return ERROR;
    }
    
    // Free the stack 
    free_linked_stack(stack);
    
    // Close input and output streams
    if (argc == 3) fclose(output_stream); 
    if (argc >= 2) fclose(input_stream);
    
    // Successfully completed
    return SUCCESS;
}

// EOF