FLAGS=-lSDL2_gfx -lSDL2_ttf -std=c++11 `sdl2-config --libs --cflags` -g
EXENAME=a.out
OBJECTS=driver.o gamewindow.o textobject.o lineobject.o bullet.o movingobject.o
HPPFILES=graphicsobject.hpp movingobject.hpp textobject.hpp gamewindow.hpp keyboardhandler.hpp point.hpp velocity.hpp lineobject.hpp bullet.hpp
%.o:
	g++ $(FLAGS) -c -o $@ $<

$(EXENAME): $(OBJECTS)
	g++ $(OBJECTS) $(FLAGS) -o $(EXENAME)

clean:
	- rm -f $(OBJECTS) $(NAME)

#Make a more elegant compilation system rather than include all .hpp's in unnecessary object files...
driver.o: driver.cpp $(HPPFILES)
gamewindow.o: gamewindow.cpp $(HPPFILES)
movingobject.o: movingobject.cpp $(HPPFILES)
textobject.o: textobject.cpp $(HPPFILES)
lineobject.o: lineobject.cpp $(HPPFILES)	
bullet.o: bullet.cpp $(HPPFILES)