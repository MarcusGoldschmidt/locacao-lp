#ifndef __CARRO_H
#define __CARRO_H

#include <stdio.h>
#include <string.h>

typedef struct TCarro{
	int id;
	char modelo[10];
	char cor[6];
	float motor;
	int anoFabricacao;
	char placa[8];
	int arCondicionado;
	int quilometragem;
	float valorDiaria;
	int disponivel;
}TCarro;

#define DATABASECARRO "../databases/carro.dat"
#define DATABASEVENDA "../databases/venda.dat"

int numeroRegistrosCarros();

void indexCarro(TCarro *carros);

void cadastrarCarro(TCarro novoCarro);

void atualizarCarro(TCarro);

void localizarCarroPorModelo(char modelo[10]);

void listarCadastroCarro(TCarro carro);

void disponibilizarCarrosVenda();

int quantidadeCarrosEmprestados();

#endif
