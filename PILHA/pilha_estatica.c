// ##########################################
// #                                        #
// #   IMPLEMENTADO POR VICTOR ALCANTARA    #
// #  https://github.com/victoralcantara75  #
// #              15/02/2019                #
// #                                        #
// ##########################################

#include <stdio.h>
#define TAM 10

typedef struct sPilha{
    int info[TAM];
    int topo;
}pilha;

void inicializar(pilha *p){
    p->topo = -1;
}

int vazia(pilha *p){
    if(p->topo == -1)
        return 1;
    return 0;
}

int cheia(pilha *p){
    if(p->topo == TAM-1)
        return 1;
    return 0;
}

int push(pilha *p, int elem){
    if(cheia(p)){
        printf("pilha cheia!\n");
        return 0;
    }

    p->topo++;
    p->info[p->topo] = elem;
    return 1;
}

int pop(pilha *p){
    if(vazia(p)){
        printf("pilha vazia!\n");
        return 0;
    }
    p->topo--;
    return 1;
}

void imprimirNaoClassico(pilha *p){
    for(int i=0; i<p->topo; i++)
        printf("%d ", p->info[i]);

    printf("\n");
}

int main(){

    pilha p;
    inicializar(&p);

    for(int i=0; i<10; i++){
        push(&p, i);
    }

    for(int i=0; i<7; i++){
        pop(&p);  
    }
    imprimirNaoClassico(&p);
    return 0;
}