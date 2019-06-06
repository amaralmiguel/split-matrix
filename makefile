# Arquivo Makefile para compilar o programa de divisao de Matriz em outras duas:
# Superior e Inferior
#
# Declaracoes:
OBJS	= divideMatriz.o arquivo.o
SOURCE	= divideMatriz.c arquivo.c
HEADER	= arquivo.h
OUT	= divideMatriz
# Compilador padrao:
CC	 = gcc
# Comandos de compilacao:
FLAGS	 = -g -c -Wall
LFLAGS	 = -lpthread

#Dependencias de compilacao:
all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

divideMatriz.o: divideMatriz.c
	$(CC) $(FLAGS) divideMatriz.c 

arquivo.o: arquivo.c
	$(CC) $(FLAGS) arquivo.c 

#Limpando:
clean:
	rm -f $(OBJS) $(OUT)