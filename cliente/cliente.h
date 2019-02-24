#ifndef __CLIENTE_H
#define __CLIENTE_H

#include <stdio.h>

typedef struct TCliente{
    char cpf[13];
	char nome[50];
	int idade;
	char endereco[50];
	char cidade[50];
	char estado[3];
	int pontos;
}TCliente;

char DATABASECLIENTE[26] = "../databases/cliente.dat";

int numeroRegistros();

void index(TCliente *clientes);

void cadastrarCliente(TCliente novoRegistro);

void atualizarPontuacao(TCliente registroAtualizado);

void listarClientesIdade();

void listarClientesPontos();

void listarCadastro(TCliente cliente);

#endif
