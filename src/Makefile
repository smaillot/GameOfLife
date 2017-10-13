CC = gcc
CFLAGS = -Wall -I/usr/include/ -I.
LDFLAGS = -lncurses
DEPS = conway.h
OBJ = main.o rules.o display.o drawing.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

conway: $(OBJ)
	gcc -o $@ $^ $(LDFLAGS) $(CFLAGS)

clean:
	rm -f $(OBJ) conway
