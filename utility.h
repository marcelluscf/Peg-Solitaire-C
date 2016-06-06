#ifndef UTILITY_H
#define UTILITY_H

#define INPUT_LENGTH 20

typedef enum
{
    FALSE, TRUE
} BOOLEAN;

/* clears residual data from stdin */
void read_rest_of_line(void);			//body in line 8 from utility.c, appears in line 29 from utility.c


char *get_input(char *buffer);			//body in line 21 from utility.c, appears in line 55 from game.c(TERMINAR DEPOIS)		


char number_to_letter(int i);			//body in line 40 from utility.c, appears in line 92 from board.c(TERMINAR DEPOIS)

int letter_to_number(char c);			//body in line 45 from utility.c, appears in line 283 from game.c(TERMINAR DEPOIS)

#endif
