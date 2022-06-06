#include <stdio.h>
#include <stdlib.h>

typedef struct sCell{
    int info;
    struct sCell *next, *prev;
}celula;

typedef struct sDeque{
    celula *inicio, *final;
}DEQUE;

void* criarCelula(){
    return (celula*)malloc(sizeof(celula));
}

void inicializar(DEQUE *d){
    d->final = NULL;
    d->inicio = NULL;
}

int vazio(DEQUE *d){
    if(d->inicio == NULL && d->final == NULL)
        return 1;
    return 0;
}

int inserirInicio(DEQUE *d, int n){
    
    celula *no = criarCelula();

    no->info = n;
    if (vazio(d)){
        no->prev = NULL;
        no->next = NULL;
        d->inicio = no;
        d->final = no;
        return 1;
    }

    no->prev = NULL;
    no->next = d->inicio;
    d->inicio->prev = no;
    d->inicio = no;
    return 1;
}

int removerInicio(DEQUE *d){
    if(vazio(d))
        return 0;

    celula *aux = d->inicio;
    d->inicio = aux->next;
    aux->next->prev = NULL;
    free(aux);
    return 1;
}

int inserirFinal(DEQUE *d, int n){
    
    celula *no = criarCelula();
    no->info = n;
    if (vazio(d)){
        no->prev = NULL;
        no->next = NULL;
        d->inicio = no;
        d->final = no;
        return 1;
    }
       
    d->final->next = no;
    no->prev = d->final;
    no->next = NULL;
    d->final = no;
    return 1;
}

int removerFinal(DEQUE *d){
    if(vazio(d))
        return 0;

    celula *aux = d->final;
    aux->prev->next = NULL;
    d->final = aux->prev;
    free(aux);
	
	return 1;   
}

void imprimirClassico(DEQUE *d){

	if(vazio(d)){
        printf("d vazio...");
        return;
    }

    while (!vazio(d))
    {
        printf("%d ", d->inicio->info);
        removerInicio(d);
    }
    printf("\n ");
}

void imprimirNaoClassico(DEQUE *d){

	if(vazio(d)){
        printf("d Vazio...");
        return;
    }

    celula *aux = d->inicio;

    while (aux != NULL)
    {
        printf("%d ", aux->info);
        aux = aux->next;
    }
    printf("\n ");
}
