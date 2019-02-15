// ##########################################
// #                                        #
// #   IMPLEMENTADO POR VICTOR ALCANTARA    #
// #  https://github.com/victoralcantara75  #
// #              15/02/2019                #
// #                                        #
// ##########################################

#include <stdio.h>
#include <stdlib.h>

typedef struct sCell{
	int info;
	struct sCell *prox;
}celula;

typedef struct sFila{
	celula *inicio;
	celula *fim;
}fila;

celula *criarNo(){
	return (celula*)malloc(sizeof(celula));
}

void inicializar(fila *fila){
	fila->inicio = NULL;
	fila->fim = NULL;
}

int vazia(fila *fila){
	if(fila->inicio == NULL && fila->fim == NULL)
		return 1;
	return 0;
}

int enfileirar(fila *fila, int elemento){
	
	celula *no= criarNo();
	if(no == NULL) return -1;
	
	no->info = elemento;
	
	if(vazia(fila)){
		fila->inicio = no;
		fila->fim = no;
		return 1;
	}
	
	fila->fim->prox = no;
	no->prox = NULL;
	return 1;
}

int desenfileirar(fila *fila){
	
	if (vazia(fila)) return 0;
	
	celula *aux = fila->inicio;
	fila->inicio = aux->prox;
	
	free(aux);
	return 1;
	
}

void imprimir(fila *fila){
	
	while (!vazia(fila)){
		printf("%d ", fila->inicio->info);
		desenfileirar(fila);
	}
}

int main(){
	
	fila ptrfila;
	inicializar(&ptrfila);
	
	enfileirar(&ptrfila, 6);
	enfileirar(&ptrfila, 12);
	imprimir(&ptrfila);
	
	return 0;
}