# Makefile
CC = gcc
# -ggdb3 is for debugging with Valgrind. Remove later
CFLAGS = -Wall -pedantic -Wno-deprecated-declarations -ggdb3
LDFLAGS =

SRC = main.c png.c
OBJ = ${SRC:.c=.o}

INSTDIR = /usr/bin
NAME = png2ascii

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME} ${LDFLAGS}

clean:
	rm -f ${NAME} ${OBJ}

install:
	mkdir -p ${INSTDIR}
	cp -f ${NAME} ${INSTDIR}
	chmod 755 ${INSTDIR}/${NAME}

uninstall:
	rm -f ${INSTDIR}/${NAME}

.PHONY: clean install uninstall
