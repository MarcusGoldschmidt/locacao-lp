# Meu primeiro Makefile

all: exemplo

exemplo : main.o conversao.o
	# Linkando e gerando executável
	gcc -o Conversao main.o conversao.o
	
main.o: main.c conversao.h
	gcc -o main.o -c main.c -W -Wall

conversao.o: conversao.o
	gcc -o conversao.o -c conversao.c -W -Wall

clean:
	rm -rf *-o
