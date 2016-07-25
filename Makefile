CC = gcc
CFLAGS = -Wall -g
OBJ = TallyLog.o main.o

all: main

main: main.o TallyLog.o
	$(CC) $(CFLAGS) -o main main.o TallyLog.o

#TallyLog: $(OBJ)
#	$(CC) $(CFLAGS) -o TallyLog $(OBJ)

main.o: main.c TallyLog.h

TallyLog.o: TallyLog.c TallyLog.h

clean:
	rm -rf main main.o TallyLog.o