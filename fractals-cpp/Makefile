# compiler vars
CC = g++
CFLAGS = -Wall -Werror -ansi -pedantic

all: sierpinski original

# ===================================== link object files into a binary
# sfml-graphics ---> depends on sfml-window ---> depends on sfml-system
sierpinski: Sierpinski_fract.o Sierpinski.o 
	$(CC) $(FLAGS) -o sierpinski Sierpinski_fract.o Sierpinski.o -lsfml-graphics -lsfml-window -lsfml-system

original: Original_fract.o Original.o
	$(CC) $(FLAGS) -o original Original_fract.o Original.o -lsfml-graphics -lsfml-window -lsfml-system

# ============================== compile source files into object files
Sierpinski_fract.o: Sierpinski_fract.cpp Sierpinski.cpp Sierpinski.hpp 
	$(CC) $(FLAGS) -c Sierpinski_fract.cpp

Sierpinski.o: Sierpinski.cpp Sierpinski.hpp
	$(CC) $(FLAGS) -c Sierpinski.cpp

Original_fract.o: Original_fract.cpp Original.cpp Original.hpp
	$(CC) $(FLAGS) -c Original_fract.cpp

Original.o: Original.cpp Original.hpp
	$(CC) $(FLAGS) -c Original.cpp

# =================== remove old binary, object *.o and backup *~ files
clean:
	rm -rf sierpinski original *.o *.~

