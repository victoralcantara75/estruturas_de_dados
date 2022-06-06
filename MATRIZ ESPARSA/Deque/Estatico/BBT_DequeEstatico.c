#include <stdio.h>
#define TAM 10

 typedef struct sDeque{
    int info[TAM];
    int inicio, fim;
}DEQUE;

int inicializar(DEQUE *d){
    d->inicio = 0;
    d->fim = 0;
    return 1;
}

int vazio(DEQUE *d){
    if (d->inicio == d->fim)
        return 1;
    return 0;
}

int cheio(DEQUE *d){
    if ((d->fim+1)%TAM == d->inicio)
        return 1;
    return 0;
}

int inserirInicio(DEQUE *d, int n){
    if (cheio(d))
        return 0;
    
    if(d->inicio == 0)
        d->inicio = TAM-1;
    else
        d->inicio--;

    d->info[d->inicio] = n;
    
    return 1;
}

int removerInicio(DEQUE *d){
    if(vazio(d))
        return 0;

    d->inicio = (d->inicio+1)%TAM;
    
    return 1;
}

int inserirFinal(DEQUE *d, int n){
    if (cheio(d)){
        printf("deque cheio!");
        return 0;
    }
       
    d->info[d->fim] = n;
    d->fim = (d->fim+1)%TAM;
    return 1;
}

int removerFinal(DEQUE *d){
    if(vazio(d))
        return 0;

    if(d->fim == 0)
        d->fim = TAM-1;
    else
        d->fim--;
	
	return 1;   
}

void imprimirClassico(DEQUE *d){

	if(vazio(d)){
        printf("deque vazio");
        return;
    }

    while (!vazio(d))
    {
        printf("%d ", d->info[d->inicio]);
        removerInicio(d);
    }
    printf("\n ");
}

void imprimirNaoClassico(DEQUE *d){

	if(vazio(d)){
        printf("deque vazio");
        return;
    }

    int aux = d->inicio;

    while (aux != d->fim)
    {
        printf("%d ", d->info[aux]);
        aux = (aux+1)%TAM;
    }
    printf("\n ");
}