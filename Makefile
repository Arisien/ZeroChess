CC = gcc
CFLAGS = -c -g
LDFLAGS = -g
SRC = ${wildcard src/*.c}
HDR = ${wildcard include/*c}
OBJ = ${SRC:.c=.o}
EXEC = zero

all: ${SRC} ${OBJ} ${EXEC}

${EXEC}: ${OBJ}
	${CC} ${LDFLAGS} $^ -o $@

%.o: %.c ${HDR}
	${CC} ${CFLAGS} $< -o $@

install:
	make
	cp ./zero /usr/local/bin/zero

clean:
	rm src/*.o ${EXEC}