CC = gcc
CFLAGS = -Wall -O2
LDFLAGS = -lm

EXEC = coder.exe
SRCS = main.c compressorFunctions.c PGMReaderFunctions.c

all:
	$(CC) $(CFLAGS) $(SRCS) -o $(EXEC) $(LDFLAGS)

clean:
	rm -f $(EXEC)
