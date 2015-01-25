# Makefile used in order to build tests
LDFLAGS = -L/usr/local/opt/ncurses/lib
CPPFLAGS = -I/usr/local/opt/ncurses/include
LINKER =  -lncurses
SOURCE = test_keypresses.cc
EXEC = Test

all:
	g++ -std=c++11 $(SOURCE) $(LDFLAGS) $(CPPFLAGS) $(LINKER) -o $(EXEC)

run: all
	./$(EXEC)

clean:
	rm $(EXEC)
