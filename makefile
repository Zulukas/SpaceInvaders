FLAGS=-lSDL2_gfx -std=c++11 `sdl2-config --libs --cflags` -lcoordinate
# SDL2=`sdl2-config --libs --cf
EXENAME=a.out
OBJECTS=movingobject.o driver.o

%.o:
	g++ $(FLAGS) -c -o $@ $<

$(EXENAME): $(OBJECTS)
	g++ $(OBJECTS) $(FLAGS) -o $(EXENAME)

clean:
	- rm -f $(OBJECTS) $(NAME)

movingobject.o: movingobject.cpp movingobject.hpp graphicsobject.hpp
driver.o: driver.cpp