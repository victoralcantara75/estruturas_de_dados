#include <stdio.h>
#include <stdlib.h>
#include "BBT_ListaDinamica2.c"

void imprimirMenu() {
	printf("1 - Inserir elemento\n");
	printf("2 - Remover primeiro elemento\n");
	printf("3 - Remover determinado elemento\n");
	printf("4 - Pesquisar elemento (mover para frente)\n");
	printf("5 - Pesquisar elemento (transposicao)\n");
	printf("6 - Exibir lista\n");
	printf("7 - Sair do programa\n");
}

int main(){
	
	celula *ptrlista = criarCelula();
	inicializaLista(&ptrlista);
	int opcao;
	char valor;

	do {
		imprimirMenu();
		scanf("%d", &opcao);

		switch(opcao) {
			case 1:
				printf("Digite o valor para inserir: ");
				fflush(stdin);
				scanf("%c", &valor);
				inserir(&ptrlista, valor);
			break;
			case 2:
				removerPrimeiro(&ptrlista);
			break;
			case 3:
				printf("Digite o valor para remover: ");
				fflush(stdin);
				scanf("%c", &valor);
				remover(&ptrlista, valor);
			break;
			case 4:
				printf("Digite o valor para pesquisar: ");
				fflush(stdin);
				scanf("%c", &valor);
				moverParaFrente(&ptrlista, valor);
			break;
			case 5:
				printf("Digite o valor para pesquisar: ");
				fflush(stdin);
				scanf("%c", &valor);
				transposicao(&ptrlista, valor);
			break;
			case 6:
				imprimirLista(ptrlista);
			break;
		}
	}while(opcao < 7);

	free(ptrlista);
	
	return 0;
}