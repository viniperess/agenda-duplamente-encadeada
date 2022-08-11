#ifndef agenda_H
#define agenda_H

#define SUCESSO 0
#define LISTA_VAZIA 1
#define FALTOU_MEMORIA 2
#define CODIGO_INEXISTENTE 3

typedef struct {
	int num;
	char nome[10];
} Dado;

typedef struct nodo Nodo;

struct nodo {
	Dado info;
	Nodo *prox;
	Nodo *ant;
};

typedef struct {
	Nodo *inicio;
	Nodo *fim;
	int n;
} Agenda;

void criaAgenda (Agenda *a);
int inclui(Agenda *a, Dado c);
int consulta (Agenda a, Dado *c, int numero);
int exclui(Agenda *a, Dado *c, int numero);
void exibe(Agenda a);
int edita(Agenda *a, Dado *c, int numero);
#endif
