#include <stdio.h>
#include <string.h>
#define TAM 60
#define SEMANAS 2

typedef struct sAluno{
	char nome[20];
	int matricula;
	char turma;
	float notaQuiz[SEMANAS];
	float notaLista[SEMANAS];
	float notaParticipacao[SEMANAS];
}alunos;

typedef struct sLista{
	alunos lista[TAM];
	int ultimoIndice;
}lista;

void inicializar(lista *lista){
	(lista)->ultimoIndice = -1;
}

int cheia(lista *lista){
	if(lista->ultimoIndice + 1 == TAM)
		return 1;
	return 0;
}

int vazia(lista *lista){
	if (lista->ultimoIndice == -1)
		return 1;
	return 0;
}

int menu(){
	int escolha;
	printf("1 - cadastrar aluno\n");
	printf("2 - pesquisar por matricula \n");
	printf("3 - remover \n");
	printf("4 - calcular media \n");
	printf("5 - imprimir lista \n");
	printf("0 - sair\n");
	printf("Escolha: ");
	scanf("%d", &escolha);
	return escolha;
}

alunos dadosAluno(){
	alunos novoAluno;
	
	fflush(stdin);
	printf("---- CADASTRO ----\n ");
	printf("Nome: ");
	scanf("%s", &novoAluno.nome);
	
	printf("Matricula: ");
	scanf("%d", &novoAluno.matricula);

	printf("Turma (A/B): ");
	scanf(" %c", &novoAluno.turma);
	
	int i;
	for(i = 1; i <= SEMANAS; i++){
		printf("Nota do quiz | semana %d: ", i);
		scanf("%f", &novoAluno.notaQuiz[i-1]);
	}
	
	for(i = 1; i <= SEMANAS; i++){
		printf("Nota da lista | semana %d: ", i);
		scanf("%f", &novoAluno.notaLista[i-1]);
	}
	
	for(i = 1; i <= SEMANAS; i++){
		printf("Nota de participacao | semana %d: ", i);
		scanf("%f", &novoAluno.notaParticipacao[i-1]);
	}
	
	return novoAluno;
}

void imprimir(lista *lista){
	if(vazia(lista))
		return ;
	int i, j;
	for(i = 0; i <= lista->ultimoIndice; i++){
		printf("Nome: %s\n", lista->lista[i].nome);
		printf("Matricula: %d\n", lista->lista[i].matricula);
		printf("Turma: %c\n", lista->lista[i].turma);
		for (j = 0; j < SEMANAS ; j++){
			printf("Nota quiz semana %d: %.2f\n",j+1, lista->lista[i].notaQuiz[j]);
		}
		for (j = 0; j < SEMANAS ; j++){
			printf("Nota lista semana %d: %.2f\n",j+1, lista->lista[i].notaLista[j]);
		}
		for (j = 0; j < SEMANAS ; j++){
			printf("Nota participacao semana %d: %.2f\n",j+1, lista->lista[i].notaParticipacao[j]);
		}
		printf("\n");
	}
}

int pesquisarAluno(lista *lista, int matricula){
	int i;
	
	for(i = 0; i < TAM; i++){
		if ((lista)->lista[i].matricula == matricula)
			return i+1;
	}
	
	printf("Aluno nao encontrado\n");
	return -1;
}

int inserirNoFinal(lista *lista, alunos elemento){
	if(cheia(lista))
		return 0;
	
	lista->ultimoIndice++;
	lista->lista[lista->ultimoIndice] = elemento;
	return 1;
}

int inserirPosicaoK(lista *lista, alunos elemento, int posicao){
	
	if(cheia(lista) || posicao > TAM)
		return 0;
	
	posicao--;
	if(posicao > lista->ultimoIndice ){
		inserirNoFinal(lista, elemento);
		return 1;
	}
		
	int i;                          
	for(i = lista->ultimoIndice+1; i > posicao; i--){
		lista->lista[i] = lista->lista[i-1];
	}
	lista->lista[posicao] = elemento;
	lista->ultimoIndice++;

	return 1;
}

int removerPosicaoK(lista *lista, int posicao){
	if(vazia(lista))
		return 0;
	
	posicao--;
	int i;
	for(i = posicao; i <= lista->ultimoIndice; i++){
		lista->lista[i] = lista->lista[i+1];
	}
	lista->ultimoIndice--;
	return 1;
}

void calcularMedia(lista *lista){
	
	float somaQuizA = 0, somaQuizB = 0;
	float somaListA = 0, somaListB = 0;
	float somaPartA = 0, somaPartB = 0;
	int i, j, contA = 0, contB = 0;
	
	for (j = 0; j < SEMANAS; j++){
		for (i = 0; i <= lista->ultimoIndice; i++){
			if(lista->lista[i].turma == 'A'){
				contA++;
				somaQuizA += lista->lista[i].notaQuiz[j];
				somaListA += lista->lista[i].notaLista[j];
				somaPartA += lista->lista[i].notaParticipacao[j];
			}
			if(lista->lista[i].turma == 'B'){
				contB++;
				somaQuizB += lista->lista[i].notaQuiz[j];
				somaListB += lista->lista[i].notaLista[j];
				somaPartB += lista->lista[i].notaParticipacao[j];
			}
		}
	
		printf("Media da semana %d do quiz turma A: %.2f\n", j+1, somaQuizA / contA);
		printf("Media da semana %d do quiz turma B: %.2f\n", j+1, somaQuizB / contB);
		
		printf("Media da semana %d da lista turma A: %.2f\n", j+1, somaListA / contA);
		printf("Media da semana %d da lista turma B: %.2f\n", j+1, somaListB / contB);
		
		printf("Media da semana %d da participacao turma A: %.2f\n", j+1, somaPartA / contA);
		printf("Media da semana %d da participacao turma B: %.2f\n", j+1, somaPartB / contB);
		
		
	}
	
}                                   