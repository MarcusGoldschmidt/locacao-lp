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
	databaseVenda = fopen(DATABASEVENDA, "wb+");
	
	printf("\n\n          # # # PLACA <|> MODELO <|> ANO FABRICAÇÃO\n");
	while(fread(&bufferCarro, sizeof(TCarro), 1, databaseCarro) != 0){
		if((2019 - bufferCarro.anoFabricacao) > 3){
			fwrite(&bufferCarro, sizeof(TCarro), 1, databaseVenda);
			printf("\n              %s <|>", bufferCarro.placa);
			printf("              %s <|>", bufferCarro.modelo);
			printf("              %d ", bufferCarro.anoFabricacao);
			printf("\n");
		}
	}
	fclose(databaseCarro);
	fclose(databaseVenda);
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

void cadastroCarroInput(){
	TCarro aux;		
    aux.disponivel = 0;
     aux.arCondicionado = 0;
	printf("\n\t# # CARROS\n");
	printf("\t# # # Cadastrar Novo Carro\n");
	printf("\t      Modelo: ");
	scanf("%s", aux.modelo);
	printf("\t      Cor: ");
	scanf("%s", aux.cor);
	printf("\t      Motor: ");
	scanf("%f", &aux.motor);
	printf("\t      Ano de Fabricacao: ");
	scanf("%d", &aux.anoFabricacao);
	printf("\t      Placa: ");
	scanf("%s", aux.placa);		

	while ((aux.arCondicionado != 1)&&(aux.arCondicionado != 2)){	
	printf("\t      Ar Condicionado [(1)Sim/(2)Não]: ");
	scanf("%d", &aux.arCondicionado);}
           
	printf("\t      Quilometragem Inicial: ");
	scanf("%d", &aux.quilometragem);
	printf("\t      Valor da Diária: ");
	scanf("%f", &aux.valorDiaria);

    while ((aux.disponivel != 1)&&(aux.disponivel != 2)){				
	printf("\t      Disponibilidade [(1)Sim/(2)Não]: ");
	scanf("%d", &aux.disponivel);

	cadastrarCarro(aux);
	}
}