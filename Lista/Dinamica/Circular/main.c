#include <stdio.h>
#include "BBT_LCSE1.c"

int main(){
	
	celula *lista;
	inicializar(&lista);
	
	
	inserirFinal(&lista, 'b');
	inserirFinal(&lista, 'c');
	inserirInicio(&lista, 'a');
	
	imprimir(&lista);
	imprimir_vogal(&lista);
	
	removerFinal(&lista);
	removerInicio(&lista);
	
	imprimir(&lista);
	
	return 0;
}