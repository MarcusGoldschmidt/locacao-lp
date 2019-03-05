#ifndef __CLIENTE_H
#define __CLIENTE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../locacao/locacao.h"
#include "../carro/carro.h"

typedef struct TCliente{
    char cpf[13];
	char nome[50];
	int idade;
	char endereco[50];
	char cidade[50];
	char estado[3];
	int pontos;
}TCliente;

#define DATABASECLIENTE "../databases/cliente.dat"

int numeroRegistrosCliente();

void indexCliente(TCliente *clientes);

void cadastrarCliente(TCliente novoRegistro);

void atualizarPontuacao(char cpf[13]);

void listarClientesIdade();

void listarClientesPontos();

void listarCadastroCliente(TCliente cliente);

void localizarLocacao();

#endif
