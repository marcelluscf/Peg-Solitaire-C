#ifndef BOARD_H
#define BOARD_H

#include "utility.h"

#define BOARD_WIDTH 7
#define BOARD_HEIGHT 7

/* colour codes for displaying the board */
#define COLOR_RESET     "\x1b[0m"
#define COLOR_LINES     "\x1b[2;34m"    /* blue */
#define COLOR_HOLE      "\x1b[2;34m"    /* blue */
#define COLOR_PEG       "\x1b[1;37m"    /* white */

enum cell_contents
{
    INVALID, HOLE, PEG
};

/* The initial game board - this is an example of the occasional
 * exception to the rule against global variables. Be aware that
 * this should be the only global variable in your program */
static const enum cell_contents master_board[BOARD_HEIGHT][BOARD_WIDTH] = {
{ INVALID, INVALID, PEG, PEG, PEG, INVALID, INVALID },
{ INVALID, INVALID, PEG, PEG, PEG, INVALID, INVALID },
{ PEG, PEG, PEG, PEG, PEG, PEG, PEG },
{ PEG, PEG, PEG, HOLE, PEG, PEG, PEG },
{ PEG, PEG, PEG, PEG, PEG, PEG, PEG },
{ INVALID, INVALID, PEG, PEG, PEG, INVALID, INVALID },
{ INVALID, INVALID, PEG, PEG, PEG, INVALID, INVALID }
        };

/* Requirement 2 - copies the contents of master_board to a local
 * board for each game */
void init_board(enum cell_contents board[][BOARD_WIDTH]);			//body in line 5 board.c, appears in line 13 game.c


/* Requirement 4 - displays the puzzle game board to the screen */
void display_board(enum cell_contents board[][BOARD_WIDTH]);			//body in line 15 from board.c	


void display_line_row(int y, enum cell_contents board[][BOARD_WIDTH]);		//body in line 30, appears in line 22 e 25 from board.c

void display_peg_row(int y, enum cell_contents board[][BOARD_WIDTH]);		//body 58 board.c, appears 23 body.c				

void display_horizontal_coords(void);						//body line 85 board.c, appears line 26


BOOLEAN is_valid(int x, int y, enum cell_contents board[][BOARD_WIDTH]);

BOOLEAN is_peg(int x, int y, enum cell_contents board[][BOARD_WIDTH]);

BOOLEAN is_hole(int x, int y, enum cell_contents board[][BOARD_WIDTH]);


int get_peg_count(enum cell_contents board[][BOARD_WIDTH]);			//body 119 board.c

#endif
