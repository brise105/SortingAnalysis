BUILD_FLAGS = -W -Wall -pedantic
CC = g++
RM = rm
EXES = *.exe
OBJECTS = *.o

all: Driver.exe

Ch6Ex2.o: Makefile Sorting.cpp
	$(CC) $(BUILD_FLAGS) -c Sorting.cpp -o Sorting.o


Driver.exe: Makefile Sorting.o main.cpp
	$(CC) $(BUILD_FLAGS) Sorting.o main.cpp -o Driver.exe

clean:
	$(RM) $(EXES) $(OBJECTS)
