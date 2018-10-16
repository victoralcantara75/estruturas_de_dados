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
	if ((*lista)->info == 0)
		return 1;
	return 0;
}

int inserirFinal(celula **lista, char elemento){
	
	celula *no = criarCelula();
	if(no == NULL) printf("Erro na alocacao");
	
	no->info = elemento;
	
	if(listaVazia(lista))
	{
		no->prox = *lista;
		(*lista)->prox = no;
		(*lista)->info++;
		return 1;
	}
	
	celula *aux = (*lista);
	while(aux->prox != (*lista)){
		aux = aux->prox;
	}
	no->prox = aux->prox;
	aux->prox = no;
	(*lista)->info++;
	
	return 1;
}

void imprimirLista(celula *lista){
	celula *aux = (lista)->prox;
	
	while (aux != lista){
		printf("%c \n", aux->info);
		aux = aux->prox;
	}
	
	printf("A lista tem %d elementos \n", lista->info);
}

int main(){
	
	celula *ptrlista = criarCelula();
	inicializaLista(&ptrlista);
	
	celula *cabecalho = criarCelula();
	cabecalho->info = 0;
	cabecalho->prox = cabecalho;
	
	ptrlista = cabecalho;
	
	inserirFinal(&ptrlista, 'L');
	inserirFinal(&ptrlista, 'G');
	inserirFinal(&ptrlista, 'Y');

	imprimirLista(ptrlista);
	free(ptrlista);
	
	return 0;
}