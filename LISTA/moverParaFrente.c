#include <stdio.h>
#include <stdlib.h>

typedef struct sCell
{
	char info;
	struct sCell *prox;
}celula;

celula *criarCelula(){
	return (celula*)malloc(sizeof(celula));
}
void inicializaLista(celula **lista){
	(*lista) = NULL;
}

int listaVazia(celula **lista){
	if ((*lista) == NULL)
		return 1;
	return 0;
}

int inserirFinal(celula **lista, char elemento){
	
	celula *no = criarCelula();
	if(no == NULL) printf("Erro na alocacao");
	
	no->info = elemento;
	no->prox = NULL;
	
	if(listaVazia(lista))
	{
		(*lista) = no;
		return 1;
	}
	
	celula *aux = *lista;
	
	while ( aux->prox != NULL){
		aux = aux->prox;
	}	
	
	aux->prox = no;
	
	//if(aux == *lista) *lista = no;
	
	return 1;
}

int moverParaFrente(celula **lista, char elemento){
	
	if(listaVazia(lista))
		return 0;
	
	celula *aux = *lista;
	celula *ant;
	
	while (aux->info != elemento){
		ant = aux;
		aux = aux->prox;
	}
	
	ant->prox = aux->prox;
	aux->prox = *lista;
	*lista = aux;
	return 1;
	
}

void imprimirLista(celula *lista){
	celula *aux = lista;
	while (aux != NULL){
		printf("%c \n", aux->info);
		aux = aux->prox;
		
	}
}

int main(){
	
	celula *ptrlista = criarCelula();
	inicializaLista(&ptrlista);
	
	inserirFinal(&ptrlista, 'L');
	inserirFinal(&ptrlista, 'A');
	inserirFinal(&ptrlista, 'B');
	inserirFinal(&ptrlista, 'S');
	inserirFinal(&ptrlista, 'O');
	imprimirLista(ptrlista);
	printf("\n");
	moverParaFrente(&ptrlista, 'O');
	moverParaFrente(&ptrlista, 'B');
	imprimirLista(ptrlista);
	free(ptrlista);
	
	return 0;
}