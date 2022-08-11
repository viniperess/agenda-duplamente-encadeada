#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"

void criaAgenda(Agenda *a){
	a->inicio = NULL;
	a->fim = NULL;
	a->n = 0;
}

int inclui(Agenda *a, Dado c){
	
	Nodo *pNodo,*pAux;
	pNodo = (Nodo *) malloc(sizeof(Nodo));
	if(pNodo == NULL){
		return(FALTOU_MEMORIA);
	}else{
		pNodo->info = c;
		pNodo->ant = a->fim;
		pNodo->prox = NULL;
		
		if(a->n == 0){
			a->inicio = pNodo;
		}else{
			a->fim->prox = pNodo;
		}
		a->fim = pNodo;
		a->n++;
		return(SUCESSO);
}
}
int consulta(Agenda a, Dado *c, int numero){
	
	Nodo *pNodo;
	
	pNodo = a.inicio;


if(a.n == 0){
	return(LISTA_VAZIA);
}
else{
	while(pNodo != NULL){
		if(pNodo->info.num == numero){
			*c = pNodo->info;
			printf("CONTATO ENCONTRADO!\nNUMERO: %d | NOME: %s\n",c->num,c->nome);
			return (SUCESSO);
		}
	 pNodo = pNodo->prox;	
	} 
	return (CODIGO_INEXISTENTE);
}
}

int exclui(Agenda *a, Dado *c, int numero){
	
	Nodo *pNodo,*pAux,*pProx;
	
	pNodo = a->inicio;
	
if(a->n == 0){
	return(LISTA_VAZIA);
}
else{
	while(pNodo != NULL){
	if(pNodo->info.num == numero){		
	*c = pNodo->info;
			
	if(a->n == 1){
			a->inicio = NULL;
			a->fim = NULL;
			a->n--;
	}
	else if(pNodo == a->inicio){
		pAux = pNodo->prox;
		pAux->ant = NULL;
		a->inicio = pAux;
		a->n--;
	}
	else if(pNodo == a->fim){
		pAux = pNodo->ant;
		pAux->prox = NULL;
		a->fim = pAux;
		a->n--;
	}
	else{
		pProx = pNodo->prox;
		pAux = pNodo->ant;
		pAux->prox = pProx;
		pProx->ant = pAux;
		a->n--;
	}
		printf("Contato Excluido.\n*****Numero: %d ***** | *****Nome: %s *****\n",c->num,c->nome);		 	
        free(pNodo);
		return(SUCESSO);	
	}
		pNodo = pNodo->prox;}
	return(CODIGO_INEXISTENTE);	
}
}


int edita(Agenda *a, Dado *c, int numero){
	
	Nodo *pNodo,*pAux;
	
	pNodo = a->inicio;


if(a->n == 0){
	return(LISTA_VAZIA);
}
else{
while(pNodo != NULL){
	if(pNodo->info.num == numero){		
		*c = pNodo->info;
		printf("Contato Encontrado.\n*****Numero: %d ***** | *****Nome: %s *****\n",c->num,c->nome);
		printf("Digite o novo numero: ");
		scanf("%d",&c->num);
		printf("Digite o novo nome: ");
		scanf("%s",&c->nome);
		pNodo->info = *c;
		printf("Contato Editado.\n*****Numero Novo: %d ***** | *****Nome Novo: %s *****\n",pNodo->info.num,pNodo->info.nome);
		return(SUCESSO);
		} 	
	pNodo = pNodo->prox;
}
		return(CODIGO_INEXISTENTE);	
}
}

void exibe(Agenda a){
     Nodo *pAux;
     pAux = a.inicio;
     printf("\nExibindo a Agenda\n");
	 printf("\n*%d NUMEROS ENCONTRADOS*\n",a.n);
	 printf("Inicio: %p \nFim: %p \n",a.inicio,a.fim);
     printf("[Endereco Anterior] [ Numero ]  [Endereco   Nodo]  [  Nome  ]   [Endereco Proximo]\n");
 	    while (pAux != NULL) {
           printf("%p  |   %d    %p    %s  |  %p\n", pAux->ant, pAux->info.num, pAux, pAux->info.nome, pAux->prox);
           pAux = pAux->prox;
     }
}

