#include<stdio.h>
#include"BBT_PilhaDinamica.c"

void imprimirMenu() {
	printf("1 - PUSH\n");
	printf("2 - POP\n");
	printf("3 - RETORNAR TOPO\n");
	printf("4 - IMPRIMIR CLASSICO\n");
	printf("5 - SAIR\n");
}

int main(){

    pilha a;
    inicializar(&a);
    int opcao;
	int valor;

	do {
		imprimirMenu();
		scanf("%d", &opcao);

		switch(opcao) {
			case 1:
				printf("Digite o valor: ");
				scanf("%d", &valor);
				push(&a, valor);
			break;
			case 2:
				pop(&a);
			break;
			case 3:
				imprimir_topo(a);
			break;
			case 4:
				imprimir_classico(&a);
		}
	}while(opcao < 5);

    return 0;
}