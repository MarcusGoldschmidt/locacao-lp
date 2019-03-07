#include <stdio.h>
#include <stdlib.h>
#include "../../cliente/cliente.h"
void telaCliente(){
    system("clear");
    int menu = 0;
    while(menu != 9){
    	system("clear");
    	printf("\n\t# # Clientes \n\n\t[1]Cadastrar Novo Cliente \n\n\t[2]Atualizar Pontuação \n\n\t[3]Localizar Locações Realizadas \n\n\t[4]Listar Clientes entre 18 e 25 \n\n\t[5]Listar Clientes acima de 200 Pontos \n\n\t[9]Voltar \n\n\tOpção ");
        scanf("%d",&menu);
		if(menu == 1){
			system("clear");
			printf("\n\t# # Clientes\n");
			printf("\t# # # Cadastrar Novo Cliente\n");

			TCliente aux;					

			printf("\t      CPF: ");
			scanf("%s", aux.cpf);
			printf("\t      Nome: ");
			scanf("%[^\n]s", aux.nome);
			setbuf(stdin, NULL);			
			printf("\t      Idade: ");
			scanf(" %d", &aux.idade);
			printf("\t      Endereço: ");
			scanf("%[^\n]s", aux.endereco);
			setbuf(stdin, NULL);
			printf("\t      Cidade: ");
			scanf("%[^\n]s", aux.cidade);
			setbuf(stdin, NULL);
			printf("\t      Estado: ");
			scanf("%[^\n]s", aux.estado);
			setbuf(stdin, NULL);			
			printf("\t      Pontos: ");
			scanf(" %d", &aux.pontos);			

			cadastrarCliente(aux);		
		}
		if(menu == 2){
			system("clear");
			printf("\n\t# # Clientes\n");
			printf("\n\t# # # Atualizar Pontuação\n");
			char cpf[13];
			printf("\tCPF: ");
			scanf(" %s",cpf);

			atualizarPontuacao(cpf);
		}
		if(menu == 3){
			system("clear");
			printf("\n\t# # Clientes\n");
			printf("\n\t# # # Localizar Locações Realizadas\n");

			localizarLocacao();

		}
		if(menu == 4){
			system("clear");
			printf("\n\t# # Clientes\n");
			printf("\n\t# # # Listar Clientes entre 18 e 25\n");

			listarClientesIdade();
		}
		if(menu == 5){
			system("clear");
			printf("\n\t# # Clientes\n");
			printf("\n\t# # # Listar Clientes Acima de 200 Pontos\n");

			listarClientesPontos();			
		}
		if((menu <= 0)&&(menu > 5)&&(menu != 9))
        	printf("\nComando não conhecido.\nTente Novamente.\n");    
        }
}
