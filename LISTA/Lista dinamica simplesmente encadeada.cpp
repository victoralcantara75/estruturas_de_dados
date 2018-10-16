#include <stdio.h>
#include <stdlib.h>

typedef struct sCell
{
	int info;
	struct sCell *prox;
}celula;

celula *criarCelula(){
	return (celula*)malloc(sizeof(celula));
}
void inicializaLista(celula **lista){
	(*lista)->prox = NULL;
}

int listaVazia(celula **lista){
	if ((*lista)->prox == NULL)
		return 1;
	return 0;
}

int inserirInicio(celula **lista, int elemento){
	if(listaVazia(lista))
	{
		celula *no = criarCelula();
		no->info = elemento;
		no->prox = NULL;
		(*lista)->prox = no;
		return 1;
	}
	return 0;
}

void imprimirLista(celula **lista){
	celula *aux = (*lista);
	while (aux != NULL){
		
		aux = aux->prox;
		printf("%d \n", aux->info);
	}
}

int main(){
	
	celula *ptrlista = criarCelula();
	inicializaLista(&ptrlista);
	
	inserirInicio(&ptrlista, 5);
	imprimirLista(&ptrlista);
	
	return 0;
}