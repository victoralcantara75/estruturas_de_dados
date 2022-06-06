#include <stdio.h>
#include <stdlib.h>


typedef struct sCell{
	int info;
	struct sCell *next;
}celula;

typedef struct sFila{
	celula *inicio, *fim;
}fila;

void inicializar(fila *f){
	f->inicio = NULL;
	f->fim = NULL;
}

int vazia(fila *f){
	if (f->inicio == NULL && f->fim== NULL)
	{
		return 1;
	}
	return 0;
}

int enfileirar(fila *f, int p1){

	celula *no = (celula*)malloc(sizeof(celula));
	if (no == NULL)
	{
		printf("ERRO NA ALOCACAO\n");
		return 0;
	}

	no->info = p1;
	no->next = NULL;

	if (vazia(f))
	{
		f->inicio = no;
		f->fim = no;
		return 1;
	}	

	f->fim->next = no;
	f->fim = no;
	return 1;

}

int desenfileirar(fila *f){

	if (vazia(f))
	{
		exit(1) ;
	}

	celula *aux = f->inicio;
	f->inicio = aux->next;

	int x = aux->info;

	if (f->inicio == NULL)
	{
		f->fim = NULL;
	}

	free(aux);
	return x;	
}

void imprimir(fila *f){
	celula *aux = f->inicio;

	while (aux != NULL)
	{
		printf("%d\n", aux->info);
		aux = aux->next;
	}
}

void imprimirC(fila *f){
	while(!vazia(f)){
		printf("%d\n", f->inicio->info);
		desenfileirar(f);
	}
}