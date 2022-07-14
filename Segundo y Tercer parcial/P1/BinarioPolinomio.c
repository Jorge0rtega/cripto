/*
	Nombre: Ortega Silva Jorge Eduardo
	Fecha: 01/04/2022
	Descripcion: Dada una cadena binaria que representa un elemento de GF(2^n) con n<=4
	Se imprime su representacion polinomial
*/

#include<stdio.h>
#include <string.h>
int main(){
	char b1[4]="1010";
	binPol(b1);
}

void binPol(char *b1){
	int i=0, j=0, cont=0, tam=0;
	tam=strlen(b1);
	for(i=0, j=tam-1; i<tam-1; i++, j--){		
		if(b1[i]=='1'){
			if(cont!=0)printf(" + ");
			printf("x^%d",j);
			cont++;
		}		
	}
	if(b1[tam-1]=='1'){
		if(cont!=0)printf(" + ");
		printf("1");
	}
	if(b1[tam-1]=='0' && cont==0){
		printf("0");
	}		
}
