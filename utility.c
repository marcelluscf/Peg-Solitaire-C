#include <stdio.h>
#include <string.h>
#include "utility.h"

/* Tidy up residual data in stdin when encountering an error. You will
 * need to use this when there is a possibility that there will be
 * leftover characters in the input buffer. */
void read_rest_of_line(void)
{
    int ch;
    /* remove all characters from the buffer */
    while (ch = getc(stdin), ch != '\n' && ch != EOF)
        ;
    /* clear the error status of the input pointer */
    clearerr(stdin);
}


/* custom get input function that handles buffer overflow.
   returns the return value of fgets */
char *get_input(char *buffer)
{
    char *result = fgets(buffer, INPUT_LENGTH, stdin);

    if (result != NULL)
    {
        /* if no newline character, buffer overflown */
        if (buffer[strlen(buffer) - 1] != '\n')
            read_rest_of_line();

        /* replace newline character with null terminator */
        buffer[strlen(buffer) - 1] = '\0';
    }

    return result;
}


/* convert numeric grid value to letter (e.g. 2 to B) */
char number_to_letter(int i)
{
    return i + 'A';
}

int letter_to_number(char c)
{
    return c - 'A';
}
