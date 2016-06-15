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
		total_pegs = 32;    	
		for (y = 0; y < BOARD_HEIGHT; y++)
        	for (x = 0; x < BOARD_WIDTH; x++)
            	board[y][x] = master_board[y][x];
		master_title = 1;
		break;
		/* Square board */
	case 2:
		total_pegs = 35;
    	for (y = 0; y < BOARD_HEIGHT; y++)
        	for (x = 0; x < BOARD_WIDTH; x++)
            	board[y][x] = master_board_square[y][x];
		master_title = 2;
		break;
		/* German board */
	case 3:
		total_pegs = 44;
    	for (y = 0; y < BOARD_HEIGHT; y++)
   			for (x = 0; x < BOARD_WIDTH; x++)
           		board[y][x] = master_board_german[y][x];
		master_title = 3;		
		break;
		/* European board */
	case 4:
		total_pegs = 36;
    	for (y = 0; y < BOARD_HEIGHT; y++)
        	for (x = 0; x < BOARD_WIDTH; x++)
            	board[y][x] = master_board_european[y][x];
		master_title = 4;
		break;	
		/* Diamond board */
	case 5:
		total_pegs = 39;
    	for (y = 0; y < BOARD_HEIGHT; y++)
        	for (x = 0; x < BOARD_WIDTH; x++)
        		board[y][x] = master_board_diamond[y][x];
		master_title = 5;
		break;
		/* Especial board */
	case 6:
		total_pegs = 40;
		/* RE-Set the special master line color */
		strcpy(master_color, COLOR_VALENTINES);
		/* RE-Set the special master hole color */
		strcpy(master_color_hole, COLOR_HOLE_VALENTINES);
    	for (y = 0; y < BOARD_HEIGHT; y++)
        	for (x = 0; x < BOARD_WIDTH; x++)
        		board[y][x] = master_board_heart[y][x];
		master_title = 6;
		break;
		/* Board NULL */
	case 7:
		*fimjogo = 7;
		break;
	}											
}

void title(void)
{
	switch (master_title)
	{
		case 1:
			title_standart();
			break;
		case 2:
			title_square();
			break;
		case 3:
			title_german();
			break;
		case 4:
			title_european();
			break;
		case 5:
			title_diamond();
			break;
		case 6:
			title_heart();
			break;
	}		
}

void title_standart(void)
{
	printf(" _____   _____   _____   _   _   ____    _____   _____   _____\n");
	printf("|  ___| |_   _| |  _  | | \\ | | |  _ \\  |  _  | |     | |_   _|\n");
	printf("|___  |   | |   | |_| | |  \\| | | | \\ \\ | |_| | |    _|   | |\n");
	printf(" ___| |   | |   |  _  | | |\\  | | |_/ / |  _  | | |\\ \\    | |\n");
	printf("|_____|   |_|   |_| |_| |_| \\_| |____/  |_| |_| |_| \\_\\   |_|\n\n");

}

void title_square(void)
{
	printf(" _____   _____   _   _   _____   _____   _____\n");
	printf("|  ___| |  _  | | | | | |  _  | |     | |  ___|\n");
	printf("|___  | | | | | | | | | | |_| | |    _| | |_\n");
	printf(" ___| | | |_| | | |_| | |  _  | | |\\ \\  |   |_\n");
	printf("|_____| |____ | |_____| |_| |_| |_| \\_\\ |_____|\n");
	printf("             \\|\n\n");
}

void title_german(void)
{
	printf(" _____   _____   _____   _    _   _____   _   _\n");
	printf("|  ___| |  ___| |     | | \\  / | |  _  | | \\ | |\n");
	printf("| |  _  | |_    |    _| |  \\/  | | |_| | |  \\| |\n");
	printf("| |_| | |   |_  | |\\ \\  | |\\/| | |  _  | | |\\  |\n");
	printf("|_____| |_____| |_| \\_\\ |_|  |_| |_| |_| |_| \\_|\n\n");
}

void title_european(void)
{
	printf(" _____   _   _   _____   _____   _____   _____   _____   _   _\n");
	printf("|  ___| | | | | |     | |  _  | |     | |  ___| |  _  | | \\ | |\n");
	printf("| |_    | | | | |    _| | | | | |  ___| | |_    | |_| | |  \\| |\n");
	printf("|   |_  | |_| | | |\\ \\  | |_| | | |     |   |_  |  _  | | |\\  |\n");
	printf("|_____| |_____| |_| \\_\\ |_____| |_|     |_____| |_| |_| |_| \\_|\n\n");
}

void title_diamond(void)
{
	printf(" ____    _   _____   _    _   _____   _   _   ____\n");
	printf("|  _ \\  |_| |  _  | | \\  / | |  _  | | \\ | | |  _ \\ \n");
	printf("| | \\ \\  _  | |_| | |  \\/  | | | | | |  \\| | | | \\ \\ \n");
	printf("| |_/ / | | |  _  | | |\\/| | | |_| | | |\\  | | |_/ /\n");
	printf("|____/  |_| |_| |_| |_|  |_| |_____| |_| \\_| |____/\n\n");
}
void title_heart(void)
{
	printf("__    __  _____   _       _____   _   _   _____   _   _   _   _____   _   _____\n");
	printf("\\ \\  / / |  _  | | |     |  ___| | \\ | | |_   _| |_| | \\ | | |  ___| | | |  ___|\n");
	printf(" \\ \\/ /	 | |_| | | |     | |_    |  \\| |   | |    _  |  \\| | | |_    |/  |___  |\n");
	printf("  \\  /	 |  _  | | |___  |   |_  | |\\  |   | |   | | | |\\  | |   |_       ___| |\n");
	printf("   \\/    |_| |_| |_____| |_____| |_| \\_|   |_|   |_| |_| \\_| |_____|     |_____|\n\n");
}

/* display the game board to the screen */
void display_board(enum cell_contents board[][BOARD_WIDTH])			//header in line 39 from board.h		
{

    int y, count;

    printf("\n\n\n");
	
	title();
	
	printf ("\n");
	
	count = display_scoreboard(board);
	
	display_movements (count);

    for (y = 0; y < BOARD_HEIGHT; y++)
    {
        display_line_row(y, board);						//header in line 42 from board.h, body in line 30 from board.c
        display_peg_row(y, board);						//header line 44 board.h, body 58 body.c
    }
    display_line_row(BOARD_HEIGHT, board);					//header in line 42 from board.h , body in line 30 from board.c
    display_horizontal_coords();					//header line 44 board.h, body line 85 board.c
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
    printf("   "); 
	/* vertical coords space */
    for (i = 0; i < BOARD_WIDTH; i++)
        printf("  %c ", number_to_letter(i));

    printf("\n");
}

int display_scoreboard (enum cell_contents board[][BOARD_WIDTH]) {

	int peg = get_peg_count(board);
	printf ("%s", "+--------------+\n");	
	printf ("%s", "|");
	printf (COLOR_VALENTINES);
	if (peg < 10)
		printf ("%s : %i", "PEGS LEFT" ,peg);
	else
		printf ("%s : %i", "PEGS LEFT" ,peg);
	printf (COLOR_RESET);
	printf ("|");
	printf ("\n%s", "+--------------+\n");

	return peg;
}

void display_movements (int y) {

	int peg = total_pegs - y;
	printf ("%s", "+---------------+\n");	
	printf ("%s", "|");
	printf (COLOR_VALENTINES);
	//to fix the layout problem	
	if (peg < 10)
		printf ("%s :  %i", "MOVES DONE" ,peg);
	else
		printf ("%s : %i", "MOVES DONE" ,peg);
	printf (COLOR_RESET);
	printf ("|");
	printf ("\n%s", "+---------------+\n");

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


