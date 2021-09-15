CXX=g++
CXXFLAGS=-std=c++14 -Werror=vla -g -MMD
EXEC=biquadris
OBJECTS=main.o window.o block.o board.o display.o Iblock.o unit.o _1block.o Jblock.o Lblock.o level.o level0.o level1.o level2.o level3.o level4.o Oblock.o Sblock.o Tblock.o Zblock.o game.o
DEPENDS=${OBJECTS:.o=.d}

${EXEC}:${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}  -lX11 -L/usr/X11/lib -I/usr/X11/include

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

.PHONY: clean
