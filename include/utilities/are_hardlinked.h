#ifndef ARE_HARDLINKED_H
#define ARE_HARDLINKED_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int are_hardlinked(const char *file1, const char *file2);

#endif // ARE_HARDLINKED_H