#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct sP{
	char nome[20];
	int id;
}processo;

typedef struct sCell{
	processo info;
	struct sCell *prox;
}celula;

typedef struct sC{
	int tamanho;
	celula *prox;
}cabecalho;

cabecalho *criarCabecalho(){
	cabecalho *c = (cabecalho*)malloc(sizeof(cabecalho));
	c->tamanho = 0;
	c->prox = NULL;
	
	return c;
}

celula *criarCelula(){
	return (celula*)malloc(sizeof(celula));
}

void inicializar(cabecalho **lista){
	(*lista) = criarCabecalho();
}

int vazia(cabecalho **lista){
	if ((*lista)->tamanho == 0)
		return 1;
	return 0;
}

void inserirInicio(cabecalho **lista){
	
	processo p;
	printf("digite o nome:" );
	scanf("%s", p.nome);
	printf("digite o id:" );
	scanf("%d", &p.id);
	
	celula *no = criarCelula();
	no->info.id = p.id;
	strcpy(no->info.nome, p.nome);
	
	if(vazia(lista))
		no->prox = no;
	else
		no->prox = (*lista)->prox;
	
	(*lista)->prox = no;
	
	int i;
	celula *aux = no;
	for (i = 0; i < (*lista)->tamanho; i++){
		aux = aux->prox;
	}
	
	aux->prox = no;
	(*lista)->tamanho++;

}

void imprimir(cabecalho **lista){
	celula *aux = (*lista)->prox;
	int i;
	for (i = 0; i < (*lista)->tamanho; i++){
		printf("id - %d\n", aux->info.id);
		aux = aux->prox;
	}
}


















