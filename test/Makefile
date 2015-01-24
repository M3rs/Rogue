LDFLAGS = -L/usr/local/opt/ncurses/lib
CPPFLAGS = -I/usr/local/opt/ncurses/include
LINKER =  -lncurses
SOURCE = test_windows.cc
EXEC = Test

all:
	g++ -std=c++11 $(SOURCE) $(LDFLAGS) $(CPPFLAGS) $(LINKER) -o $(EXEC)

run: all
	./$(EXEC)

clean:
	rm $(EXEC)
