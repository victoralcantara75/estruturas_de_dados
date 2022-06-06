#include <stdio.h>
#include "BBT_ListaEstatica.c"


int main(){
	
	lista l;
	int escolha, elemento, posicao;
	
	inicializar(&l);
	
	do{
		escolha = menu();
		switch(escolha)
		{
		case 1:
			printf("Digite o numero: ");
			scanf("%d", &elemento);
			inserirNoFinal(&l, elemento);
			break;
		case 2:
			printf("Digite o numero: ");
			scanf("%d", &elemento);
			printf("Digite a posicao: ");
			scanf("%d", &posicao);
			inserirPosicaoK(&l, elemento, posicao);
			break;
		case 3:
			printf("Digite a posicao: ");
			scanf("%d", &posicao);
			removerPosicaoK(&l, posicao);
			break;
		case 4:
			printf("Digite o numero: ");
			scanf("%d", &elemento);
			printf("Digite a posicao: ");
			scanf("%d", &posicao);
			modificarPosicaoK(&l, elemento, posicao);
			break;
		case 0:
			break;
		default:
			break;
		}
		printf("\n\n");
		imprimir(&l);
	}while(escolha != 0);
	
	
	return 0;
}