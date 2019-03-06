#include <stdio.h>
#include <stdlib.h>
#include "../../cliente/cliente.h"
void telaCliente(){
    int menu = 0;
    while(menu != 9){
    	printf("\n\t# # Clientes \n\t[1]Cadastrar Novo Cliente \n\t[2]Atualizar Pontuação \n\t[3]Localizar Locações Realizadas \n\t[4]Listar Clientes entre 18 e 25 \n\t[5]Listar Clientes acima de 200 Pontos \n\t[9]Voltar \n\tOpção ");
        scanf("%d",&menu);
		if(menu == 1){
			system("clear");
			printf("\n\t# # Clientes\n");
			printf("\t# # # Cadastrar Novo Cliente\n");
			TCliente aux;
			aux.idade = 18;			
			printf("\t      CPF: ");
			scanf("%s", aux.cpf);
			printf("\t      Nome: ");
			scanf("%s", aux.nome);
			while(aux.idade > 17){
			printf("\t      Idade: ");
			scanf(" %d", &aux.idade);}
			printf("\t      Endereço: ");
			scanf("%s", aux.endereco);
			printf("\t      Cidade: ");
			scanf("%s", aux.cidade);
			printf("\t      Estado: ");
			scanf("%s", aux.estado);			
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
		else{printf("\nComando não conhecido.\nTente Novamente.\n");}    
    }
}
