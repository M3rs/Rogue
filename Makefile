LDFLAGS = -L/usr/local/opt/ncurses/lib
CPPFLAGS = -I/usr/local/opt/ncurses/include
LINKER =  -lncurses
SOURCE = main.cc GameEngine.cc Point.cc Entity.cc Player.cc State.cc PlayState.cc
EXEC = Rogue

all:
	g++ -std=c++11 $(SOURCE) $(LDFLAGS) $(CPPFLAGS) $(LINKER) -o $(EXEC)

run: all
	./$(EXEC)

clean:
	rm $(EXEC)
