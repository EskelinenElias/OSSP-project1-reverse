# reverse

This project is a part of the course Operating Systems and Systems Programming.

The reverse command takes reads lines from an input stream and prints them in reverse order to an output stream. The input stream can be a file or standard input, and the output stream can be a file or standard output, according to which arguments are provided. 

## Usage  

Calling reverse with both input and output files:

```
reverse [input_file] [output_file]
```

Calling reverse with only input file:

```
reverse [input_file]
```

Calling reverse without any arguments will read user input from standard input and write the reversed lines to standard output.

```
reverse
```

## Implementation

The implementation uses a stack-like structure to store the lines read from the input stream. The lines are used using the ```getline``` function, so that lines can be as long as needed. 

The lines are then written from the stack to the output stream. The stack-like structure reverses the order of the lines, as the stack is a Last-In-First-Out (LIFO) data structure. 

The ```main``` function handles the command-line arguments, checks that files are valid and opens them, and then calls the ```reverse``` function to perform the reversal.

## Sources: 

- W3Schools: C Read Files, Available: https://www.w3schools.com/c/c_files_read.php 

- GeeksForGeeks: C Program to Read Content of a File, Available: https://www.geeksforgeeks.org/c-program-to-read-contents-of-whole-file/ 

- GeeksForGeeks: Command Line Arguments in C, Available: https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/ 

- GeeksForGeeks: Error Handling in C, Available: https://www.geeksforgeeks.org/error-handling-in-c/ # OSSP-project1-reverse
