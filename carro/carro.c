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
	
	carros = (TCarro *) realloc(carros, contadorDeRegistrosIniciais);
	
	fread(carros, sizeof(TCarro), contadorDeRegistrosIniciais, read);
	
	fclose(read);
}

void localizarCarroPorModelo(char modelo[10]){
	int numeroDeCarros;
	
	TCarro *carros;
	carros = (TCarro *) malloc(sizeof(TCarro));
	indexCarro(carros);
	
	numeroDeCarros = numeroRegistrosCarros();
	
	for(int i = 0; i < numeroDeCarros; i++){
		if(strcmp(modelo, carros[i].modelo) == 0){
			listarCadastroCarro(carros[i]);
		}
	}
}

void listarCadastroCarro(TCarro carro){
	printf("ID: %d\n", carro.id);
	printf("MODELO: %s\n", carro.modelo);
	printf("COR: %s\n",carro.cor);
	printf("ANO DE FABRICACAO: %d\n", carro.anoFabricacao);
	printf("QUILOMETRAGEM: %d\n", carro.quilometragem);
	printf("VALOR DIARIA: %f\n", carro.valorDiaria);
	if(carro.disponivel == 1){
		printf("DISPONIVEL\n");
	}else {
		printf("INDISPONIVEL\n");
	}
}

void cadastrarCarro(TCarro novoCarro){
	FILE *database;
	database = fopen(DATABASECARRO, "ab");
	
	fwrite(&novoCarro, sizeof(TCarro), 1, database);
	fclose(database);
}
