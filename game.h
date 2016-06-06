#ifndef GAME_H
#define GAME_H

#include <string.h>
#include "board.h"
#include "utility.h"

struct position
{
    int x, y;
};

struct move
{
    struct position start, end;
};

enum move_validity
{
    VALID, MALFORMED_INPUT,
    INVALID_START_POSITION, INVALID_END_POSITION,
    START_NOT_PEG, END_NOT_HOLE, NOT_SAME_ROW_COLUMN, NO_PEG_TO_JUMP
};

enum move_result
{
    QUIT_GAME, SUCCESSFUL_MOVE
};

/* Requirement 3 - controls the flow of play in the game */
void play_game(void);

void display_result(enum cell_contents board[][BOARD_WIDTH]);

BOOLEAN process_ask_play_again(void);


/* Requirement 6 - tests to see whether a move is valid or not */
BOOLEAN is_valid_move(struct move move, enum cell_contents board[][BOARD_WIDTH], enum move_validity *move_validity);

struct position get_jumped_position(struct position p1, struct position p2, enum cell_contents board[][BOARD_HEIGHT]);


/* Requirement 7 - tests to see whether it is the end of the game */
BOOLEAN is_game_over(enum cell_contents board[][BOARD_WIDTH]);


/* Requirement 5 - handle the logic for each individual move */
enum move_result player_move(enum cell_contents board[][BOARD_WIDTH]);

enum move_validity try_get_move(struct move *move, char *input, enum cell_contents board[][BOARD_WIDTH]);

void perform_move(struct move move, enum cell_contents board[][BOARD_WIDTH]);


BOOLEAN is_same_row(struct position p1, struct position p2, int separation);

BOOLEAN is_same_column(struct position p1, struct position p2, int separation);


int get_valid_move_count(int x, int y, enum cell_contents board[][BOARD_WIDTH]);


BOOLEAN try_create_move_from_coords(struct move *move, char *start_coord, char *end_coord);

struct position create_position_from_coord(char *coord);

BOOLEAN is_valid_coord(char *coord);


struct move create_move(int x1, int y1, int x2, int y2);

void print_move_validity_string(enum move_validity move_validity);

#endif
