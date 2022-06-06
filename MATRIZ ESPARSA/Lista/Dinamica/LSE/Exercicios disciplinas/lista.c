#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct sDisc
{
    char codigo[7];
    char nome[15];
    int creditos;
    int carga_horaria;
}disciplina;

typedef struct sCell
{
	disciplina info;
	struct sCell *prox;
}celula;

celula *criarCelula(){
	return (celula*)malloc(sizeof(celula));
}

void inicializaLista(celula **lista){
	(*lista) = NULL;
}

int listaVazia(celula **lista){
	if ((*lista) == NULL)
		return 1;
	return 0;
}

int inserir(celula **lista, disciplina elemento){
	
	celula *no = criarCelula();
	if(no == NULL) printf("Erro na alocacao");
	
	no->info = elemento;
	if(listaVazia(lista))
	{
		no->prox = NULL;
		(*lista) = no;
		return 1;
	}
	
	celula *aux = *lista;
	celula *ant;
	
    while ( aux != NULL && strcmp(aux->info.nome,elemento.nome) < 0){
		ant = aux;
		aux = aux->prox;
	}	
	no->prox = aux;
	
	if(aux == *lista) *lista = no;
	else ant->prox = no;
	
	return 1;
}

celula* remover(celula **lista, char codigo[7]){
	
	if(listaVazia(lista)){
		printf("lista vaziza");
		exit(1);
	}
	
	celula *aux = *lista;
    celula *ant;
	celula *q = criarCelula();
	
	while ( strcmp(aux->info.codigo,codigo) != 0){
        ant = aux;
		aux = aux->prox;
	}
	
	q->info = aux->info;
	
	ant->prox = aux->prox;
	free(aux);
	
	return q;
}

int disciplinaSIN(disciplina d){
    return (d.codigo[0] == 'S' && d.codigo[1] == 'I' && d.codigo[2] == 'N');
}

void imprimirDisciplina(disciplina d){
    printf("Codigo: %s\n",d.codigo);
    printf("Nome: %s\n", d.nome);
    printf("Creditos: %d\n", d.creditos);
    printf("Carga horaria: %d\n", d.carga_horaria);
}

void imprimirLista(celula *lista){
    printf("Lista: \n");
	celula *aux = lista;
	while (aux != NULL){
		imprimirDisciplina(aux->info);
		aux = aux->prox;
	}
    printf("\n");
}

void imprimirListaSIN(celula *lista){
    printf("Lista: \n");
	celula *aux = lista;
	while (aux != NULL){
        if(disciplinaSIN(aux->info) && aux->info.carga_horaria > 60){
		    imprimirDisciplina(aux->info); 
        }
		aux = aux->prox;
	}
    printf("\n");
}