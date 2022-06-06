#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct sP{
	char nome[20];
	int id;
}processo;

typedef struct sCell{
	char info;
	struct sCell *prox;
}celula;

celula *criarCelula(){
	return (celula*)malloc(sizeof(celula));
}

void inicializar(celula **lista){
	(*lista) = NULL;
}

int vazia(celula **lista){
	if ((*lista) == NULL)
		return 1;
	return 0;
}

void inserirInicio(celula **lista, char elemento){
	
	celula *no = criarCelula();
	no->info = elemento;
	
	if(vazia(lista))
		no->prox = no;
	else
		no->prox = (*lista);
	
	(*lista) = no;
	
	celula *aux = no->prox;

	while(aux->prox != no->prox){
		aux = aux->prox;
	}
	
	aux->prox = no;

}

void inserirFinal(celula  **lista, char elemento){
	
	celula *no = criarCelula();
	no->info = elemento;
	
	if(vazia(lista)){
		no->prox = no;
		(*lista) = no;
		return;
	}
	
	celula *aux = (*lista);
 
    while(aux->prox != (*lista)){
		aux = aux->prox;
	}
	
	aux->prox = no;
	no->prox = (*lista);
	
}

void removerInicio(celula **lista){
	if (vazia(lista))
		return;
	
	celula *aux = (*lista);
	celula *rem = (*lista);
	
	while(aux->prox != (*lista)){
		aux = aux->prox;
	}

	(*lista) = rem->prox;
	aux->prox = (*lista);
	free(rem);
}

void removerFinal(celula **lista){
	if (vazia(lista))
		return;
	
	celula *aux = (*lista);
	celula *ant = NULL;
	
	while(aux->prox != (*lista)){
		ant = aux;
		aux = aux->prox;
	}
	if (ant != NULL)
		ant->prox = (*lista);
	else 
		(*lista) = NULL;
	
	free(aux);
}

void imprimir(celula **lista){
	
	if (vazia(lista))
		return;
	
	celula *aux = (*lista);
	do{
		printf("%c ", aux->info);
		aux = aux->prox;
	}while(aux != (*lista));
	
	printf("\n");
}

int vogal(char letra){
	if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u')
		return 1;
	return 0;
}

void imprimir_vogal(celula **lista){
	
	if (vazia(lista))
		return;
	
	celula *aux = (*lista);
	do{
		if (vogal(aux->info))
			printf("%c ", aux->info);
		aux = aux->prox;
	}while(aux != (*lista));
	
	printf("\n");
}

















