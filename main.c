#include <stdio.h>
#include <stdlib.h>
#include "./tela/locacao/telalocacao.h"
#include "./tela/carro/telacarro.h"
#include "./tela/cliente/telacliente.h"

int main(){
    int menu = 0;
    while (menu != 9){  
        printf("# MENU PRINCIPAL \n  [1]Locações \n  [2]Clientes \n  [3]Carros \n[9]Sair \n  Opção ");
        scanf("%d",&menu);
        if(menu == 1){
			system("cls");
			telaLocacao();			
		}
		if(menu == 2){
			system("cls");
			telaCliente();
		}
		if(menu == 3){
			system("cls");
			telaCarro();
		}
        else{printf("Comando não conhecido.\nTente Novamente.\n");}     
    }
    return 0;
}
