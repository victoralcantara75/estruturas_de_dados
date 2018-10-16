#include <stdio.h>
#include <stdlib.h>

typedef struct sCell
{
	int info;
	struct sCell *prox;
	struct sCell *ant;
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

int inserir(celula **lista, int elemento){
	
	celula *no = criarCelula();
	if(no == NULL) printf("Erro na alocacao");
	
	no->info = elemento;
	if(listaVazia(lista))
	{
		no->prox = NULL;
		no->ant = NULL;
		(*lista) = no;
		return 1;
	}
	
	celula *aux = *lista;
	
	while ( aux->prox != NULL && aux->prox->info < elemento){
		aux = aux->prox;
	}
	
	if(aux == *lista && aux->info > elemento)
	{
		no->ant = aux->ant;
		aux->ant = no;
		no->prox = aux;
		(*lista) = no;
	}else
	{
		no->ant = aux;
		no->prox = aux->prox;
		aux->prox = no;
		if (no->prox != NULL) no->prox->ant = no;
	}


	return 1;
}

celula* remover(celula **lista, int elemento){
	
	if(listaVazia(lista)){
		printf("lista vaziza");
		exit(1);
	}
	
	celula *aux = *lista;
	celula *q = criarCelula();
	
	while ( aux->info != elemento){
		aux = aux->prox;
	}
	
	q->info = aux->info;
	
	aux->ant->prox = aux->prox;
	aux->prox->ant = aux->ant;
	free(aux);
	
	return q;
}

void imprimirLista(celula *lista){
	celula *aux = lista;
	while (aux != NULL){
		printf("%d \n", aux->info);
		aux = aux->prox;
	}
		printf("\n");
}

int main(){
	
	celula *ptrlista = criarCelula();
	inicializaLista(&ptrlista);
	
	inserir(&ptrlista, 2);
	inserir(&ptrlista, 5);
	inserir(&ptrlista, 3);
	inserir(&ptrlista, 7);
	inserir(&ptrlista, 6);
	imprimirLista(ptrlista);
	
	celula *removido = remover(&ptrlista, 3);
	printf("elemento removido foi: %d\n", removido->info);
	imprimirLista(ptrlista);
	
	celula *removido2 = remover(&ptrlista, 6);
	printf("elemento removido foi: %d\n", removido2->info);
	imprimirLista(ptrlista);
	
	free(ptrlista);
	
	return 0;
}