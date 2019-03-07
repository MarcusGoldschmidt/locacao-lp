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
	
	databaseCarro = fopen(DATABASECARRO, "rb");
	databaseLocacao = fopen(DATABASELOCACAO, "rb+");
	
	// Para quando chegar no final do arquivo, ou no primeiro carro disponível que atenda a condição do arCondicionado
	while((fread(&carro, sizeof(TCarro),1,databaseCarro) != 0) && (auxLogico != 1)){
		posicaoCarroFile++;
		if((carro.disponivel == 1) && (carro.arCondicionado == arCondicionado) && ( carro.motor == motor)){
			auxLogico = 1;
		}
	}
	
	if(carro.id != 0){
		printf("\n\t   <> CARRO ENCONTRADO <>\n");
		printf("\t      MODELO: %s\n",carro.modelo);
		printf("\t      COR: %s\n",carro.cor);
		printf("\t      PRECO DIÁRIA: %f\n",carro.valorDiaria);
		printf("\t      QUILOMETRAGEM: %d\n",carro.quilometragem);
		printf("\t      PLACA: %s\n",carro.placa);
		
		printf("\t   <> DATA INICIO <>\n");
		printf("\t      DIA: ");
		scanf(" %d", &locacao.inicioLocacao.dia);
		printf("\t      MES: ");
		scanf(" %d", &locacao.inicioLocacao.mes);
		printf("\t      ANO: ");
		scanf(" %d", &locacao.inicioLocacao.ano);
		printf("\t      HORA: ");
		scanf(" %d", &locacao.inicioLocacao.hora);
		
		locacao.devolucaoLocacao.dia = 0;
		locacao.devolucaoLocacao.mes = 0;
		locacao.devolucaoLocacao.ano = 0;
		locacao.devolucaoLocacao.hora = 0;
		
		locacao.id = quantidadeRegistros + 1;
		locacao.carro_id = carro.id;
		locacao.quilometragemInicial = carro.quilometragem;
		locacao.quilometragemFinal = 0;
		locacao.cpf = cpf;
		
		// Atualizando carro
		fseek(databaseCarro,sizeof(TCarro) * (posicaoCarroFile - 1), SEEK_SET);
		carro.disponivel = 0;
		fwrite(&carro,sizeof(TCarro),1,databaseCarro);
		fflush(databaseCarro);
		fflush(databaseLocacao);
	}else{
		printf("\t      NAO HÁ CARROS DISPONIVEIS!\n");
	}
	
	fclose(databaseCarro);
	fclose(databaseLocacao);
}

void finalizarLocacao(int idLocacao,TData data,int quilometragemEntrega){
	FILE *databaseLocacao;
	FILE *databaseCarro;
	
	TLocacao locacao;
	TCarro carro;

	int posicaoLocacao = 0;
	int posicaoCarro = 0;
	int auxLogico = 0;
	
	// Encontrando locacao
	databaseLocacao = fopen(DATABASELOCACAO, "rb+");
	while(fread(&locacao, sizeof(TLocacao),1,databaseLocacao) && (auxLogico == 0)){
		posicaoLocacao++;
		if(locacao.id == idLocacao){
			auxLogico = 1;
		}
	}
	
	locacao.devolucaoLocacao.dia = data.dia;
	locacao.devolucaoLocacao.mes = data.mes;
	locacao.devolucaoLocacao.ano = data.ano;
	locacao.devolucaoLocacao.hora = data.hora;
	
	// Encontrando carro
	databaseCarro = fopen(DATABASECARRO, "rb+");
	auxLogico = 0;
	while(fread(&carro, sizeof(TCarro),1,databaseCarro) && (auxLogico == 0)){
		posicaoCarro++;
		if(carro.id == locacao.carro_id){
			auxLogico = 1;
		}
	}
	
	// Atualizando locacao
	locacao.quilometragemFinal = quilometragemEntrega;
	locacao.valorTotal = calculoValorTotal(locacao.inicioLocacao, locacao.devolucaoLocacao, carro.valorDiaria);
	printf("\n\t   <> VALOR TOTAL R$ %.2f\n", locacao.valorTotal);
	
	fseek(databaseLocacao, sizeof(TLocacao) * (posicaoLocacao - 1), SEEK_SET);
	fwrite(&locacao, sizeof(TLocacao), 1, databaseLocacao);
	
	// deixando carro disponivel
	carro.quilometragem = quilometragemEntrega;
	carro.disponivel = 1;
	
	fseek(databaseCarro,sizeof(TCarro) * (posicaoCarro - 1), SEEK_SET);
	fwrite(&carro, sizeof(TCarro), 1, databaseCarro);
	
	fclose(databaseCarro);
	fclose(databaseLocacao);
}

float calculoValorTotal(TData inicioLocacao, TData finalLocacao, float valor){
	float valorTotal = 0;
	int quantidadeDias = 0;
	
	// Em um mundo perfeito
	quantidadeDias = (finalLocacao.dia - inicioLocacao.dia);
	quantidadeDias += (finalLocacao.mes - inicioLocacao.mes) * 30;
	quantidadeDias += (finalLocacao.ano - inicioLocacao.ano) * 365;
	
	if(quantidadeDias == 0){
		return valor;
	}
	
	valorTotal = valor * quantidadeDias;
	valorTotal += ((finalLocacao.hora - inicioLocacao.hora) / 24) * valor;
	
	return valorTotal;
}
