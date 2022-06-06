#include <stdio.h>
#include "BBT_LDE.c"


void imprimirMenu() {
	printf("1 - Inserir elemento no inicio da lista\n");
	printf("2 - Inserir elemento no final da lista \n");
	printf("3 - Remover elemento do inicio da lista\n");
	printf("4 - Remover derterminado elemento da lista\n");
	printf("5 - Remover do final da lista\n");
	printf("6 - Exibir os elementos da lista na ordem inversa\n");
	printf("7 - Exibir a soma de todos os elementos da lista\n");
	printf("8 - Sair do Programa\n");
	printf("\n");
}

int main(){
	
	celula *ptrlista = criarCelula();
	inicializaLista(&ptrlista);
	int opcao;
	float valor;

	do {
		imprimirMenu();
		scanf("%d", &opcao);

		switch(opcao) {
			case 1:
				printf("Digite o valor para inserir no inicio da lista: ");
				scanf("%f", &valor);
				inserir_inicio(&ptrlista, valor);
			break;
			
			case 2:
				printf("Digite o valor para inserir no final da lista: ");
				scanf("%f", &valor);
				inserir_fim(&ptrlista, valor);
			break;
			
			case 3:
				remover_inicio(&ptrlista);
			break;
		
			case 4:
				remover_k(&ptrlista);
			break;
		
			case 5:
				remover_final(&ptrlista);
			break;
			
			case 6:
				imprimirListaInversa(&ptrlista);
			break;
		
			case 7:
				soma(&ptrlista);
			break;
		}
	}while(opcao < 8);

	free(ptrlista);
	
	return 0;
}