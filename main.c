#include <stdio.h>
#include <stdlib.h>
#include "./tela/locacao/telalocacao.h"
#include "./tela/carro/telacarro.h"
#include "./tela/cliente/telacliente.h"

int main(){
	system("clear");
    int menu = 0;
    while (menu != 9){ 
    	system("clear"); 
        printf("\n    # MENU PRINCIPAL \n\n      [1]Locações \n\n      [2]Clientes \n\n      [3]Carros \n\n      [9]Sair \n\n      Opção ");
        scanf(" %d",&menu);
        if(menu == 1){
			system("clear");
			telaLocacao();			
		}
		if(menu == 2){
			system("clear");
			telaCliente();
		}
		if(menu == 3){
			system("clear");
			telaCarro();
		}
		if(menu == 9){
			system("clear");			
		}
        if((menu <= 0)&&(menu > 3)&&(menu != 9))
        	printf("\nComando não conhecido.\nTente Novamente.\n");     
    }
    
}
