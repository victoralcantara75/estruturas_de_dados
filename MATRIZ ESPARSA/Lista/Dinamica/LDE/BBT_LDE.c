#include<stdio.h>
#include<stdlib.h>

typedef struct sCell
{
	float info;
	struct sCell *esq;
	struct sCell *dir;
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

void inserir_inicio(celula **lista, float elemento){
	
	celula *no = criarCelula();
	if(no!=NULL){
	  no->info= elemento;
	  no->esq= NULL; 
	  no->dir= (*lista);
	
      if(!listaVazia(lista))
        (*lista)->esq= no;
        (*lista)= no;
	}else {
	  printf("Erro na Alocação");
	  exit(1);
	}
}

void imprimirListaInversa(celula **lista){
    printf("Lista Inversa: ");
	celula *aux = (*lista);
	
	while(aux->dir != NULL){
		aux = aux->dir;
	}
	while (aux != NULL){
		printf("%f ", aux->info);
		aux = aux->esq;
	}
    printf("\n");
}

void imprimir(celula **lista){

	
	celula *aux = (*lista);
	
	while(aux != NULL){
		printf("%f ", aux->info);
		aux = aux->dir;
	}

    printf("\n");
}


void soma(celula **lista){
	
	if(listaVazia(lista)){
		printf("Lista vazia\n");
		return;
	}
	
	
    printf("Soma: ");
    float soma = 0;
    
	celula *aux = (*lista);
	while (aux != NULL){
		soma += aux->info;
		aux = aux->dir;
	}
	
    printf("%f \n", soma);
}

void inserir_fim(celula **lista, int elemento){
	 
	celula *no = criarCelula();
	celula *aux= *lista;
	if(no!=NULL){
	  no->info= elemento;
	  no->dir= NULL;
	  no->esq= NULL;
	
	  if(listaVazia(lista)){
	  (*lista) = no;
	  }else {
	  while(aux->dir != NULL){
		  aux = aux->dir;
	  }
	  aux->dir= no;
	  no->esq= aux;
	  }
    }
	else {
	  printf("Erro na Alocação");
	  exit(1);
    } 
}

void remover_inicio(celula **lista){
	
	 celula *no;
	 no = *lista;
	 
	if(!listaVazia(lista)){
	  (*lista)= no->dir;
	  (*lista)->esq = NULL;
	  free(no); // desalocando
	}else {
	  printf("Erro na alocação");
	  exit(1);
	}
}

void remover_final(celula **lista){
	celula *aux = (*lista);
	
	if(listaVazia(lista)){
	  return ;
	}
	while(aux->dir!= NULL){
	  aux = aux->dir;
	}
	(aux->esq)->dir = NULL;
	free(aux);
	
}

void remover_k(celula **lista){
	if(listaVazia(lista)){
	  return ;
	}
	
	float k;
	printf("Digite o elemento que quer remover: ");
	scanf("%f", &k);
	
	celula *aux = (*lista);
	
	while (aux->info != k && aux != NULL){
		aux = aux->dir;
	}
	
	if(aux == NULL){
		printf("Elemento nao encontrado!");
		return;
	}
	
	if(aux->esq != NULL)
		aux->esq->dir = aux->dir;
	else 
		(*lista) = aux->dir;
	if(aux->dir != NULL)
		aux->dir->esq = aux->esq;
	
	free(aux);
	
	return;
	
}
	
	
	
	
	
	
	