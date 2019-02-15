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
    while(!vazia(p)){
        printf("%d ", p->ptrtopo->info);
        pop(p);
    }
    printf("\n");
}

int main(){
    
    pilha p;
    inicializar(&p);
    vazia(&p);

    push(&p, 5);
    push(&p, 8);

    imprimir(&p);
    return 0;
}