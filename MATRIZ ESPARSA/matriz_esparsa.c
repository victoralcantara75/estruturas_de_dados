#include <stdio.h>
#include <stdlib.h>
#define TAML 4
#define TAMC 4

typedef struct sCell{
	int linha, coluna;
	int info;
	struct sCell *proxlin;
	struct sCell *proxcol;
}celula;

typedef struct sMat{
	celula *linha[TAML];
	celula *coluna[TAMC];
}matriz_esparsa;

celula *criarCelula(){
	return (celula*)malloc(sizeof(celula));
}

void inicializar(matriz_esparsa *matriz){
	int i;
	for ( i = 0; i < TAML; ++i)          //VAI EM TODAS AS LINHAS APONTANDO PRA NULL
		matriz->linha[i] = NULL;
	for ( i = 0; i < TAMC; ++i)
		matriz->coluna[i] = NULL;		//VAI EM TODAS AS COLUNAS APONTANDO PRA NULL

}

int vazia(matriz_esparsa *matriz){

	int i;
	for (int i = 0; i < TAML; ++i)
	{
		if (matriz->linha[i] != NULL)
			return 0;
	}
	return 1;
}

int inserirLinha(matriz_esparsa *matriz, celula *no, int lin, int col, int elemento){

	celula **lista = &matriz->linha[lin];          //CRIO UMA VARIAVEL LISTA, PARA FICAR MAIS INTUITIVO COM A LISTA JA CONHECIDA
	celula *aux = *lista;
	celula *ant;

	if (*lista == NULL)                            //NAO TEM ELEMENTOS NAQUELA LINHA -  equivalente à lista vazia
	{
		*lista = no;
		no->proxcol = NULL;
		return 1;
	}

	if (col < aux->coluna)						   //O ELEMENTO QUE QUERO INSERIR PERTENCE A UMA COLUNA ANTERIOR A PRIMEIRA JA INSERIDA - equivalente a inserir no inicio
	{
		no->proxcol = *lista;
		*lista = no;
		return 1;
	}

	while(aux!= NULL && aux->coluna <= col){       //PERCORRENDO A LISTA PRA ACHAR A POSICAO(COLUNA) QUE DEVE SER INSERIDO - equivalente a inserir na posicao K
		if (aux->coluna == col)					   //CASO JA EXISTA UM NO NAQUELA COORDENADA
		{
			aux->info = elemento;				   //SIMPLESMENTE SUBSTITUI O INFO
			return 1;
		}
		ant = aux;
		aux = aux->proxcol;
	}

	no->proxcol = ant->proxcol;
	ant->proxcol = no;
	return 1;

}

int inserirColuna(matriz_esparsa *matriz, celula *no, int lin, int col, int elemento){

	celula **lista = &matriz->coluna[col];
	celula *aux = *lista;
	celula *ant;

	if (*lista == NULL)
	{
		*lista = no;
		no->proxlin = NULL;
		return 1;
	}

	if (lin < aux->linha)
	{
		no->proxlin = *lista;
		*lista = no;
		return 1;
	}

	while(aux != NULL && aux->linha <= lin){
		if (aux->linha == lin)
		{
			aux->info = elemento;
			free(no);
			return 1;
		}
		ant = aux;
		aux = aux->proxlin;
	}

	no->proxlin = ant->proxlin;
	ant->proxlin = no;
	return 1;

}

int remover(matriz_esparsa *matriz, int lin, int col){
	celula *removida;
	celula *aux = matriz->linha[lin];

	while (aux->proxcol->coluna != col){
		aux = aux->proxcol;
	}
	removida = aux->proxcol;
	aux->proxcol = removida->proxcol;

	celula *aux2 = matriz->coluna[col];

	while (aux2->proxlin->linha != lin){
		aux2 = aux2->proxlin;
	}
	aux2->proxlin = removida->proxlin;
	free(removida);
	return 1;

}

int inserir(matriz_esparsa *matriz, int elemento, int lin, int col){

	lin = lin-1; 									//NA PROGRAMACAO OS INDICES COMECAM COM ZERO, MAS O USUARIO PARTE DO PRINCIPIO QUE A MATRIZ COMECA NO (1,1)
	col = col-1;

	if (elemento ==  0)
		return 0;

	celula *no = criarCelula();
	no->info = elemento;
	no->linha = lin;
	no->coluna = col;

	inserirLinha(matriz, no, lin, col, elemento);
	inserirColuna(matriz, no, lin, col, elemento);

	return 1;
}


void imprimir(matriz_esparsa *matriz){           //IMPRIME SOMENTE OS ELEMENTOS DA MATRIZ
	
	int i, j;
	celula *aux;
	for (i = 0; i < TAML; ++i)
	{
		aux = matriz->linha[i];

		while(aux != NULL){
			printf("%d ", aux->info);

			aux = aux->proxcol;
		}
		printf("\n");
	}

}

void imprimir2(matriz_esparsa *matriz)			//IMPRIME TODA A MATRIZ, COMPLETANDO COM 0 
{
	int i, j;
	celula *aux;
	for (int i = 0; i < TAML; ++i)
	{
		aux = matriz->linha[i];
		for (int j = 0; j < TAMC; ++j)
		{
			if (aux != NULL && aux->linha == i && aux->coluna == j)
			{
				printf("%d ",aux->info );
				aux = aux->proxcol;
			}
			else 
				printf("0 ");
		}
		printf("\n");
	}
}

int main(){
	
	matriz_esparsa matriz;
	inicializar(&matriz);

	inserir(&matriz, 1, 4, 4);
	inserir(&matriz, 1, 1, 1);
	inserir(&matriz, 1, 2, 2);
	inserir(&matriz, 1, 3, 3);
	inserir(&matriz, 2, 3, 3);
	inserir(&matriz, 2, 2, 4);
	remover(&matriz, 4, 4);

	//imprimir(&matriz);
	imprimir2(&matriz);

	return 0;
}








