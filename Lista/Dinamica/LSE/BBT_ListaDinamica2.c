#include<stdio.h>
#include<stdlib.h>

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
    printf("Lista: ");
	celula *aux = lista;
	while (aux != NULL){
		printf("%c ", aux->info);
		aux = aux->prox;
		
	}
    printf("\n");
}

celula* removerPrimeiro(celula **lista){
    if(listaVazia(lista)){
        printf("Lista vazia");
		exit(1);
    }

    celula *aux = *lista;
    celula *q = criarCelula();

    q->info = aux->info;
    *lista = (*lista)->prox;

    free(aux);

    return q;
}

celula* remover(celula **lista, char elemento){
	
	if(listaVazia(lista)){
		printf("lista vaziza");
		exit(1);
	}
	
	celula *aux = *lista;
    celula *ant;
	celula *q = criarCelula();
	
	while ( aux->info != elemento){
        ant = aux;
		aux = aux->prox;
	}
	
	q->info = aux->info;
	
	ant->prox = aux->prox;
	free(aux);
	
	return q;
}

int moverParaFrente(celula **lista, char elemento){
	
	if(listaVazia(lista)){
        printf("Lista Vazia");
		return 0;
    }
	
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

int transposicao(celula **lista, char elemento){
    if(listaVazia(lista)){
        printf("Lista Vazia");
		return 0;
    }

    celula *aux = *lista;
	celula *ant, *ant2;
	
	while (aux->info != elemento){
        ant2 = ant;
		ant = aux;
		aux = aux->prox;
	}

    ant2->prox = aux;
    ant->prox = aux->prox;
    aux->prox = ant;

    return 1;
}