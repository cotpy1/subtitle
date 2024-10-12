SURC = *.cpp *.h
EXEC = run
CC = g++
FLAGS = -std=c++11 -g
all: $(SURC) $(CC) $(FLAGS) -o $(EXEC) $^