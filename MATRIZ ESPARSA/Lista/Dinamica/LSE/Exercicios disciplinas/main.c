#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

void imprimirMenu() {
	printf("1 - Inserir materia\n");
	printf("2 - Remover determinado materia\n");
	printf("3 - Exibir todas as materias\n");
	printf("4 - Exibir todas as materias de Sistemas\n");
	printf("5 - Sair do programa\n");
}

int main(){
	
	celula *ptrlista = criarCelula();
	inicializaLista(&ptrlista);
	int opcao;
	disciplina d;

	do {
		imprimirMenu();
		scanf("%d", &opcao);

		switch(opcao) {
			case 1:
				printf("Digite o codigo da disciplina: ");
                fflush(stdin);
                scanf("%s", d.codigo);
                printf("Digite o nome da disciplina: ");
                fflush(stdin);
                scanf("%s", d.nome);
                printf("Digite os creditos da disciplina: ");
                scanf("%d", &d.creditos);
                printf("Digite a carga horaria da disciplina: ");
                scanf("%d", &d.carga_horaria);
				inserir(&ptrlista, d);
			break;
			case 2:
                printf("Digite o codigo da disciplina: ");
                scanf("%s", d.codigo);
				remover(&ptrlista, d.codigo);
			break;
			case 3:
                imprimirLista(ptrlista);
			break;
			case 4:
                imprimirListaSIN(ptrlista);
			break;
		}
	}while(opcao < 5);

	free(ptrlista);
	
	return 0;
}