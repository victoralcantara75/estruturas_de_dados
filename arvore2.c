#include <stdio.h>
#include <stdlib.h>

typedef struct sCell{
	int info;
	struct sCell *dir;
	struct sCell *esq;
}celula;

void inicializar (celula **raiz){
	*raiz = NULL;
}

celula *criarCelula(){
	return (celula*)malloc(sizeof(celula));
	
}

int vazia(celula **raiz){
	if (*raiz == NULL)
		return 1;
	return 0;	
}
void visita(celula **raiz){
	printf("%d \n", raiz->info);	
}

void ordem(celula **raiz){
	
	if(!vazia(*raiz)){
		ordem(*raiz->esq);
		visita(*raiz);
		ordem(*raiz->dir);
	}
}

/*void inserir(celula *raiz, int elemento){
	
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
	}*/
		
}int main(){
	
	celula *arv;
	inicializar(&arv);
	
	//inserir(&arv, 8);
	//inserir(&arv, 0);
	//inserir(&arv, 87);
	
	//ordem(&arv);
	
	return 0;
}