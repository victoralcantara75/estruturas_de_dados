#include <stdio.h>
#include <stdlib.h>

typedef struct sPrato {
    char cor[10], tipo[20];
    float tamanho;
}prato;

typedef struct sCell{
	prato info;
	struct sCell *prox;
}celula;


void inicializar(celula **pilha){
    *pilha = NULL;
}

int vazia(celula **pilha){
    if((*pilha) == NULL)
        return 1;
    return 0;
}

celula *criarNo(){
	return (celula*)malloc(sizeof(celula));
}

int push(celula **pilha, prato elem){

	celula* no = criarNo();
	if(no == NULL)
		return 0;
	
	no->info = elem;
	no->prox = *pilha;
	*pilha = no;
	
    return 1;
}

int pop(celula **pilha){
	
    if(vazia(pilha)){
        printf("Nao ha elementos para remover\n");
        return 0;
    }
    celula *aux = *pilha;
    *pilha = (*pilha)->prox;
    free(aux);
    
    return 1;
}

void imprimir_topo(celula **pilha) {
    if(vazia(pilha)){
        printf("pilha vazia!\n");
    }

    printf("tipo: %s\n", (*pilha)->info.tipo);
    printf("cor: %s\n", (*pilha)->info.cor);
    printf("tamanho: %0.2f\n", (*pilha)->info.tamanho);

}

void imprimir_classico(celula **pilha){
    while(!vazia(pilha)) {
        printf("TOPO:\n");
        printf("tipo: %s\n", (*pilha)->info.tipo);
        printf("cor: %s\n", (*pilha)->info.cor);
        printf("tamanho: %0.2f\n",(*pilha)->info.tamanho);
        pop(pilha);
    }
    printf("\n");
}