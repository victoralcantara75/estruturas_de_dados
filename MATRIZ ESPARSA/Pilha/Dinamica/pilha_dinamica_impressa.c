// ##########################################
// #                                        #
// #   IMPLEMENTADO POR VICTOR ALCANTARA    #
// #  https://github.com/victoralcantara75  #
// #              15/02/2019                #
// #                                        #
// ##########################################

#include <stdio.h>
#include <stdlib.h>

typedef struct sCell{
    int info;
    struct sCell *prox;
}celula;

typedef struct sPilha{
    celula *ptrtopo;
    int tamanho;
}pilha;

void* criarCelula(){
    return (celula*)malloc(sizeof(celula));
}

void inicializar(pilha *p){
    p->ptrtopo = NULL;
    p->tamanho = 0;
}

int vazia(pilha *p){
    if(p->ptrtopo == NULL)
        return 1;
    return 0;
}

int push(pilha *p, int elem){
    
    celula *no = criarCelula();
    no->info = elem;

    no->prox = p->ptrtopo;
    p->ptrtopo = no;
    p->tamanho++;

    return 1;
}

int pop(pilha *p){
    if(vazia(p))
    {
        printf("não há elementos para desempilhar\n");
        return 0;
    }
    
    celula *aux = p->ptrtopo;
    p->ptrtopo = p->ptrtopo->prox;
    free(aux);
}

void imprimir(pilha *p){
    
    printf("\n");

    celula *aux = p->ptrtopo;
    while(aux != NULL)
    {
        printf("-------\n");
        printf("|  %d  |\n", aux->info);
        printf("-------\n");
        aux = aux->prox;
    }

}

int main(){
    
    pilha p;
    int elemento, escolha;
    inicializar(&p);
    
    
    do
	{
		printf("1 - Empilhar\n");
		printf("2 - Desempilhar\n");
		printf("3 - Sair\n");

		scanf("%d", &escolha);

		switch(escolha){
			case 1:
				printf("Digite o elemento para ser inserido: ");
				scanf("%d", &elemento);
				push(&p, elemento);
				break;

			case 2:
				pop(&p);
				break;

			case 3: 
				imprimir(&p);
				break;
		}

		printf("\e[H\e[2J");
		imprimir(&p);

	} while (escolha != 3);

    while(!vazia(&p))
    {   
        printf("Limpando memoria!\n");
        pop(&p);
    }

    return 0;
}