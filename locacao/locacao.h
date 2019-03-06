#ifndef __LOCACAO_H
#define __LOCACAO_H

#include <stdio.h>
#include <string.h>
#include "../carro/carro.h"

typedef struct TData{
	int dia;
	int mes;
	int ano;
	int hora;
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

#define DATABASELOCACAO "../databases/locacoes.dat"

int numeroRegistrosLocacoes();

void iniciarLocacao(int cpf, float motor, int arCondicionado);

void finalizarLocacao(int idLocacao,TData data,int quilometragemEntrega);

float calculoValorTotal(TData inicioLocacao, TData finalLocacao, float valorDiaria);

#endif
