FLAGS=-lSDL2_gfx -lSDL2_ttf -std=c++11 `sdl2-config --libs --cflags` -g
EXENAME=a.out
OBJECTS=gamewindow.o movingobject.o driver.o

%.o:
	g++ $(FLAGS) -c -o $@ $<

$(EXENAME): $(OBJECTS)
	g++ $(OBJECTS) $(FLAGS) -o $(EXENAME)

clean:
	- rm -f $(OBJECTS) $(NAME)

driver.o: driver.cpp gamewindow.hpp point.hpp velocity.hpp
gamewindow.o: gamewindow.cpp gamewindow.hpp keyboardhandler.hpp textobject.hpp point.hpp
movingobject.o: movingobject.cpp movingobject.hpp graphicsobject.hpp
# textbox.o: textbox.cpp textbox.hpp point.hpp