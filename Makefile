# Meu primeiro Makefile

TELALOCACAOO=./tela/locacao/telalocacao.o
TELACLIENTEO=./tela/cliente/telacliente.o
TELACARROO=./tela/carro/telacarro.o

TELALOCACAOH=./tela/locacao/telalocacao.h
TELACLIENTEH=./tela/cliente/telacliente.h
TELACARROH=./tela/carro/telacarro.h

LOCACAOH=./locacao/locacao.h
CLIENTEH=./cliente/cliente.h
CARROH=./carro/carro.h

LOCACAOO=./locacao/locacao.o
CLIENTEO=./cliente/cliente.o
CARROO=./carro/carro.o

all: index

index : main.o telalocacao.o telacarro.o telacliente.o
	# Index
	gcc -o index main.o telalocacao.o telacarro.o telacliente.o
	
main.o: main.c $(TELALOCACAOH) $(TELACLIENTEH) $(TELACARROH)
	# Linkando e gerando executável
	gcc -o main.o -c main.c -W -Wall

# Telas
telalocacao.o: $(TELALOCACAOO) locacao.o $(TELALOCACAOH)
	gcc -o $(TELALOCACAOO) -c ./tela/locacao/telalocacao.c -W -Wall
	
telacliente.o: $(TELACLIENTEO) cliente.o $(CLIENTEH)
	gcc -o $(TELACLIENTEO) -c ./tela/cliente/telacliente.c -W -Wall
	
telacarro.o: $(TELACARROO) carro.o $(CARROH)
	gcc -o $(TELACARROO) -c ./tela/carro/telacarro.c -W -Wall

# Tipos basicos
locacao.o: $(LOCACAOO) $(CARROH)
	gcc -o $(LOCACAOO) -c ./locacao/locacao.c -W -Wall
	
carro.o: $(CARROO)
	gcc -o $(CARROO) -c ./carro/carro.c -W -Wall
	
cliente.o: $(CLIENTEO) $(LOCACAOH) $(CARROH)
	gcc -o $(CLIENTEO) -c ./cliente/cliente.c -W -Wall

clean:
	rm -rf *-o
