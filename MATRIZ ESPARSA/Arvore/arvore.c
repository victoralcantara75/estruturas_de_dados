#include <stdio.h>
#include <stdlib.h>

typedef struct sCell{
	int info;
	struct sCell *dir, *esq;
}celula;

void inicializar(celula **ptrRaiz){
	*ptrRaiz = NULL;
}

celula *criarNo(){
	return (celula*)malloc(sizeof(celula));
}

int vazia(celula **no){
	if (*no == NULL)
		return 1;
	return 0;
}


int inserir(celula **ptrRaiz, int elemento){
	if (*ptrRaiz == NULL){
		celula *novoNo = criarNo();
		novoNo->info = elemento;
		novoNo->esq = NULL;
		novoNo->dir = NULL;
		*ptrRaiz = novoNo;
		return 1;
	}
	
	if(elemento > (*ptrRaiz)->info)
		return inserir(&(*ptrRaiz)->dir, elemento);
	return inserir(&(*ptrRaiz)->esq, elemento);
}

int inserirIterativa(celula **ptrRaiz, int elemento){
	celula *aux = *ptrRaiz;
	celula *ant = NULL;
	
	celula *novoNo = criarNo();
	novoNo->info = elemento;
	novoNo->esq = NULL;
	novoNo->dir = NULL;
	
	if(vazia(ptrRaiz)){
		*ptrRaiz = novoNo;
		return 1;
	}
	
	while(aux != NULL){
		ant = aux;
		if(elemento > aux->info)
			aux = aux->dir;
		else 
			aux = aux->esq;
	}
	
	if(elemento > ant->info)
		ant->dir = novoNo;
	else 
		ant->esq = novoNo;
	
	return 1;
}

void imprimir(celula **no){
	printf("%d ", (*no)->info);
}

void emOrdem(celula **ptrRaiz){
	if (*ptrRaiz != NULL){
		emOrdem(&(*ptrRaiz)->esq);
		imprimir(ptrRaiz);
		emOrdem(&(*ptrRaiz)->dir);
	}
	
}

int contaNo(celula **ptrRaiz){
	if(*ptrRaiz == NULL)
		return 0;
	
	return 1 + contaNo(&(*ptrRaiz)->esq) + contaNo(&(*ptrRaiz)->dir);
}

int altura(celula **ptrRaiz){
	if(*ptrRaiz == NULL)
		return 0;
	
	int altE = altura(&(*ptrRaiz)->esq);
	int altD = altura(&(*ptrRaiz)->dir);
	if(altE > altD)
		return 1+ altE;
	else 
		return 1+ altD;
}

int contaFolha(celula **ptrRaiz){
	if ((*ptrRaiz)-> dir == NULL && (*ptrRaiz)-> esq == NULL)
		return 1;
	return contaFolha(&(*ptrRaiz)->esq) + contaFolha(&(*ptrRaiz)->dir);
}

celula* pesquisar(celula **ptrRaiz, int elemento){
	if (vazia(&(*ptrRaiz)))
		return NULL;
	
	if ((*ptrRaiz)->info == elemento)
		return *ptrRaiz;
	if (elemento > (*ptrRaiz)->info)
		return pesquisar(&(*ptrRaiz)->dir, elemento);
	else 
		return pesquisar(&(*ptrRaiz)->esq, elemento);
}

celula *maiorElemento(celula **ptrRaiz){
	if((*ptrRaiz)->dir != NULL)
		maiorElemento(&(*ptrRaiz)->dir);
	
	celula *aux = (*ptrRaiz);
	if((*ptrRaiz)->esq != NULL)
		(*ptrRaiz) = (*ptrRaiz)->esq;
	else 
		(*ptrRaiz) = NULL;
	
	return aux;
}

int removerIterativo(celula **ptrRaiz, int elemento){
	
	if (vazia(&(*ptrRaiz)))
		return 1;
	
	celula *rem = (*ptrRaiz);
	celula *remPai = NULL;
	
	while(rem->info != elemento){
		remPai = rem;
		if(elemento > rem->info)
			rem = rem->dir;
		else 
			rem = rem->esq;
	}
	
	if(rem->esq == NULL && rem->dir == NULL){
		if((remPai->esq) == rem)
			remPai->esq = NULL;
		else 
			remPai->dir = NULL;
 		free(rem);
	}
	else{
		if(rem->esq == NULL){
			if((remPai->esq) == rem)
				remPai->esq = rem->dir;
			else 
				remPai->dir = rem->dir;
			
			free(rem);
		}
		if(rem->dir == NULL){
			if((remPai->esq) == rem)
				remPai->esq = rem->esq;
			else 
				remPai->dir = rem->esq;
			
			free(rem);
		}
		else
		{
			celula *aux = maiorElemento(&rem->esq);
			rem->info = aux->info;
			free(aux);
		}
		
	}
	
	return 1;
}

int remover(celula **ptrRaiz, int elemento){
	if (vazia(&(*ptrRaiz)))
		return 1;
	
	//ACHANDO O ELEMENTO
	if(elemento > (*ptrRaiz)->info)
		remover(&(*ptrRaiz)->dir, elemento);
	else if (elemento < (*ptrRaiz)->info)
		remover(&(*ptrRaiz)->esq, elemento);
	
	//ELEMENTO ACHADO
	else
	{
		celula *aux = (*ptrRaiz);
		
		//CASO 1 - ELEMENTO � FOLHA
		if((*ptrRaiz)->esq == NULL && (*ptrRaiz)->dir == NULL)
			(*ptrRaiz) = NULL;
		
		else
		{
			//CASO 2 - S� TEM UMA SUBARVROE
			if((*ptrRaiz)->esq == NULL)
				(*ptrRaiz) = (*ptrRaiz)->dir;

			if((*ptrRaiz)->dir == NULL)
				(*ptrRaiz) = (*ptrRaiz)->esq;

			//CASO 3 - TEM DUAS SUBARVORES
			else
			{
				aux = maiorElemento(&(*ptrRaiz)->esq);
				(*ptrRaiz)->info = aux->info;
			}
		}
		
		free(aux);
	}
	
	return 1;
}

celula *maiorElementoIter(celula **ptrRaiz){
	celula *aux = (*ptrRaiz);
	celula *pai = NULL;
	
	while(aux->dir != NULL){
		pai = aux;                   
		aux = aux->dir;
	}
	
	if(aux->esq != NULL)
		pai->dir = aux->esq;
	else
		pai->dir = NULL;
	
	return aux;
}


int main(){
	
	celula *ptrRaiz;
	inicializar(&ptrRaiz);
	
	inserir(&ptrRaiz, 10);
	inserir(&ptrRaiz, 5);
	inserir(&ptrRaiz, 4);
	inserir(&ptrRaiz, 7);
	inserir(&ptrRaiz, 15);
	inserir(&ptrRaiz, 14);
	inserir(&ptrRaiz, 16);

	removerIterativo(&ptrRaiz, 5);
	emOrdem(&ptrRaiz);
	printf("\n");
	remover(&ptrRaiz, 10);
	emOrdem(&ptrRaiz);
	
	
	
	printf("\nnos - %d",contaNo(&ptrRaiz));
	printf("\naltura - %d",altura(&ptrRaiz));
	printf("\nfolhas - %d",contaFolha(&ptrRaiz));
	
	return 0;
}