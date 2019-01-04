#include <stdio.h>
#include <stdlib.h>

typedef struct sCell{
	int info;
	struct sCell *dir;
	struct sCell *esq;
}celula;

typedef struct sArv{
	celula *raiz;	
}arvore;

void inicializar (celula *raiz){
	raiz = NULL;
}

celula *criarCelula(){
	return (celula*)malloc(sizeof(celula));
	
}

int vazia(celula *raiz){
	if (raiz == NULL)
		return 1;
	return 0;	
}

void visita(celula *raiz){
	printf("%d \n", raiz->info);	
}

void preordem (celula *raiz){
	
	if(!vazia(raiz))
		visita(raiz);
		preordem(raiz->esq);
		preordem(raiz->dir);
}

void ordem(celula *raiz){
	
	if(!vazia(raiz)){
		ordem(raiz->esq);
		visita(raiz);
		ordem(raiz->dir);
	}
}

void posordem (celula *raiz){
	
	if(!vazia(raiz))
		posordem(raiz->dir);
		posordem(raiz->esq);
		visita(raiz);
}

void inserir(celula *raiz, int elemento){
	
	if (raiz == NULL)
	{
		system("pause");
		celula *no = criarCelula();
		no->info = elemento;
	
		raiz = no;
		no->esq = NULL;
		no->dir = NULL;
	}else
	{
		if (elemento < raiz->info)	
			inserir(raiz->esq, elemento);
		else
		inserir(raiz->dir, elemento);
	}
		
}

celula *pesquisar(celula *raiz, int elemento){
	
	if (vazia(raiz))
		return NULL;
		
	if (raiz->info == elemento)
		return raiz;
		
	else 
	{
		if(raiz->info < elemento)
			pesquisar(raiz->esq, elemento);
		else
			pesquisar(raiz->dir, elemento);	
	}
}

celula *maiorElemento(celula *raiz){
	if (raiz->dir != NULL)
		maiorElemento(raiz->dir);
	else
	{
		celula *aux = raiz;
		if (raiz->esq != NULL)
			raiz = raiz->esq;
		else
			raiz = NULL;	
		return aux;	
	}	
}

void remover(celula *raiz, int elemento){
	
	if (vazia(raiz))
		printf("arvore vazia"); return;
	
	//ACHANDO O ELEMENTO
	if(raiz->info < elemento)
		remover(raiz->esq, elemento);
	else if (raiz->info > elemento)
		remover(raiz->dir, elemento);
	
	//ELEMENTO ACHADO 
	else 
	{
		celula *aux = raiz;
		if (raiz->esq == NULL && raiz->dir == NULL) //VERIFICANDO SE O ELEMENTO É FOLHA - CASO 1
		{
			free(aux);
			raiz = NULL;
		}
		
		else 										// VERIFICANDO SE O ELEMENTO SÓ TEM 1 SUBARVORE - CASO 2
		{
			if (raiz->esq == NULL)						
			{
				raiz = raiz->dir;
				free(aux);	
			}
			if (raiz->dir == NULL)
			{
				raiz = raiz->esq;
				free(aux);	
			}
			
			else
			{
				aux = maiorElemento(raiz->esq);
				aux->esq = raiz->esq;
				aux->dir = raiz->dir;
				free(raiz);
				raiz = aux;
			}
		}
	}	
}



int main(){
	
	arvore arv;
	inicializar(arv.raiz);
	
	inserir(arv.raiz, 8);
	inserir(arv.raiz, 0);
	inserir(arv.raiz, 87);
	
	ordem(arv.raiz);
	
	return 0;
}