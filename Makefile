CFLAGS = -Wall -g

all: tic-tac-toe

tic-tac-toe:
	$(CC) $(CFLAGS) main.c game_logic.c ai.c -o tic-tac-toe

clean:
	rm -f tic-tac-toe

.PHONY: all clean

