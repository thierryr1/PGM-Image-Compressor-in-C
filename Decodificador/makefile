CC = gcc
CFLAGS = -Wall -Wextra -O2

TARGET = decoder

SRC = decoderFunctios.c \
      PGMWriterFunctions.c \
      main.c

all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
