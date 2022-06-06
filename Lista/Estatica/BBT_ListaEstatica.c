#include <stdio.h>
#define TAM 50

typedef struct sLista{
	int lista[TAM];
	int ultimoIndice;
}lista;

int menu(){
	int escolha;
	printf("1 - inserir final\n");
	printf("2 - inserir k\n");
	printf("3 - remover k\n");
	printf("4 - modificar k\n");
	printf("0 - sair\n");
	printf("Escolha: ");
	scanf("%d", &escolha);
	return escolha;
}

void inicializar(lista *lista){
	(lista)->ultimoIndice = -1;
}

int cheia(lista *lista){
	if(lista->ultimoIndice + 1 == TAM)
		return 1;
	return 0;
}

int vazia(lista *lista){
	if (lista->ultimoIndice == -1)
		return 1;
	return 0;
}

void imprimir(lista *lista){
	if(vazia(lista))
		return;
	
	int i;
	printf("[LISTA] ");
	for(i = 0; i <= lista->ultimoIndice; i++){

			printf("%d ", lista->lista[i]);
	}
	
	printf("\n\n");
}

int inserirNoFinal(lista *lista, int elemento){
	if(cheia(lista))
		return 0;
	
	lista->ultimoIndice++;
	lista->lista[lista->ultimoIndice] = elemento;
	return 1;
}

int inserirPosicaoK(lista *lista, int elemento, int posicao){
	
	if(cheia(lista) || posicao > TAM)
		return 0;
	
	posicao--;
	if(posicao > lista->ultimoIndice ){
		inserirNoFinal(lista, elemento);
		return 1;
	}
		
	int i;
	for(i = lista->ultimoIndice+1; i > posicao; i--){
		lista->lista[i] = lista->lista[i-1];
	}
	lista->lista[posicao] = elemento;
	lista->ultimoIndice++;

	return 1;
}

int removerPosicaoK(lista *lista, int posicao){
	if(vazia(lista))
		return 0;
	
	posicao--;
	int i;
	for(i = posicao; i <= lista->ultimoIndice; i++){
		lista->lista[i] = lista->lista[i+1];
	}
	lista->ultimoIndice--;
	return 1;
}

int modificarPosicaoK(lista *lista, int elemento, int posicao){
	posicao--;
	if(posicao > lista->ultimoIndice)
		return 0;
	
	lista->lista[posicao] = elemento;
	return 1;
}