#ifndef __LOCACAO_H
#define __LOCACAO_H

#include <stdio.h>
#include <string.h>
#include "../carro/carro.h"

typedef struct TData{
	int dia;
	int mes;
	int ano;
}TData;

typedef struct TLocacao{
	int id;
	int carro_id;
	int cpf;
	TData inicioLocacao;
	TData devolucaoLocacao;
	int quilometragemInicial;
	int quilometragemFinal;
	float valorTotal;
}TLocacao;

char DATABASELOCACAO[26] = "../databases/locacao.dat";

int numeroRegistrosLocacoes();

void iniciarLocacao(int cpf, float motor, int arCondicionado);

#endif
