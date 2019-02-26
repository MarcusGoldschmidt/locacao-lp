#ifndef __CLIENTE_H
#define __CLIENTE_H

#include <stdio.h>
#include <string.h>

typedef struct TCarro{
	int id;
	char modelo[10];
	char cor[6];
	float motor;
	int anoFabricacao;
	int arCondicionado;
	int quilometragem;
	float valorDiaria;
	int disponivel;
}TCarro;

char DATABASECARRO[26] = "../databases/carro.dat";

int numeroRegistrosCarros();

void indexCarro(TCarro *carros);

void cadastrarCarro(TCarro novoCarro);

void atualizarCarro(TCarro);

void localizarCarroPorModelo(char modelo[10]);

void listarCadastroCarro(TCarro carro);

#endif
