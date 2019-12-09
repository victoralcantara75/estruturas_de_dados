// ##########################################
// #                                        #
// #   IMPLEMENTADO POR VICTOR ALCANTARA    #
// #  https://github.com/victoralcantara75  #
// #              15/02/2019                #
// #                                        #
// ##########################################

#include <stdio.h>
#include <stdlib.h>

typedef struct spessoa{
	int idade;
	int altura;
}pessoa;

typedef struct sCell{
	pessoa info;
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

int enfileirar(fila *f, pessoa p1){

	celula *no = (celula*)malloc(sizeof(celula));
	if (no == NULL)
	{
		printf("ERRO NNA ALOCACAO\n");
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

pessoa desenfileirar(fila *f){

	if (vazia(f))
	{
		exit(1) ;
	}

	celula *aux = f->inicio;
	f->inicio = aux->next;

	pessoa x = aux->info;

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
		printf("%d\n", aux->info.idade);
		printf("%d\n", aux->info.altura);
		aux = aux->next;
	}
}

void imprimirC(fila *f){
	while(!vazia(f)){
		printf("%d\n", f->inicio->info.idade);
		printf("%d\n", f->inicio->info.altura);
		desenfileirar(f);
	}
}


int main(){

	fila f;
	inicializar(&f);

	pessoa p1;
	p1.idade = 10;
	p1.altura = 170;

	pessoa p2;
	p2.idade = 90;
	p2.altura = 140;

	enfileirar(&f, p1);
	enfileirar(&f, p2);

	imprimirC(&f);

	
}