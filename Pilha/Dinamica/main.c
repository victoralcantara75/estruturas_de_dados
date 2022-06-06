#include<stdio.h>
#include"BBT_PilhaEstatica.c"

void imprimir_menu() {
	printf("1 - PUSH\n");
	printf("2 - POP\n");
	printf("3 - RETORNAR O TOPO\n");
	printf("4 - IMPRIMIR CLASSICO\n");
	printf("5 - SAIR\n");
}

int main(){

    celula *pilha;
    int opcao;
	prato valor;

	do {
		imprimir_menu();
		scanf("%d", &opcao);

		switch(opcao) {
			case 1:
				printf("Digite a cor: ");
				fflush(stdin);
				scanf("%s", valor.cor);
                printf("Digite o tipo: ");
				fflush(stdin);
				scanf("%s", valor.tipo);
                printf("Digite o tamanho: ");
				scanf("%f", &valor.tamanho);
				push(&pilha, valor);
			break;
			case 2:
				pop(&pilha);
			break;
			case 3:
				imprimir_topo(&pilha);
			break;
			case 4:
				imprimir_classico(&pilha);
		}
	}while(opcao < 5);

    return 0;
}