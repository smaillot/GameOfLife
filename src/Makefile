CC = gcc
CFLAGS = -Wall -I/usr/include/ -I.
LDFLAGS = -lncurses
DEPS = conway.h
OBJ = main.o init.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

conway: $(OBJ)
	gcc -o $@ $^ $(LDFLAGS) $(CFLAGS)

clean:
	rm -f $(OBJ) conway
