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

int inserir(celula **lista, char elemento){
	
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
	
	while ( aux != NULL && aux->info < elemento){
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
		printf("%c \n", aux->info);
		aux = aux->prox;
		
	}
}

int main(){
	
	celula *ptrlista = criarCelula();
	inicializaLista(&ptrlista);
	
	inserir(&ptrlista, 'b');
	inserir(&ptrlista, 'c');
	inserir(&ptrlista, 'e');
	inserir(&ptrlista, 'f');
	inserir(&ptrlista, 'a');
	inserir(&ptrlista, 'd');
	inserir(&ptrlista, 'g');
	imprimirLista(ptrlista);
	free(ptrlista);
	
	return 0;
}