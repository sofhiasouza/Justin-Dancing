OBJS = $(wildcard src/*.cpp)
INCLUDES = $(wildcard include/*.h)
CC = g++
CFLAGS=-Wall -std=c++14
OBJ_NAME = game
LINKER_FLAGS = -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lpthread

all : $(OBJS) $(INCLUDES)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(CFLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
	
run:
	./$(OBJ_NAME)	
