#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "carro.h"

int numeroRegistrosCarros(){
	FILE *read;
	int numeroDeRegistros = 0;
	TCarro buffer;
	
	read = fopen(DATABASECARRO, "rb");
	
	while(fread(&buffer, sizeof(TCarro), 1, read) != 0){
		numeroDeRegistros++;
	}
	fclose(read);
	
	return numeroDeRegistros;
}

void indexCarro(TCarro *carros){
	FILE *read;
	int contadorDeRegistrosIniciais;
	
	contadorDeRegistrosIniciais = numeroRegistrosCarros();
	
	read = fopen(DATABASECARRO, "rb");
	
	carros = (TCarro *) realloc(carros, sizeof(TCarro) * contadorDeRegistrosIniciais);
	
	fread(carros, sizeof(TCarro), contadorDeRegistrosIniciais, read);
	
	fclose(read);
}

void localizarCarroPorModelo(char modelo[10]){
	FILE *read;

	TCarro carro;
    read = fopen(DATABASECARRO, "rb");		
	
	while(fread(&carro, sizeof(TCarro), 1, read) != 0){
        if(strcmp(modelo, carro.modelo) == 0){
            listarCadastroCarro(carro);
        }
    }
}

void listarCadastroCarro(TCarro carro){
	printf("       ID: %d\n", carro.id);
	printf("       MODELO: %s\n", carro.modelo);
	printf("       COR: %s\n",carro.cor);
	printf("       ANO DE FABRICACAO: %d\n", carro.anoFabricacao);
	printf("       QUILOMETRAGEM: %d\n", carro.quilometragem);
	printf("       VALOR DIARIA R$ %.2f\n", carro.valorDiaria);
	if(carro.disponivel == 1){
		printf("       DISPONIVEL\n");
	}else {
		printf("       INDISPONIVEL\n");
	}
}

void cadastrarCarro(TCarro novoCarro){
	FILE *database;
	
	novoCarro.id = numeroRegistrosCarros() + 1;
	
	database = fopen(DATABASECARRO, "ab");
	
	fwrite(&novoCarro, sizeof(TCarro), 1, database);
	fclose(database);
}

void atualizarCarro(TCarro carro){
	FILE *database;
	TCarro buffer;
	int aux = 0;
	int auxLogico = 0;
	
	database = fopen(DATABASECARRO, "rb+");
	
	while((fread(&buffer,sizeof(TCarro), 1,database) != 0) && (auxLogico == 0)){
		aux++;
		if(buffer.id == carro.id){
			auxLogico = 1;
		}
	}
	
	fseek(database, sizeof(TCarro) * (aux - 1), SEEK_SET);
	fwrite(&carro, sizeof(TCarro), 1, database);
	fclose(database);
}

void disponibilizarCarrosVenda(){
	FILE *databaseCarro;
	FILE *databaseVenda;
	TCarro bufferCarro;
	
	databaseCarro = fopen(DATABASECARRO, "rb");
	databaseVenda = fopen(DATABASECARRO, "ab");
	
	printf("\n\n         # # # PLACA | MODELO | ANO FABRICAÇÃO\n");
	while(fread(&bufferCarro, sizeof(TCarro), 1, databaseCarro) != 0){
		if((2019 - bufferCarro.anoFabricacao) > 3){
			fwrite(&bufferCarro, sizeof(TCarro), 1, databaseVenda);
			printf("              %s |", bufferCarro.placa);
			printf("              %s |", bufferCarro.modelo);
			printf("              %d ", bufferCarro.anoFabricacao);
			printf("\n");
		}
	}
}

int quantidadeCarrosEmprestados(){
	FILE *database;
	TCarro bufferCarro;
	int aux = 0;
	
	database = fopen(DATABASECARRO, "rb");
	
	while(fread(&bufferCarro, sizeof(TCarro), 1, database) != 0){
		if(bufferCarro.disponivel == 0){
			aux++;
		}
	}
	
	return aux;
}
