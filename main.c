#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include "agenda.h"

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
    int op, numero;
    Agenda a;
    Dado c;
    
    criaAgenda(&a);

    do {

    printf("\n0. Fim             2. Editar Contato      4. Exclui Contato\n");
    printf("1. Novo Contato       3.Consulta Contato     5. Exibe Agenda\n");
	printf("Operacao: ");
    scanf("%d",&op);

    switch(op){

        case 1:        	
        	printf("\nTelefone: ");
			scanf ("%d", &c.num);
			printf("Nome do Contato: ");
			scanf ("%s", &c.nome);
			if (inclui(&a,c)==0)
			   	printf("Operacao Realizada com Sucesso!\n");
        	else
                printf("Operacao NAO realizada: Faltou Memoria!");
             break;
        case 2:
        	printf("\nDigite Contato Pelo Numero: ");
			scanf(" %d",&numero);
			if (edita(&a,&c,numero)==0){
		    	 	printf("Operacao Realizada com Sucesso!\n");}
 			else if(edita(&a,&c,numero)==1){
            	 	printf("Operacao NAO Realizada\nAGENDA VAZIA!\n");
				}
			else{
				printf("Operacao NAO Realizada.\nNUMERO INEXISTENTE!\n"); }	
          	 break;    
        case 3:
			printf("Informe o Numero: ");
            scanf("%d",&numero);
            	if(consulta(a,&c,numero)==0){
            	 	printf("Operacao Realizada com Sucesso!\n");
				 }
				 else if(consulta(a,&c,numero)==1){
            	 	printf("Operacao NAO Realizada\nAGENDA VAZIA!\n");
				 }
				 else{
				 	printf("Operacao NAO Realizada.\nNUMERO INEXISTENTE!\n");
				 }          	 
				 break;
        case 4:
        	 printf("Digite o numero: ");
             scanf("%d",&numero);
            	 if(exclui(&a,&c,numero)==0){
            	 	printf("Operacao Realizada com Sucesso!\n");
				 }
				 else if(exclui(&a,&c,numero)==1){
            	 	printf("Operacao NAO Realizada\nAGENDA VAZIA!\n");
				 }
				 else{
				 	printf("Operacao NAO Realizada.\nNUMERO INEXISTENTE!\n");
				 }
             break;	
        case 5:
			exibe(a);
        	break;
      }
      getch();
      system("cls");
    } while (op!=0);  

  return(0);	
}
