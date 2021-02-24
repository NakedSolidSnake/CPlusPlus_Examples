CXX		:= g++
CCFLAGS	:= -g3 -O0
LDFLAGS := 
LIBS	:= -lsfml-graphics -lsfml-window -lsfml-system
TARGET  :=	tetris.out
RM 		:= rm -rf


all: ${TARGET}

${TARGET}: 
	${CXX} ${CCFLAGS} tetris.cpp -o ${TARGET} ${LIBS}

clean:
	${RM} *.o ${TARGET}

