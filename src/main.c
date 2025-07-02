#include "../include/main.h"

// Define constants
#define MAX_NUM_LINES 1000 // Maximum number of lines to read
#define MAX_LINE_LENGTH 256 // Maximum length of each line

int hardlinked(const char *file1, const char *file2) {
    struct stat stat1, stat2;
    
    // Get file status from file 1
    if (stat(file1, &stat1) == -1) {
        perror("Error stating first file");
        return -1;
    }
    
    //  Get file status from file 2
    if (stat(file2, &stat2) == -1) {
        perror("Error stating second file");
        return -1;
    }
    
    // Compare device ID and inode number
    return (stat1.st_dev == stat2.st_dev) && (stat1.st_ino == stat2.st_ino);
}

// Function to ask user for input and then print the lines in the input to console in reverse order
int reverseInput() {
    char *lines[MAX_NUM_LINES]; // Array for storing the lines
    int line_number = 0; // Variable for counting the lines
    
    // Get input from the standard input
    while (line_number < MAX_NUM_LINES && getchar() != '\n') {
        // Dynamically allocate memory
        lines[line_number] = malloc(MAX_LINE_LENGTH * sizeof(char)); 
        fgets(lines[line_number], MAX_LINE_LENGTH, stdin);
        // Remove trailing newline if present
        int len = strlen(lines[line_number]);
        if (len > 0 && lines[line_number][len-1] == '\n') {
            lines[line_number][len-1] = '\0';
        }
        // Increment line counter
        line_number++; 
    }
    
    // Print lines in reverse order to console
    for (int i = line_number - 1; i >= 0; i--) {
        printf("%s\n", lines[i]);
        free(lines[i]); // Free each line after writing
    }
    return 0;
}

// Function to print the lines in input file to console in reverse order
int reverseToConsole(const char *input_file) {
    // Open input file
    FILE *input = fopen(input_file, "r");
    if (input == NULL) { // Check that the file opened successfully
        fprintf(stderr, "reverse: cannot open file '%s'\n", input_file); 
        exit(1);
    }
    
    // Prepare variables
    char *lines[MAX_NUM_LINES]; // Array for storing the lines
    int line_number = 0; // Variable for counting the lines
    
    // Read lines from the input file until end of file or maximum number of lines is reached
    while (line_number < MAX_NUM_LINES && !feof(input)) {
        // Dynamically allocate memory for each line
        lines[line_number] = malloc(MAX_LINE_LENGTH * sizeof(char)); 
        // Read line and store it to the array
        if (fgets(lines[line_number], MAX_LINE_LENGTH, input) != NULL) {
            line_number++; // Increment line counter
        }
    }
    fclose(input); // Close the input file
    
    // Print lines in reverse order to console
    for (int i = line_number - 1; i >= 0; i--) {
        printf("%s", lines[i]);
        free(lines[i]); // Free each line after writing
    }
    return 0;
}

// Function to print lines in input file to output file in reverse order
int reverseToFile(const char *input_file, const char *output_file) {
    
    // Check that input and output files are not the same file
    if (!strcmp(input_file, output_file)) {
        fprintf(stderr, "reverse: input and output file must differ\n"); 
        exit(1); 
    }
    
    // Open input and output files
    FILE *input = fopen(input_file, "r");
    FILE *output = fopen(output_file, "w");
    
    // Check that the input file opened successfully
    if (input == NULL) { 
        fprintf(stderr, "reverse: cannot open file '%s'\n", input_file); 
        exit(1);
    }
    
    // Check that the output file opened successfully
    if (output == NULL) { 
        fprintf(stderr, "reverse: cannot open file '%s'\n", output_file); 
        exit(1);
    }
    
    // Check that the files are not hardlinked
    if (hardlinked(input_file, output_file)) {
        fprintf(stderr, "reverse: input and output file must differ\n"); 
        exit(1); 
    }
    
    // Prepare variables
    char *lines[MAX_NUM_LINES]; // Array for storing the lines
    int line_number = 0; // Variable for counting the lines
    
    // Read lines from the input file until end of file or maximum number of lines is reached
    while (line_number < MAX_NUM_LINES && !feof(input)) {
        // Dynamically allocate memory for each line
        lines[line_number] = malloc(MAX_LINE_LENGTH * sizeof(char)); 
        // Read line and store it to the array
        if (fgets(lines[line_number], MAX_LINE_LENGTH, input) != NULL) {
            line_number++; // Increment line counter
        }
    }
    fclose(input); // Close the input file
    
    // Write lines in reverse order to the output file
    for (int i = line_number - 1; i >= 0; i--) {
        fputs(lines[i], output); // Write line
        free(lines[i]); // Free each line after writing
    }
    fclose(output); // Close the output file
    return 0;
}

int main(int argc, char *argv[]) {
    // Check the number of input arguments
    if (argc == 3) {
        // Input and output filenames
        const char *input_file = argv[1];
        const char *output_file = argv[2];
        // Print lines in input file to the output file in reverse order
        if (reverseToFile(input_file, output_file) != 0) {
            printf("Something happened!"); 
        }  
    } else if (argc == 2) {
        // Input filename
        const char *input_file = argv[1];
        // Print lines in input file to the output file in reverse order
        if (reverseToConsole(input_file) != 0) {
            printf("Something happened!"); 
        } 
    } else if (argc == 1) {
        // Print lines from standard input in reverse order to standard output 
        reverseInput(); 
    } else {
        fprintf(stderr, "usage: reverse <input> <output>\n"); 
        return 1; 
    }
    return 0;
}

/*
int main(int argc, char *argv[]) {
    // Check the number of input arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }
    
    // Input and output filenames
    const char *input_file = argv[1];
    const char *output_file = argv[2];
    
    // Check that input and output files are not the same file
    if (!strcmp(input_file, output_file)) {
        fprintf(stderr, "Error: Input and output files cannot be the same\n"); 
        exit(1); 
    }
    
    // Open input file
    FILE *input = fopen(input_file, "r");
    if (input == NULL) { // Check that the file opened successfully
        perror("Error opening input file"); 
        return 1;
    }
    
    // Prepare variables
    char *lines[MAX_NUM_LINES]; // Array for storing the lines
    int line_number = 0; // Variable for counting the lines
    
    // Read lines from the input file until end of file or maximum number of lines is reached
    while (line_number < MAX_NUM_LINES && !feof(input)) {
        // Dynamically allocate memory for each line
        lines[line_number] = malloc(MAX_LINE_LENGTH * sizeof(char)); 
        // Read line and store it to the array
        if (fgets(lines[line_number], MAX_LINE_LENGTH, input) != NULL) {
            line_number++; // Increment line counter
        }
    }
    fclose(input); // Close the input file
    
    // Open the output file for writing
    FILE *output = fopen(output_file, "w");
    if (output == NULL) { // Check that the file opened successfully
        perror("Error opening output file");
        for (int i = 0; i < line_number; i++) {
            free(lines[i]); // Free memory allocated for the lines
        }
        return 1;
    }
    
    // Write lines in reverse order to the output file
    for (int i = line_number - 1; i >= 0; i--) {
        fputs(lines[i], output); // Write line
        free(lines[i]); // Free each line after writing
    }
    fclose(output); // Close the output file
    return 0;
}
*/

/*
// Function to print lines in input file to output file in reverse order
int reverseToFile(const char *input_file, const char *output_file) {
    
    // Check that input and output files are not the same file
    if (!strcmp(input_file, output_file)) {
        fprintf(stderr, "reverse: input and output file must differ\n"); 
        exit(1); 
    }
    
    // Open input file
    FILE *input = fopen(input_file, "r");
    if (input == NULL) { // Check that the file opened successfully
        fprintf(stderr, "reverse: cannot open file '%s'\n", input_file); 
        exit(1);
    }
    
    // Prepare variables
    char *lines[MAX_NUM_LINES]; // Array for storing the lines
    int line_number = 0; // Variable for counting the lines
    
    // Read lines from the input file until end of file or maximum number of lines is reached
    while (line_number < MAX_NUM_LINES && !feof(input)) {
        // Dynamically allocate memory for each line
        lines[line_number] = malloc(MAX_LINE_LENGTH * sizeof(char)); 
        // Read line and store it to the array
        if (fgets(lines[line_number], MAX_LINE_LENGTH, input) != NULL) {
            line_number++; // Increment line counter
        }
    }
    fclose(input); // Close the input file
    
    if (are_hardlinked(input_file, output_file)) {
        exit(1); 
    }
    
    // Open the output file for writing
    FILE *output = fopen(output_file, "w");
    if (output == NULL) { // Check that the file opened successfully
        fprintf(stderr, "reverse: cannot open file '%s'\n", output_file); 
        for (int i = 0; i < line_number; i++) {
            free(lines[i]); // Free memory allocated for the lines
        }
        exit(1);
    }
    
    // Write lines in reverse order to the output file
    for (int i = line_number - 1; i >= 0; i--) {
        fputs(lines[i], output); // Write line
        free(lines[i]); // Free each line after writing
    }
    fclose(output); // Close the output file
    return 0;
}
*/