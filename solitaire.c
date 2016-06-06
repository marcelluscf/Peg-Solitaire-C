#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "solitaire.h"

int main(int argc, char *argv[])
{
    int selection = 0;
    while (selection != 3)
    {
        selection = process_menu();
        switch (selection)
        {
        case 1:
            play_game();
            break;
        case 2:
            display_how_to_play();
            break;
        }
    }
    return EXIT_SUCCESS;
}


/* ======================================================== FUNCTIONS */
/* return value is the menu selection */
int process_menu(void)
{
    display_menu();
    return get_menu_input();
}

int get_menu_input(void)
{
    char *end;
    char input[INPUT_LENGTH];
    int result;

    while (TRUE)
    {
        printf("Input numerical selection: ");

        if (get_input(input) == NULL)
        {
            printf("\n");
            return 3;
        }

        result = strtol(input, &end, 10);

        if (*end != '\0' || result < 1 || result > 3)
            printf("Invalid input. ");
        else
            break;
    }

    return result;
}

void display_menu(void)
{
    printf("\n\n\nPEG SOLITAIRE\n\n");
    printf("1. Play Game\n");
    printf("2. How to Play\n");
    printf("3. Quit\n\n");
}


void display_how_to_play(void)
{
    printf("\n\n\nHOW TO PLAY");
    printf("\n\nThe only valid move in Peg Solitaire is jump a peg over an");
    printf("\northogonally adjacent peg (up, down, left or right, not)");
    printf("\ndiagonal into an empty hole. So in the starting position, the");
    printf("\nvalid pegs that can jump are at B4, D2, D6 and F4 – all");
    printf("\njumping to the centre hole at D4. The peg that is jumped over");
    printf("\nis then removed from the game, leaving another hole.");

    printf("\n\nThe object of the game is to remove as many pegs as possible");
    printf("\nbefore you are left in a position without any valid moves");
    printf("\n(i.e. no pegs can make a valid jump). The ideal solution to");
    printf("\nthe puzzle is to be left with a single peg in the centre hole.");

    printf("\n\nMoves must be input in the following format:");
    printf("\n    <start_coord> <end_coord>");
    printf("\n    e.g. B4 D4");
    printf("\n\nThe above uses a space to separate the coords but commas,");
    printf("\nhyphens and tabs can also be used.");

    printf("\n\n\nPress ENTER to return to menu");
    if (getchar() != '\n') read_rest_of_line();			//header in line 12 from utility.h			
}
