CC = gcc
CFLAGS = -std=c2x -Wall -Wextra

SRCS = main.c \
       combat.c \
       init.c \
       destroy.c \
       setGet.c \
       func.c \
       visual.c \
       lifeCycle.c \
       deathScreen.c \
       game.c \
       splashScreen.c \
       fileReader.c \
       fileWriter.c

OBJS = $(SRCS:.c=.o)

.PHONY: all clean

all: Porjet_C

Porjet_C: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) Porjet_C