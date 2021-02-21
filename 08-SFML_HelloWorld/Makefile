CXX		:= g++
CCFLAGS	:=
LDFLAGS := 
LIBS	:= -lsfml-graphics -lsfml-window -lsfml-system
TARGET  :=	trial.out
RM 		:= rm -rf


all: ${TARGET}

${TARGET}: 
	${CXX} trial.cpp -o ${TARGET} ${LIBS}

clean:
	${RM} *.o ${TARGET}

