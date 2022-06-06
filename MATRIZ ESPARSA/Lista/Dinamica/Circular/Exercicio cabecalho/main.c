#include <stdio.h>
#include "BBT_LCSE1.c"

int main(){
	
	cabecalho *lista;
	inicializar(&lista);
	
	
	inserirInicio(&lista);
	inserirInicio(&lista);
	inserirInicio(&lista);
	
	imprimir(&lista);
	
	return 0;
}