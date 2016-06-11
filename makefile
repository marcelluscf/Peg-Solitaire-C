jogar : board.o game.o solitaire.o utility.o
	cc -o jogar board.o game.o solitaire.o utility.o
board.o : board.c board.h
	cc -c board.c
game.o : game.c game.h
	cc -c game.c
solitaire.o : solitaire.c solitaire.h
	cc -c solitaire.c
utility.o : utility.c utility.h
	cc -c utility.c
clean :
	rm board.o game.o solitaire.o utility.o
