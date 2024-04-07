
MKDIR=mkdir
OBJDIR=objs

DIR_INC = ./include
DIR_SRC = ./src
DIR_OBJ = ./obj
DIR_BIN = ./bin

SRC = $(wildcard ${DIR_SRC}/*.cpp)
$(info src =  $(SRC))
OBJ = $(patsubst %.cpp, ${DIR_OBJ}/%.o, $(notdir ${SRC}))
$(info obj =  $(OBJ))
TARGET = main
$(info target =  $(TARGET))
CC = g++
CFLAGS = -g  -I${DIR_INC} -I/usr/include
BIN_TARGET = ${DIR_BIN}/${TARGET}
$(info bin_target =  $(BIN_TARGET))

$(info DIR_SRC =  $(DIR_SRC))
${BIN_TARGET}:${OBJ} 
	$(CC) $(OBJ)  -o $@ -L//usr/lib/x86_64-linux-gnu -lPocoFoundation

${DIR_OBJ}/%.o:${DIR_SRC}/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# test:main.o add.o sub.o
# 	g++ main.o add.o sub.o -o test



# add.o:add.cpp 
# 	g++ -c add.cpp -o add.o -I include/add.h
# sub.o:sub.cpp include/sub.h
# 	g++ -c sub.cpp -o sub.o 

clean:
	rm -f obj/*.o bin/* 

	