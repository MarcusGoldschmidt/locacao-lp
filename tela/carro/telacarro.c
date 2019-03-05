#include <stdio.h>
#include <stdlib.h>
#include "../../carro/carro.h"
void telaCarro(){
    int menu = 0;
    while (menu != 9){  
        printf("\n\t# # CARROS \n\t[1]Cadastrar Novo Carro \n\t[2]Atualizar Informações do Carro \n\t[3]Disponibilizar Carros p/ Venda \n\t[4]Localizar Carro Por Modelo \n\t[9]Voltar");
        scanf("%d",&menu);
        if(menu == 1){
			system("clear");
			TCarro aux;
			aux.arCondicionado = 0;
			aux.disponivel = 0;
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
			while ((aux.arCondicionado != 1)||(aux.arCondicionado != 2)){
			printf("\t      Ar Condicionado [(1)Sim/(2)Não]: ");
			scanf("%d", &aux.arCondicionado);}
			printf("\t      Quilometragem Inicial: ");
			scanf("%d", &aux.quilometragem);
			printf("\t      Valor da Diária: ");
			scanf("%f", &aux.valorDiaria);
			while ((aux.disponivel != 1)||(aux.disponivel != 2)){
			printf("\t      Disponibilidade [(1)Sim/(2)Não]: ");
			scanf("%d", &aux.disponivel);}
			
			cadastrarCarro(aux);				
		}
		if(menu == 2){
			system("clear");
			TCarro aux;
			aux.arCondicionado = 0;
			aux.disponivel = 0;
			printf("\n\t# # CARROS\n");
			printf("\t# # # Atualizar Cadastro Do Carro\n");
			printf("\t      ID: ");
			scanf("%d", &aux.id);
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
			while ((aux.arCondicionado != 1)||(aux.arCondicionado != 2)){
			printf("\t      Ar Condicionado [(1)Sim/(2)Não]: ");
			scanf("%d", &aux.arCondicionado);}
			printf("\t      Quilometragem Inicial: ");
			scanf("%d", &aux.quilometragem);
			printf("\t      Valor da Diária: ");
			scanf("%f", &aux.valorDiaria);
			while ((aux.disponivel != 1)||(aux.disponivel != 2)){
			printf("\t      Disponibilidade [(1)Sim/(2)Não]: ");
			scanf("%d", &aux.disponivel);}
			
			atualizarCarro(aux);		
		}
		if(menu == 3){
			system("clear");
			printf("\n\t# # CARROS");
			printf("\n\t# # # Carros Disponiveis Para Venda ");
			
			disponibilizarCarrosVenda();		
		}
		if(menu == 4){
			system("clear");
			printf("\n\t# # CARROS");
			printf("\n\t# # # Localizar Carro Por Modelo ");
			char modelo[10];
			printf("\n\t      Modelo: ");
			scanf("%s",modelo);
			
			localizarCarroPorModelo(modelo);		
		}
		if(menu == 9){
			system("clear");		
		}
        else{printf("\nComando não conhecido.\nTente Novamente.\n");}     
    }
}
