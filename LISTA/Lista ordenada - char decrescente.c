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
		(*lista) = no;
		return 1;
	}
	
	celula *aux = *lista;
	celula *ant;
	
	while ( aux != NULL && aux->info > elemento){
		ant = aux;
		aux = aux->prox;
	}	
	no->prox = aux;
	
	if(aux == *lista) *lista = no;
	else ant->prox = no;
	
	return 1;
}

void imprimirLista(celula *lista){
	celula *aux = lista;
	while (aux != NULL){
		printf("%d \n", aux->info);
		aux = aux->prox;
		
	}
}

int main(){
	
	celula *ptrlista = criarCelula();
	inicializaLista(&ptrlista);
	
	inserir(&ptrlista, 5);
	inserir(&ptrlista, 2);
	inserir(&ptrlista, 7);
	inserir(&ptrlista, 8);
	inserir(&ptrlista, 4);
	imprimirLista(ptrlista);
	free(ptrlista);
	
	return 0;
}