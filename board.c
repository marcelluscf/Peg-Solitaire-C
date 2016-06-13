#include <stdio.h>
#include <string.h>
#include "board.h"

/* copies the master board to a local copy for each game */
void init_board(enum cell_contents board[][BOARD_WIDTH], int* fimjogo)			//header in line 35 from board.h 
{
	
    int x, y, z;
	z = selection_board();

	/* set the master line colors */
	strcpy(master_color, COLOR_LINES);
	/* Set the master hole color */	
	strcpy(master_color_hole, COLOR_HOLE);
	/* switch that select the displeyd board */
	switch (z)
	{
		/* Master board */
	case 1:
    	for (y = 0; y < BOARD_HEIGHT; y++)
        	for (x = 0; x < BOARD_WIDTH; x++)
            	board[y][x] = master_board[y][x];
		break;
		/* Square board */
	case 2:
    	for (y = 0; y < BOARD_HEIGHT; y++)
        	for (x = 0; x < BOARD_WIDTH; x++)
            	board[y][x] = master_board_square[y][x];
		break;
		/* German board */
	case 3:
    	for (y = 0; y < BOARD_HEIGHT; y++)
   			for (x = 0; x < BOARD_WIDTH; x++)
           		board[y][x] = master_board_german[y][x];
		break;
		/* European board */
	case 4:
    	for (y = 0; y < BOARD_HEIGHT; y++)
        	for (x = 0; x < BOARD_WIDTH; x++)
            	board[y][x] = master_board_european[y][x];
		break;	
		/* Diamond board */
	case 5:
    	for (y = 0; y < BOARD_HEIGHT; y++)
        	for (x = 0; x < BOARD_WIDTH; x++)
        		board[y][x] = master_board_diamond[y][x];
		break;
		/* Especial board */
	case 6:
		/* RE-Set the special master line color */
		strcpy(master_color, COLOR_VALENTINES);
		/* RE-Set the special master hole color */
		strcpy(master_color_hole, COLOR_HOLE_VALENTINES);
    	for (y = 0; y < BOARD_HEIGHT; y++)
        	for (x = 0; x < BOARD_WIDTH; x++)
        		board[y][x] = master_board_heart[y][x];
		break;
		/* Board NULL */
	case 7:
		*fimjogo = 7;
		break;
	}											
}


/* display the game board to the screen */
void display_board(enum cell_contents board[][BOARD_WIDTH])			//header in line 39 from board.h		
{
    int y;

    printf("\n\n\n");
    for (y = 0; y < BOARD_HEIGHT; y++)
    {
        display_line_row(y, board);						//header in line 42 from board.h, body in line 30 from board.c
        display_peg_row(y, board);						//header line 44 board.h, body 58 body.c
    }
    display_line_row(BOARD_HEIGHT, board);					//header in line 42 from board.h , body in line 30 from board.c
    display_horizontal_coords();						//header line 44 board.h, body line 85 board.c
}


void display_line_row(int y, enum cell_contents board[][BOARD_WIDTH])		//header in line 42 from board.h
{
    BOOLEAN line_started = FALSE;
    int x;

    printf("   ");
	printf("%s", master_color);

    /* purposely go past array bounds to print final "+" */
    for (x = 0; x <= BOARD_WIDTH; x++)
    {
        if (is_valid(x, y, board) || is_valid(x, y - 1, board))
        {
            printf("+---");
            line_started = TRUE;
        }
        else
        {
            /* print "+" when transitioning from line to invalid */
            printf(line_started ? "+" : " ");
            printf("   ");
            line_started = FALSE;
        }
    }
    printf(COLOR_RESET);

    printf("\n");
}

void display_peg_row(int y, enum cell_contents board[][BOARD_WIDTH])			//header 44 board.h
{
    int x;

    printf(" %d ", y + 1);
    /* purposely go past array bounds to print final "|" */
    for (x = 0; x <= BOARD_WIDTH; x++)
    {
        /* print border if adjacent cell is valid */
     
    	printf("%s", master_color);
		

        printf(is_valid(x, y, board) || is_valid(x - 1, y, board) ? "|" : " ");
        printf(COLOR_RESET);

        if (is_valid(x, y, board))
        {
            if (is_peg(x, y, board))
                printf("%s o %s", COLOR_PEG, COLOR_RESET);
            else if (is_hole(x, y, board))
                printf("%s . %s", master_color_hole, COLOR_RESET);
        }
        else
            printf("   ");
    }

    printf("\n");
}

void display_horizontal_coords(void)								//header line 44 board.h
{
    int i;

    printf("\n");
    printf("   "); /* vertical coords space */
    for (i = 0; i < BOARD_WIDTH; i++)
        printf("  %c ", number_to_letter(i));

    printf("\n");
}


BOOLEAN is_valid(int x, int y, enum cell_contents board[][BOARD_WIDTH])
{
    if (x >= 0 && x < BOARD_WIDTH && y >= 0 && y < BOARD_HEIGHT && board[y][x] != INVALID)
        return TRUE;
    else
        return FALSE;
}

BOOLEAN is_peg(int x, int y, enum cell_contents board[][BOARD_WIDTH])
{
    if (board[y][x] == PEG) return TRUE;
    else return FALSE;
}

BOOLEAN is_hole(int x, int y, enum cell_contents board[][BOARD_WIDTH])
{
    if (board[y][x] == HOLE) return TRUE;
    else return FALSE;
}


int get_peg_count(enum cell_contents board[][BOARD_WIDTH])			//header line 56
{
    int count = 0;
    int x, y;
    for (y = 0; y < BOARD_HEIGHT; y++)
        for (x = 0; x < BOARD_WIDTH; x++)
            if (board[y][x] == PEG) count++;
    return count;
}
