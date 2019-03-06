#include <stdio.h>
#include <stdlib.h>
#include "../../locacao/locacao.h"
void telaLocacao(){
    system("clear");
    int menu = 0;
    while(menu != 9){
    		printf("\n\t# # Locação \n\t[1]Nova Locação \n\t[2]Finalizar Locação \n\t[3]Quantidade de Carros Emprestados \n\t[9]Voltar");
        	scanf("%d",&menu);
		if(menu == 1){
			system("clear");
			printf("\n\t# # Locação");
			printf("\n\t# # # Nova Locação\n");

			char cpf[13];
			float motor;
			int arCondicionado;
			printf("\t      CPF: ");
			scanf(" %s",cpf);
			printf("\t      MOTOR: ");
			scanf(" %f",&motor);
			printf("\t      Ar Condicionado: ");
			scanf(" %d",&arCondicionado);

			iniciarLocacao(atoi(cpf), motor, arCondicionado);		
		}
		if(menu == 2){
			system("clear");
			printf("\n\t# # Locação");
			printf("\n\t# # # Finalizar Locação\n");

			int idLocacao;
			printf("\t      ID da Locação: ");
			scanf("%d",&idLocacao);

			TData data;
			printf("\t      DIA: ");
			scanf("%d",&data.dia);
			printf("\t      MES: ");
			scanf("%d",&data.mes);
			printf("\t      ANO: ");
			scanf("%d",&data.ano);
			printf("\t      HORA: ");
			scanf("%d",&data.hora);

			int quilometragemEntrega;
			printf("\t      QUILOMETRAGEM NA ENTREGA: ");
			scanf("%d",&quilometragemEntrega);

			finalizarLocacao(idLocacao, data, quilometragemEntrega);		
		}
		if(menu == 3){
			system("clear");
			printf("\n\t# # Locação");
			printf("\n\t# # # Quantidade de Carros Emprestados\n");

			printf("\tO atual número de carros alugados é: %d", numeroRegistrosLocacoes());
		
		}
		if((menu < 0)&&(menu > 3)&&(menu != 9))
        	printf("\nComando não conhecido.\nTente Novamente.\n");    
    }
}
