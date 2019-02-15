// ##########################################
// #                                        #
// #   IMPLEMENTADO POR VICTOR ALCANTARA    #
// #  https://github.com/victoralcantara75  #
// #              15/02/2019                #
// #                                        #
// ##########################################

#include <stdio.h>
#define TAM 10

typedef struct sDeque{
    int info[TAM];
    int inicio, fim;
}deque;

int inicializar(deque *deque){
    deque->inicio = 0;
    deque->fim = 0;
}

int vazio(deque *deque){
    if (deque->inicio == deque->fim)
        return 1;
    return 0;
}

int cheio(deque *deque){
    if ((deque->fim+1)%TAM == deque->inicio)
        return 1;
    return 0;
}

int inserirInicio(deque *deque, int elemento){
    if (cheio(deque))
        return 0;
    
    if(deque->inicio == 0)
        deque->inicio = TAM-1;
    else
        deque->inicio--;

    deque->info[deque->inicio] = elemento;
}

int removerInicio(deque *deque){
    if(vazio(deque))
        return 0;

    deque->inicio = (deque->inicio+1)%TAM;
}

int inserirFinal(deque *deque, int elemento){
    if (cheio(deque))
        return 0;
    
    deque->info[deque->fim] = elemento;
    deque->fim = (deque->fim+1)%TAM;
}

int removerFinal(deque *deque){
    if(vazio(deque))
        return 0;

    if(deque->fim == 0)
        deque->fim = TAM-1;
    else
        deque->fim--;        
}

void imprimir(deque *deque){
    int aux = deque->inicio;

    while (aux != deque->fim)
    {
        printf("%d ", deque->info[aux]);
        aux = (aux+1)%TAM;
    }
    printf("\n");
}

int main(){

    deque d;
    inicializar(&d);

    inserirFinal(&d, 8);
    inserirFinal(&d, 2);
    inserirInicio(&d, 5);
    inserirInicio(&d, 1);
    imprimir(&d);
    removerInicio(&d);
    removerFinal(&d);
    imprimir(&d);

    return 0;
}