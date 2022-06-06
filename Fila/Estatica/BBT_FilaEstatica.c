#include <stdio.h>
#define MAXTAM 5

typedef struct sFila{
	int vet[MAXTAM];
	int inicio, fim;
}fila;
 
void inicializar(fila *fila){
	fila->inicio = 0;
	fila->fim = 0;
}
 
int vazia(fila *fila){
	if(fila->inicio == fila->fim)
		return 1;
	return 0;
}

int cheia(fila *fila){
	if((fila->fim+1) % MAXTAM ==  fila->inicio)
		return 1;
	return 0;
}
 
int enfileirar(fila *fila, int n){
	
	if(cheia(fila))
		return 0;
	
	fila->fim = (fila->fim+1) % MAXTAM;
	fila->vet[fila->fim] = n;
	return 1;
}
 
 int desenfileirar(fila *fila){
	
	 if (vazia(fila)){
		 printf("erro desenfileirar");
		 	return 0;
	 }
	 
	 
	 fila->inicio = (fila->inicio+1) % MAXTAM;
	 return 1;
 }
 
 int imprimir(fila *fila){

	 if(vazia(fila))
	 	return 0;
	 
	 while(!vazia(fila)){
		 printf("%d ", fila->vet[(fila->inicio+1) % MAXTAM]);
		 desenfileirar(fila);
	 }
	 return 1;
 }
 
 void imprimirNaoClassica(fila *fila){
	 int i= (fila->inicio+1) % MAXTAM;
	 while (i!= (fila->fim+1)%MAXTAM){
		 printf("%d ", fila->vet[i]);
		 i = (i+1)%MAXTAM;
	 }
 }