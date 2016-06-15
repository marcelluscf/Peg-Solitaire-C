#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "game.h"

void play_game(void)
{
	int fimjogo = 0;
    do
    {
        enum move_result move_result = SUCCESSFUL_MOVE;
        enum cell_contents board[BOARD_HEIGHT][BOARD_WIDTH];
        init_board(board, &fimjogo);									//body in line 5 board.c, header in in line 35 from board.h					
		
		
		if (fimjogo == 7)
			break; 

        /* game loop */
        while (!is_game_over(board) && move_result != QUIT_GAME)
            move_result = player_move(board);

        /* if result is QUIT_GAME, break prematurely */
        if (move_result == QUIT_GAME)
            break;

        display_result(board);
    }
    while (process_ask_play_again());
}


void display_result(enum cell_contents board[][BOARD_WIDTH])
{
    int peg_count = get_peg_count(board);			//body 119 board.c, header 56 board.h

    display_board(board);			//body in line 15 from board.c, header in line 39 from board.h
    printf("\n");

    if (peg_count == 1)
    {
        if (board[BOARD_HEIGHT / 2][BOARD_WIDTH / 2] == PEG)
            printf("You finished the puzzle with a single peg left in the centre hole!");
        else
            printf("You finished the puzzle with a single peg left.");
    }
    else
        printf("There are no more moves with %d pegs left.", peg_count);
}

BOOLEAN process_ask_play_again(void)
{
    char input[INPUT_LENGTH];

    printf("\n\n");
    while (TRUE)
    {
        printf("Would you like to play again? (Y/N) ");

        if (get_input(input) == NULL)
            return FALSE;
        else if (strlen(input) == 1)
        {
            if (toupper(input[0]) == 'Y') return TRUE;
            else if (toupper(input[0]) == 'N') return FALSE;
        }

        printf("Invalid input. ");
    }

    return FALSE;
}


/* Requirement 6 - tests to see whether a move is valid or not */
BOOLEAN is_valid_move(struct move move, enum cell_contents board[][BOARD_WIDTH], enum move_validity *move_validity)
{
    struct position jump_pos;

    /* check both positions are valid */
    if (!is_valid(move.start.x, move.start.y, board))
    {
        if (move_validity != NULL) *move_validity = INVALID_START_POSITION;
        return FALSE;
    }
    if (!is_valid(move.end.x, move.end.y, board))
    {
        if (move_validity != NULL) *move_validity = INVALID_END_POSITION;
        return FALSE;
    }

    /* check start is peg and end is hole */
    if (!is_peg(move.start.x, move.start.y, board))
    {
        if (move_validity != NULL) *move_validity = START_NOT_PEG;
        return FALSE;
    }
    if (!is_hole(move.end.x, move.end.y, board))
    {
        if (move_validity != NULL) *move_validity = END_NOT_HOLE;
        return FALSE;
    }

    /* check positions are on the same row/column and separated by 1 cell */
    if (!is_same_row(move.start, move.end, 2) && !is_same_column(move.start, move.end, 2))
    {
        if (move_validity != NULL) *move_validity = NOT_SAME_ROW_COLUMN;
        return FALSE;
    }

    /* final check: there is a peg in between the positions */
    jump_pos = get_jumped_position(move.start, move.end, board);
    if (board[jump_pos.y][jump_pos.x] == PEG)
    {
        if (move_validity != NULL) *move_validity = VALID;
        return TRUE;
    }
    else
    {
        if (move_validity != NULL) *move_validity = NO_PEG_TO_JUMP;
        return FALSE;
    }
}

/* returns the position between 2 positions, this function makes the assumption
   that is_valid_move() has been passed */
struct position get_jumped_position(struct position p1, struct position p2, enum cell_contents board[][BOARD_HEIGHT])
{
    struct position pos;
    pos.x = p1.x;
    pos.y = p1.y;

    if (is_same_row(p1, p2, 2))
    {
        if (p1.y > p2.y)
            pos.y = p1.y - 1;
        else
            pos.y = p1.y + 1;
    }
    else if (is_same_column(p1, p2, 2))
    {
        if (p1.x > p2.x)
            pos.x = p1.x - 1;
        else
            pos.x = p1.x + 1;
    }

    return pos;
}


/* Requirement 7 - tests to see whether it is the end of the game */
BOOLEAN is_game_over(enum cell_contents board[][BOARD_WIDTH])
{
    int x, y;

    for (y = 0; y < BOARD_HEIGHT; y++)
    {
        for (x = 0; x < BOARD_HEIGHT; x++)
        {
            if (is_peg(x, y, board) && get_valid_move_count(x, y, board) > 0)
                return FALSE;
        }
    }

    return TRUE;
}


/* Requirement 5 - handle the logic for each individual move */
enum move_result player_move(enum cell_contents board[][BOARD_WIDTH])
{
    char input[INPUT_LENGTH];
    struct move move;
    enum move_validity move_validity;

    while (TRUE)
    {
        display_board(board);				//body in line 15 from board.c, header in line 39 from board.h		

        printf("\nPlease enter a move [enter Q or ctrl-D to quit]: ");

        /* quit conditions */
        if (get_input(input) == NULL)
            return QUIT_GAME;
        else if (strlen(input) == 1 && toupper(input[0]) == 'Q')
            return QUIT_GAME;

        move_validity = try_get_move(&move, input, board);
        if (move_validity == VALID)
        {
            perform_move(move, board);
            return SUCCESSFUL_MOVE;
        }
        else
            print_move_validity_string(move_validity);
    }
	
    return SUCCESSFUL_MOVE;
}

/* tries to create a move from input, result returned in move_validity */
enum move_validity try_get_move(struct move *move, char *input, enum cell_contents board[][BOARD_WIDTH])
{
    enum move_validity move_validity;
    struct move tmp_move;
    char *start_coord;
    char *end_coord;
    char *delims = "- ,\t";

    /* only accept input if there are exactly 2 delimeter separated values */
    start_coord = strtok(input, delims);
    if (start_coord == NULL) return MALFORMED_INPUT; /* 0 values, thus invalid */
    end_coord = strtok(NULL, delims);
    if (end_coord == NULL) return MALFORMED_INPUT; /* only 1 value, thus invalid */
    if (strtok(NULL, delims) != NULL) return MALFORMED_INPUT; /* more than 2 values, thus invalid */

    /* creates move if coords formatted correctly */
    if (!try_create_move_from_coords(&tmp_move, start_coord, end_coord))
        return MALFORMED_INPUT;

    /* check validity of move */
    if (is_valid_move(tmp_move, board, &move_validity))
        *move = tmp_move;
    return move_validity;
}

void perform_move(struct move move, enum cell_contents board[][BOARD_WIDTH])
{
    struct position jump_pos = get_jumped_position(move.start, move.end, board);

    /* remove jumped peg */
    board[jump_pos.y][jump_pos.x] = HOLE;

    /* add peg to end and remove peg from start */
    board[move.start.y][move.start.x] = HOLE;
    board[move.end.y][move.end.x] = PEG;
}


BOOLEAN is_same_row(struct position p1, struct position p2, int separation)
{
    if (p1.x == p2.x && abs(p1.y - p2.y) == separation) return TRUE;
    else return FALSE;
}

BOOLEAN is_same_column(struct position p1, struct position p2, int separation)
{
    if (p1.y == p2.y && abs(p1.x - p2.x) == separation) return TRUE;
    else return FALSE;
}


int get_valid_move_count(int x, int y, enum cell_contents board[][BOARD_WIDTH])
{
    int count = 0;
    struct move move;

    /* check all four directions */
    move = create_move(x, y, x - 2, y);
    if (is_valid_move(move, board, NULL)) count++;
    move = create_move(x, y, x + 2, y);
    if (is_valid_move(move, board, NULL)) count++;
    move = create_move(x, y, x, y - 2);
    if (is_valid_move(move, board, NULL)) count++;
    move = create_move(x, y, x, y + 2);
    if (is_valid_move(move, board, NULL)) count++;

    return count;
}


/* tries to create move from coords. if either coord is not in the correct format (e.g. B4), return FALSE */
BOOLEAN try_create_move_from_coords(struct move *move, char *start_coord, char *end_coord)
{
    if (is_valid_coord(start_coord) && is_valid_coord(end_coord))
    {
        move->start = create_position_from_coord(start_coord);
        move->end = create_position_from_coord(end_coord);
        return TRUE;
    }
    else
        return FALSE;
}

struct position create_position_from_coord(char *coord)
{
    struct position pos;
    pos.x = letter_to_number(toupper(coord[0]));
    pos.y = coord[1] - '0' - 1; /* convert char to numeric representation by subtracting '0' then convert to zero index by subtracting 1 */
    return pos;
}

/* checks if string is in the form "B4" etc. */
BOOLEAN is_valid_coord(char *coord)
{
    if (strlen(coord) != 2) return FALSE;
    if (isalpha(coord[0]) && isdigit(coord[1])) return TRUE;
    else return FALSE;
}


/* shortcut for creating move struct */
struct move create_move(int x1, int y1, int x2, int y2)
{
    struct position start = { x1, y1 };
    struct position end = { x2, y2 };
    struct move move = { start, end };

    return move;
}

void print_move_validity_string(enum move_validity move_validity)
{
    switch (move_validity)
    {
    case VALID:
            printf("Move valid");
        break;
    case MALFORMED_INPUT:
        printf("Malformed input");
        break;
    case INVALID_START_POSITION:
        printf("Invalid start position");
        break;
    case INVALID_END_POSITION:
        printf("Invalid end position");
        break;
    case START_NOT_PEG:
        printf("Start position must be a peg");
        break;
    case END_NOT_HOLE:
        printf("End position must be a hole");
        break;
    case NOT_SAME_ROW_COLUMN:
        printf("Positions must lie on the same row/column and be separated by one cell");
        break;
    case NO_PEG_TO_JUMP:
        printf("No peg between the two positions");
        break;
    }
}
