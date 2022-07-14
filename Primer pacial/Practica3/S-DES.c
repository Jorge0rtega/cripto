/*
	Nombre: Ortega Silva Jorge Eduardo
	Fecha: 13/03/2022
	Descripcion: Dada una clave de 10 bits como entrada se realizan permutaciones, 
	permutaciones de compresion y corrimientos para generar dos subclaves de 8 bits
*/

#include<stdio.h>
#include <string.h>

void main(){
	unsigned char key[10];
	unsigned char subkey1[8];
	unsigned char subkey2[8];
	int i=0;
	printf("Ingresa tu llave de 10 bits: ");
	gets(key);
	SDES(key, subkey1, subkey2);
	printf("\nLlave: %X", binarioDecimal(key,10));	
	printf("\nSubllave 1: %X", binarioDecimal(subkey1,8));
	printf("\nSubllave 2: %X", binarioDecimal(subkey2,8));
		
}

void SDES(unsigned char *llave, unsigned char *subllave1, unsigned char *subllave2){
	unsigned char auxKey[10];
	unsigned char bloqueKey[10];
	int i=0;
	int p10[10]={3,5,2,7,4,10,1,9,8,6};
	int p8[8]={6,3,7,4,8,5,10,9};
	////////Subllave 1//////
	/////////P10///////////
	for(i=0; i<10; i++){
		auxKey[i]=llave[p10[i]-1];
	}	
	/////Corrimiento//////
	corrimiento(auxKey, bloqueKey);
	/////////P8///////////
	for(i=0; i<8; i++){
		auxKey[i]=bloqueKey[p8[i]-1];
	}	
	//asignacion primera subllave
	for(i=0; i<8; i++){
		subllave1[i]=auxKey[i];
	}
	////////Subllave 2//////
	/////Corrimientos//////
	corrimiento(bloqueKey, auxKey);
	corrimiento(auxKey, bloqueKey);
	/////////P8///////////
	for(i=0; i<8; i++){
		auxKey[i]=bloqueKey[p8[i]-1];
	}	
	//asignacion segunda subllave
	for(i=0; i<8; i++){
		subllave2[i]=auxKey[i];
	}
}

void corrimiento(unsigned char *original, unsigned char *corrimiento){
	int i=0;
	//corrimiento en bloques
	for(i=0; i<10; i++){
		//primer bloque
		if(i<5){
			if(i==0){
				corrimiento[4]=original[i];
			}else{
				corrimiento[i-1]=original[i];
			}			
		}
		//segundo bloque
		if(i>=5){
			if(i==5){
				corrimiento[9]=original[i];
			}else{
				corrimiento[i-1]=original[i];
			}			
		}
	}
}

int binarioDecimal(char *cadenaBinaria, int longitud) {
	int decimal = 0;
	int multiplicador = 1;
	char caracterActual;
	int i=0;
	for (i=longitud-1; i>=0; i--) {
		caracterActual=cadenaBinaria[i];
		if (caracterActual=='1') {
			decimal+=multiplicador;
		}
		multiplicador=multiplicador*2;
	}
	return decimal;
}
