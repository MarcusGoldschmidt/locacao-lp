#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cliente.h"

// Função auxiliar
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

// Recebe um ponteiro já alocado
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

void atualizarPontuacao(char cpf[13]){
	FILE *databaseCliente;
	FILE *databaseLocacao;
	
	TCliente cliente;
	TLocacao locacao;
	
	int auxPosicao = 0;
	int auxLogico = 0;
	
	databaseCliente = fopen(DATABASECLIENTE,"rb+");
	databaseLocacao = fopen(DATABASELOCACAO,"rb+");
	
	// Achando cliente
	while((fread(&cliente,sizeof(TCliente), 1, databaseCliente) != 0) && (auxLogico == 0)){
		auxPosicao++;
		if(strcmp(cliente.cpf, cpf) == 1){
			auxLogico = 1;
		}
	}
	
	// Atualizando pontuação
	while(fread(&locacao,sizeof(TLocacao), 1, databaseLocacao) != 0){
		if(locacao.carro_id == atoi(cliente.cpf)){
			cliente.pontos += (int) locacao.valorTotal;
		}
	}
	printf("%d PONTOS\n", cliente.pontos);
	
	// Salvando dados no arquivo
	fseek(databaseCliente, auxPosicao - 1, SEEK_SET);
	fwrite(&cliente, sizeof(TCliente),1,databaseCliente);
	
	fclose(databaseCliente);
	fclose(databaseLocacao);
}

void localizarLocacao(){
	FILE *databaseCliente;
	FILE *databaseLocacao;
	FILE *databaseCarro;
	
	TCliente cliente;
	TCarro carro;
	TLocacao locacao;
	
	int auxInt;
	int auxLogico = 0;
	
	char auxChar[50];
	
	databaseCliente = fopen(DATABASECLIENTE, "rb+");
	databaseLocacao = fopen(DATABASELOCACAO, "rb+");
	databaseCarro = fopen(DATABASECARRO, "rb+");	
		
	printf("[1] CPF | [2] NOME\n");
	scanf(" %d", &auxInt);
	printf("PESQUISAR: ");
	scanf(" %s", auxChar);
	
	// Procurando cliente
	if(auxInt == 1){	
		while((fread(&cliente,sizeof(TCliente),1, databaseCliente) != 0) && (auxLogico == 0)){
			if(strcmp(cliente.cpf, auxChar) == 0){
				auxLogico = 1;
			}
		}
	}else{
		while((fread(&cliente,sizeof(TCliente),1, databaseCliente) != 0) && (auxLogico == 0)){
			if(strcmp(cliente.nome, auxChar) == 0){
				auxLogico = 1;
			}
		}
	}
	
	// Procurando locações
	printf("|PLACA | INICIO | ENTREGA | VALOR |\n");
	while(fread(&locacao, sizeof(TLocacao),1,databaseLocacao) != 0){
		if(locacao.cpf == atoi(cliente.cpf)){	
			// Procurando carro
			while(fread(&carro, sizeof(TCarro), 1, databaseCarro) != 0){
				if(carro.id == locacao.carro_id){
					printf(" %s |",carro.placa);
					printf(" %d/%d/%d |",locacao.inicioLocacao.dia,locacao.inicioLocacao.mes,locacao.inicioLocacao.ano);
					printf(" %d/%d/%d |",locacao.devolucaoLocacao.dia,locacao.devolucaoLocacao.mes,locacao.devolucaoLocacao.ano);
					printf(" %f |", locacao.valorTotal);
					printf("\n");
				}
			}
		}
	}
}
