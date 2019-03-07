#include <stdio.h>
#include <stdlib.h>
#include "../../carro/carro.h"
void telaCarro(){
    system("clear");
    int menu = 0;
    while (menu != 9){    	
        printf("\n\t# # CARROS \n\n\t[1]Cadastrar Novo Carro \n\n\t[2]Atualizar Informações do Carro \n\n\t[3]Disponibilizar Carros p/ Venda \n\n\t[4]Localizar Carro Por Modelo \n\n\t[9]Voltar \n\n\tOpção ");
        scanf("%d",&menu);
        if(menu == 1){
			system("clear");
			/*
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
			scanf("%d", &aux.disponivel);}             
			*/

			cadastroCarroInput();
			
			system("clear");
			int temp = 0;
			printf("\n\n\t      Carro cadastrado com sucesso!\n");

				while ((temp != 1)&&(temp != 2)){
					printf("\n\n\t      Cadastrar outro carro? \n\t      [(1)Sim/(2)Não]\n\n\t      Opção  ");
					scanf("%d", &temp);
					if(temp == 1){
						system("clear");
						cadastroCarroInput();
					}
					if(temp == 2){
						system("clear");
					}
				}

		}
		    if(menu == 2){
			system("clear");
			TCarro aux;	
            aux.disponivel = 0;
            aux.arCondicionado = 0;		
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

            while ((aux.arCondicionado != 1)&&(aux.arCondicionado != 2)){	
			printf("\t      Ar Condicionado [(1)Sim/(2)Não]: ");
			scanf("%d", &aux.arCondicionado);}
            
			printf("\t      Quilometragem Inicial: ");
			scanf("%d", &aux.quilometragem);
			printf("\t      Valor da Diária: ");
			scanf("%f", &aux.valorDiaria);		
	
			while ((aux.disponivel != 1)&&(aux.disponivel != 2)){				
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
        if((menu <= 0)&&(menu > 4)&&(menu != 9))
        	printf("\nComando não conhecido.\nTente Novamente.\n");     
    }
}
