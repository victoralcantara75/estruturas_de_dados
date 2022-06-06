#include <stdio.h>
#include "BBT_DequeDinamico.c"

void imprimirMenu() {
    printf("0 - Sair \n");
	printf("1 - Inserir no inicio \n");
	printf("2 - Remover no inicio \n");
    printf("3 - Inserir no final \n");
	printf("4 - Remover no final \n");
	printf("5 - Imprimir classica\n");
	printf("6 - Imprimir nao classica\n");
}

int main(){

    int opcao;
    int n;
    DEQUE d;
    inicializar(&d);

    do
    {
        imprimirMenu();
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                printf("Qual numero que deseja inserir? \n");
                scanf("%d", &n);
                inserirInicio(&d, n);
                break;
            case 2:
                removerInicio(&d);
                break;
            case 3:
                printf("Qual numero que deseja inserir? \n");
                scanf("%d", &n);
                inserirFinal(&d, n);
                break;
            case 4:
                removerFinal(&d);
                break;
            case 5:
                imprimirClassico(&d);
                break;
            case 6:
                imprimirNaoClassico(&d);
                break;
        }
    } while (opcao != 0);
    

    return 0;
}