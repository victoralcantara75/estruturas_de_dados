#include <stdio.h>
#include "BBT_FilaEstatica.c"
 
 void imprimirMenu() {
	printf("1 - Inserir \n");
	printf("2 - Remover \n");
	printf("3 - Imprimir classica\n");
	printf("4 - Imprimir nao classica\n");
	printf("5 - Sair\n");
}
 
 int main(){
	 
	fila fila;
	inicializar(&fila);
	
	int opcao;
	int valor;

	do {
		imprimirMenu();
		scanf("%d", &opcao);

		switch(opcao) {
			case 1:
				printf("Digite o valor: ");
				scanf("%d", &valor);
				enfileirar(&fila, valor);
			break;
			case 2:
				desenfileirar(&fila);
			break;
			case 3:
				imprimir(&fila);
			break;
			case 4:
				imprimirNaoClassica(&fila);
		}
	}while(opcao < 5);


	 return 0;
 }