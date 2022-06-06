#include <stdio.h>
#define TAM 10

typedef struct sPilha{
    int info[TAM];
    int topo;
}pilha;

void inicializar(pilha *p){
    p->topo = -1;
}

int pilha_vazia(pilha *p){
    if(p->topo == -1)
        return 1;
    return 0;
}

int pilha_cheia(pilha *p){
    if(p->topo == TAM-1)
        return 1;
    return 0;
}

int push(pilha *p, int elem){
    if(pilha_cheia(p)){
        printf("pilha cheia!\n");
        return 0;
    }

    p->topo++;
    p->info[p->topo] = elem;
    return 1;
}

int pop(pilha *p){
    if(pilha_vazia(p)){
        printf("pilha vazia!\n");
        return 0;
    }
    p->topo--;
    return 1;
}

void imprimir_topo(pilha p) {
    if(p.topo == -1){
        printf("pilha vazia!\n");
    }

    printf("primeiro elemento: %d\n", p.info[p.topo]);
}

void imprimir_classico(pilha *p){
    while(!pilha_vazia(p)) {
        printf("%d ", p->info[p->topo]);
        pop(p);
    }
    printf("\n");
}