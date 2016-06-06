#ifndef UTILITY_H
#define UTILITY_H

#define INPUT_LENGTH 20

typedef enum
{
    FALSE, TRUE
} BOOLEAN;

/* clears residual data from stdin */
void read_rest_of_line(void);


char *get_input(char *buffer);


char number_to_letter(int i);

int letter_to_number(char c);

#endif
