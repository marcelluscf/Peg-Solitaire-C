#ifndef BOARD_H
#define BOARD_H

#include "utility.h"

#define BOARD_WIDTH 9
#define BOARD_HEIGHT 9


/* colour codes for displaying the board */
#define COLOR_RESET     "\x1b[0m"
#define COLOR_LINES     "\x1b[2;34m"    			/* blue */
#define COLOR_HOLE      "\x1b[2;34m"    			/* blue */
#define COLOR_PEG       "\x1b[1;37m"    			/* white */
#define COLOR_VALENTINES "\x1b[31;1m"				/* red */
#define COLOR_HOLE_VALENTINES      "\x1b[31;1m"		/* red */

enum cell_contents
{
    INVALID, HOLE, PEG

};

/* The initial game board - this is an example of the occasional
 * exception to the rule against global variables. Be aware that
 * this should be the only global variable in your program */
static const enum cell_contents master_board[BOARD_HEIGHT][BOARD_WIDTH] = {
{ INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID },
{ INVALID , INVALID, INVALID, PEG, PEG, PEG, INVALID, INVALID, INVALID },
{ INVALID, INVALID, INVALID, PEG, PEG, PEG, INVALID, INVALID, INVALID },
{ INVALID, PEG, PEG, PEG, PEG, PEG, PEG, PEG, INVALID },
{ INVALID, PEG, PEG, PEG, HOLE, PEG, PEG, PEG, INVALID },
{ INVALID, PEG, PEG, PEG, PEG, PEG, PEG, PEG, INVALID },
{ INVALID, INVALID, INVALID, PEG, PEG, PEG, INVALID, INVALID, INVALID },
{ INVALID, INVALID, INVALID, PEG, PEG, PEG, INVALID, INVALID, INVALID },
{ INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID }

        };


/* Square Board*/
static const enum cell_contents master_board_square[BOARD_HEIGHT][BOARD_WIDTH] = {
{ INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID },
{ INVALID, PEG, PEG, PEG, PEG, PEG, PEG, INVALID, INVALID},
{ INVALID, PEG, PEG, PEG, PEG, PEG, PEG, INVALID, INVALID},
{ INVALID, PEG, PEG, PEG, HOLE, PEG, PEG, INVALID, INVALID},
{ INVALID, PEG, PEG, PEG, PEG, PEG, PEG, INVALID, INVALID },
{ INVALID, PEG, PEG, PEG, PEG, PEG, PEG, INVALID, INVALID },
{ INVALID, PEG, PEG, PEG, PEG, PEG, PEG, INVALID, INVALID },
{ INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID },
{ INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID },

        };
/* German Board*/
static const enum cell_contents master_board_german[BOARD_HEIGHT][BOARD_WIDTH] = {
{ INVALID, INVALID, INVALID, PEG, PEG, PEG, INVALID, INVALID, INVALID },
{ INVALID, INVALID, INVALID, PEG, PEG, PEG, INVALID, INVALID, INVALID },
{ INVALID, INVALID, INVALID, PEG, PEG, PEG, INVALID, INVALID, INVALID },
{ PEG, PEG, PEG, PEG, PEG, PEG, PEG, PEG, PEG },
{ PEG, PEG, PEG, PEG, HOLE, PEG, PEG, PEG, PEG },
{ PEG, PEG, PEG, PEG, PEG, PEG, PEG, PEG, PEG },
{ INVALID, INVALID, INVALID, PEG, PEG, PEG, INVALID, INVALID, INVALID },
{ INVALID, INVALID, INVALID, PEG, PEG, PEG, INVALID, INVALID, INVALID },
{ INVALID, INVALID, INVALID, PEG, PEG, PEG, INVALID, INVALID, INVALID }
        };
/* European Board*/
static const enum cell_contents master_board_european[BOARD_HEIGHT][BOARD_WIDTH] = {
{ INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID },
{ INVALID, INVALID, INVALID, PEG, PEG, PEG, INVALID, INVALID },
{ INVALID, INVALID, PEG, PEG, PEG, PEG, PEG, INVALID },
{ INVALID, PEG, PEG, PEG, HOLE, PEG, PEG, PEG, INVALID },
{ INVALID, PEG, PEG, PEG, PEG, PEG, PEG, PEG, INVALID },
{ INVALID, PEG, PEG, PEG, PEG, PEG, PEG, PEG, INVALID },
{ INVALID, INVALID, PEG, PEG, PEG, PEG, PEG, INVALID },
{ INVALID, INVALID, INVALID, PEG, PEG, PEG, INVALID, INVALID, INVALID },
{ INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID }
        };
/* Diamond Board*/
static const enum cell_contents master_board_diamond[BOARD_HEIGHT][BOARD_WIDTH] = {
{ INVALID, INVALID, INVALID, INVALID, PEG, INVALID, INVALID, INVALID, INVALID },
{ INVALID, INVALID, INVALID, PEG, PEG, PEG, INVALID, INVALID, INVALID },
{ INVALID, INVALID, PEG, PEG, HOLE, PEG, PEG, INVALID, INVALID },
{ INVALID, PEG, PEG, PEG, PEG, PEG, PEG, PEG, INVALID },
{ PEG, PEG, PEG, PEG, PEG, PEG, PEG, PEG, PEG },
{ INVALID, PEG, PEG, PEG, PEG, PEG, PEG, PEG, INVALID },
{ INVALID, INVALID, PEG, PEG, PEG, PEG, PEG, INVALID, INVALID },
{ INVALID, INVALID, INVALID, PEG, PEG, PEG, INVALID, INVALID, INVALID },
{ INVALID, INVALID, INVALID, INVALID, PEG, INVALID, INVALID, INVALID, INVALID }
        };
/* Especial Board*/
static const enum cell_contents master_board_heart[BOARD_HEIGHT][BOARD_WIDTH] = {
{ INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID },
{ INVALID, PEG, PEG, PEG, PEG, PEG, PEG, PEG, INVALID },
{ PEG, PEG, PEG, PEG, PEG, PEG, PEG, PEG, PEG },
{ PEG, PEG, PEG, PEG, HOLE, PEG, PEG, PEG, PEG },
{ INVALID, PEG, PEG, PEG, PEG, PEG, PEG, PEG, INVALID },
{ INVALID, INVALID, PEG, PEG, PEG, PEG, PEG, INVALID, INVALID },
{ INVALID, INVALID, INVALID, PEG, PEG, PEG, INVALID, INVALID, INVALID},
{ INVALID, INVALID, INVALID, INVALID, PEG, INVALID, INVALID, INVALID, INVALID },
{ INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID, INVALID }

        };

/* global variable to set the special color */
static char master_color[50];
/* global variable to set the special color */
static char master_color_hole[50];

static int total_pegs;

static int master_title;


/* Requirement 2 - copies the contents of master_board to a local
 * board for each game */
void init_board(enum cell_contents board[][BOARD_WIDTH], int*);			


/* Requirement 4 - displays the puzzle game board to the screen */
void display_board(enum cell_contents board[][BOARD_WIDTH]);			


void display_line_row(int y, enum cell_contents board[][BOARD_WIDTH]);		

void display_peg_row(int y, enum cell_contents board[][BOARD_WIDTH]);		

void display_horizontal_coords(void);						

int display_scoreboard (enum cell_contents board [][BOARD_WIDTH]);

void display_movements (int);


BOOLEAN is_valid(int x, int y, enum cell_contents board[][BOARD_WIDTH]);

BOOLEAN is_peg(int x, int y, enum cell_contents board[][BOARD_WIDTH]);

BOOLEAN is_hole(int x, int y, enum cell_contents board[][BOARD_WIDTH]);


int get_peg_count(enum cell_contents board[][BOARD_WIDTH]);			

void title(void);

void title_standart(void);

void title_square(void);

void title_german(void);

void title_european(void);

void title_diamond(void);

void title_heart(void);

#endif
