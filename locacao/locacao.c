#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "locacao.h"
#include "../carro/carro.h"

int numeroRegistrosLocacoes(){
	FILE *database;
	TLocacao buffer;
	int aux = 0;
	
	database = fopen(DATABASELOCACAO, "rb");
	
	while(fread(&buffer, sizeof(TLocacao), 1, database) != 0){
		aux++;
	}
	fclose(database);
	return aux;
}

void iniciarLocacao(int cpf, float motor, int arCondicionado){
	FILE *databaseLocacao;
	FILE *databaseCarro;
	
	TLocacao locacao;
	TCarro carro;
	
	int auxLogico = 0;
	int quantidadeRegistros;
	int posicaoCarroFile = 0;
	
	quantidadeRegistros = numeroRegistrosLocacoes();
	
	carro.id = 0;
	
	databaseCarro = fopen(DATABASELOCACAO, "rb");
	databaseLocacao = fopen(DATABASELOCACAO, "rb+");
	
	// Para quando chegar no final do arquivo, ou no primeiro carro disponível
	while((fread(&carro, sizeof(TCarro),1,databaseCarro) != 0) && (auxLogico != 1)){
		posicaoCarroFile++;
		if(carro.disponivel == 1){
			auxLogico = 1;
		}
	}
	
	if(carro.id != 0){
		printf("=== CARRO ENCONTRADO ===\n");
		printf("MODELO: %s\n",carro.modelo);
		printf("COR: %s\n",carro.cor);
		printf("PRECO DIÁRIA: %f\n",carro.valorDiaria);
		printf("QUILOMETRAGEM: %d\n",carro.quilometragem);
		printf("PLACA: %s\n",carro.placa);
		
		printf("=== DATA INICIO ===\n");
		printf("DIA: ");
		scanf(" %d", &locacao.inicioLocacao.dia);
		printf("MES: ");
		scanf(" %d", &locacao.inicioLocacao.mes);
		printf("ANO: ");
		scanf(" %d", &locacao.inicioLocacao.ano);
		printf("=== DATA DEVOLUCAO ===\n");
		printf("DIA: ");
		scanf(" %d", &locacao.devolucaoLocacao.dia);
		printf("MES: ");
		scanf(" %d", &locacao.devolucaoLocacao.mes);
		printf("ANO: ");
		scanf(" %d", &locacao.devolucaoLocacao.ano);
		
		locacao.id = quantidadeRegistros + 1;
		locacao.carro_id = carro.id;
		locacao.quilometragemInicial = carro.quilometragem;
		locacao.quilometragemFinal = 0;
		locacao.cpf = cpf;
		
		// Atualizando carro
		fseek(databaseCarro, posicaoCarroFile - 1, SEEK_SET);
		carro.disponivel = 0;
		fwrite(&carro,sizeof(TCarro),1,databaseCarro);
		fflush(databaseCarro);
		fflush(databaseLocacao);
	}else{
		printf("Não há carro disponível\n");
	}
	
	fclose(databaseCarro);
	fclose(databaseLocacao);
}
