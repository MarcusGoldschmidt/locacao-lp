#include <stdio.h>
#include <stdlib.h>

#include "cliente.h"

int numeroRegistrosCliente(){
	FILE *read;
	int numeroDeRegistros = 0;
	TCliente buffer;
	
	read = fopen(DATABASECLIENTE, "rb");
	
	while(fread(&buffer, sizeof(TCliente), 1, read) != 0){
		numeroDeRegistros++;
	}
	fclose(read);
	
	return numeroDeRegistros;
}

void indexCliente(TCliente *clientes){
	FILE *read;
	int contadorDeRegistrosIniciais;
	
	contadorDeRegistrosIniciais = numeroRegistrosCliente();
	
	read = fopen(DATABASECLIENTE, "rb");
	clientes = (TCliente *) realloc(clientes, contadorDeRegistrosIniciais);
	fread(clientes, sizeof(TCliente), contadorDeRegistrosIniciais, read);
	
	fclose(read);
}

void cadastrarCliente(TCliente novoRegistro){
	FILE *database;
	database = fopen(DATABASECLIENTE, "ab");
	
	fwrite(&novoRegistro, sizeof(TCliente), 1, database);
	fclose(database);
}

void listarClientesPontos(){
	TCliente *clientes;
	
	clientes = (TCliente *) malloc(sizeof(TCliente));
	
	indexCliente(clientes);
	
	for(int i = 0; i < numeroRegistrosCliente(); i++){
		if(clientes[i].pontos > 200){
			listarCadastroCliente(clientes[i]);
		}
	}
}

void listarClientesIdade(){
	TCliente *clientes;
	
	clientes = (TCliente *) malloc(sizeof(TCliente));
	
	indexCliente(clientes);
	
	for(int i = 0; i < numeroRegistrosCliente(); i++){
		if(clientes[i].idade > 18 && clientes[i].idade < 25){
			listarCadastroCliente(clientes[i]);
		}
	}
	
}

void listarCadastroCliente(TCliente cliente){
	printf("CPF: %s\n", cliente.cpf);
	printf("NOME: %s\n", cliente.nome);
	printf("IDADE: %d\n", cliente.idade);
	printf("ENDERECO: %s\n", cliente.endereco);
	printf("CIDADE: %s\n", cliente.cidade);
	printf("ESTADO: %s\n", cliente.estado);
	printf("PONTOS: %d\n", cliente.pontos);
}
