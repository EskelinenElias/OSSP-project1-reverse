#include "../include/are_hardlinked.h"

// Function to check if two files are hardlinked
int are_hardlinked(const char *file1, const char *file2) {
    struct stat stat1, stat2;
    
    // Get file stats from file 1
    if (stat(file1, &stat1) == -1) {
        fprintf(stderr, "Failed to check files: failed to get stats for file 1\n");
        return -1;
    }
    
    //  Get file stats from file 2
    if (stat(file2, &stat2) == -1) {
        fprintf(stderr, "Failed to check files: failed to get stats for file 2\n");
        return -1;
    }
    
    // Compare device ID and inode number
    return (stat1.st_dev == stat2.st_dev) && (stat1.st_ino == stat2.st_ino);
}

// EOF