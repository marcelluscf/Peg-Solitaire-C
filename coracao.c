#define BOARD_HEIGHT 7
#define BOARD_WIDTH_G 9

static const enum cell_contents master_board_heart[BOARD_HEIGHT][BOARD_WIDTH_G] = {
{ INVALID, PEG, PEG, PEG, PEG, PEG, PEG, PEG, INVALID },
{ PEG, PEG, PEG, PEG, PEG, PEG, PEG, PEG, PEG },
{ PEG, PEG, PEG, HOLE, PEG, PEG, PEG, PEG, PEG },
{ INVALID, PEG, PEG, PEG, PEG, PEG, PEG, PEG, INVALID },
{INVALID, INVALID, PEG, PEG, PEG, PEG, PEG, INVALID, INVALID },
{ INALID, INVALID, INVALID, PEG, PEG, PEG, INVALID, INVALID, INVALID},
{ INVALID, INVALID, INVALID, INVALID, PEG, INVALID, INVALID, INVALID, INVALID },
        };