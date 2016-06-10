#define BOARD_HEIGHT_G 9
#define BOARD_WIDTH_G 9

static const enum cell_contents master_board_diamond[BOARD_HEIGHT_G][BOARD_WIDTH_G] = {
{ INVALID, INVALID, INVALID, INVALID, PEG, INVALID, INVALID, INVALID, INVALID },
{ INVALID, INVALID, INVALID, PEG, PEG, PEG, INVALID, INVALID, INVALID },
{ INVALID, INVALID, PEG, PEG, HOLE, PEG, PEG, INVALID, INVALID },
{ INALID, PEG, PEG, PEG, PEG, PEG, PEG, PEG, INVALID },
{ PEG, PEG, PEG, PEG, HOLE, PEG, PEG, PEG, PEG },
{ INALID, PEG, PEG, PEG, PEG, PEG, PEG, PEG, INVALID },
{ INVALID, INVALID, PEG, PEG, PEG, PEG, PEG, INVALID, INVALID },
{ INVALID, INVALID, INVALID, PEG, PEG, PEG, INVALID, INVALID, INVALID },
{ INVALID, INVALID, INVALID, INVALID, PEG, INVALID, INVALID, INVALID, INVALID }
        };
