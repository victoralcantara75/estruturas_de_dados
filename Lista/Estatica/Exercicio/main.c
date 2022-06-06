#include <stdio.h>
#include "BBT_ListaEstatica.c"


int main(){
	
	lista l;
	alunos elemento;
	int escolha, matricula;
	
	inicializar(&l);
	
	do{
		escolha = menu();
		switch(escolha)
		{
		case 1:
			elemento = dadosAluno();
			inserirPosicaoK(&l, elemento, 1); //SEMPRE NA PRIMEIRA POSICAO
			break;
		case 2:
			printf("Matricula a pesquisar:");
			scanf("%d", &matricula);
			int posicao = pesquisarAluno(&l, matricula);
			if(posicao != -1)
				printf("\nPosicao do aluno na lista: %d\n", posicao);
			break;
		case 3:
			removerPosicaoK(&l, l.ultimoIndice+1); //SEMPRE NA ULTIMA POSICAO
			break;
		case 4:
			calcularMedia(&l);
			break;
		case 5:
			printf("\n\n");
			imprimir(&l);
			break;
		case 0:
			break;
		default:
			break;
		}
		
	}while(escolha != 0);
	
	
	return 0;
}