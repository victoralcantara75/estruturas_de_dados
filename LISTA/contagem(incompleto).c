#include <stdio.h>
#include <stdlib.h>

typedef struct sCell{
	char info;
	struct sCell *prox;
	int cont;
}celula;

void inicializar(celula **lista){
	*lista = NULL;
}

int vazia(celula **lista){
	if(*lista == NULL)
		return 1;
	return 0;
}

int inserir(celula **lista, char elemento){
	celula *no = (celula*)malloc(sizeof(celula));
	no->info = elemento;
	no->cont = 0;

	if (vazia(lista))
	{
		*lista = no;
		no->prox = NULL;
		return 1;
	}

	no->prox = *lista;
	*lista = no;
	return 1;
}

void contagem(celula **lista){

	/*celula *t = *lista;
	celula *aux = *lista;
	celula *ant;
	celula *ant_m;

	celula *maior = aux;;

	while(t != NULL){

		while(aux != NULL){
			if (aux->cont > maior->cont)
			{	
				ant_m = ant;
				maior = aux;
			}
			ant = aux;
			aux = aux->prox;
		}
		if (maior != t)
		{
			ant_m->prox = maior->prox;
			maior->prox = t;
			if (t == *lista) *lista = maior;
			else t = maior;
		}

		t=t->prox;
	}*/


	


}

int pesquisa(celula **lista, char elemento){
	celula *aux = *lista;
	while (aux->prox != NULL && aux->info != elemento){
		aux = aux->prox;
	}
	if (aux->info != elemento)
	{
		printf("elemento nao encontrado \n");
	}
	else
	{
		printf("Elemento pesquisado foi %c\n", aux->info);
		aux->cont++;
	}
	contagem(&*lista);
}

void imprimir(celula **lista){
	if (vazia(lista))
	{
		printf("lista vazia \n");
		exit(1);
	}
	celula *aux = *lista;
	while(aux != NULL){
		printf("%c\n", aux->info);
		aux = aux->prox;
	}
}

int main(){
	
	celula *ptrlista;
	inicializar(&ptrlista);

	
	inserir(&ptrlista, 'f');
	inserir(&ptrlista, 'u');
	inserir(&ptrlista, 'c');
	inserir(&ptrlista, 'k');

	pesquisa(&ptrlista, 'c');

	imprimir(&ptrlista);

}