/*
	Nombre: Ortega Silva Jorge Eduardo
	Fecha: 18/04/2022
	Descripcion: Resuelve la multiplicacion de dos binarios de GF(2^8) mod (x^8 + x^4 + x^3+ x + 1) el polinomio de AES.
*/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int i=0;
	unsigned char b1[8]="00000011";
	unsigned char b2[8]="01101110";
	unsigned char resultado[8];	
	multBin(b1, b2, resultado);
	printf("\nbinario 1\n");
	for(i=0; i<8; i++){
		printf("%c",b1[i]);
	}
	printf("\nbinario 2\n");
	for(i=0; i<8; i++){
		printf("%c",b2[i]);
	}
	printf("\nResultado b1*b2 mod (x^4 + x + 1)\n");
	for(i=0; i<8; i++){
		printf("%c",resultado[i]);
	}

}



void multBin(unsigned char *b1, unsigned char *b2, unsigned char *res){
	int j=0, i=0, cont=0, aux=0, unos=0;
	unsigned char copyB2[8];
	unsigned char auxB2[8];
	unsigned char r[8]="00011011"; //residuo del polinomio (x^8 + x^4 + x^3+ x + 1)
	unsigned char mult[8][8];
	unsigned char listaMult[8][8];
	unsigned char resultado[8];

	for(i=0; i<8; i++){//primero sin cambios
		mult[0][i]=b2[i];
	}
	for(i=0; i<8; i++){//guardar el valor de b2
			auxB2[i]=b2[i];
	}	
	for(j=0; j<8; j++){	
		for(i=0; i<8; i++){
			copyB2[i]=b2[i];
		}
		if(b2[0]=='0') { //si el bit mas significativo es 0
			b2[7]='0';//corrimiento
			for(i=0; i<7; i++){
				b2[i]=copyB2[i+1];
			}
		}else{ //si el bit mas significativo es 1
			b2[7]='0';//Corrimiento
			for(i=0; i<7; i++){
				b2[i]=copyB2[i+1];
			}//XOR con el residuo			
			for(i=0; i<8; i++){		
				if (b2[i]==r[i]){
					b2[i]='0';
				}else{
					b2[i]='1';
				}
			}
		}
		//printf("\n%s", b2);
		for(i=0; i<8; i++){
			mult[j+1][i]=b2[i];
		}	
	}
	for(i=0; i<7; i++){//valor original de b2
		b2[i]=auxB2[i];
	}
	
	for(i=0, aux=7;i<8;i++,aux--){
		if(b1[i]=='1'){
			for(j=0;j<8;j++)
				listaMult[cont][j]=mult[aux][j];
			cont++;
		}	
	}	

	
	for(i=0;i<8;i++){
		unos=0;
		for(j=0;j<cont;j++){
			if(listaMult[j][i]=='1'){
				unos++;
			}
		}
		if((unos%2)==1){
			resultado[i]='1';
		}else{
			resultado[i]='0';
		}	
	}
	
	for(i=0; i<8; i++){
		res[i]=resultado[i]; //valor que devuelve
	}
	
}


