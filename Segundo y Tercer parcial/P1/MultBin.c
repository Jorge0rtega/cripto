/*
	Nombre: Ortega Silva Jorge Eduardo
	Fecha: 08/04/2022
	Descripcion: La primera funcion pasa de un valor binario a su respectivo valor polinomial,
	la segunda funcion, resuelve la multiplicacion de dos binarios de GF(2^8) mod (x^8 + x^4 + x^3+ x + 1),
	la tercera funcion genera la tabla de multiplicar correspondiente de GF(2^4) (La funcion de GF(2^4) esta en TEAMS ), la actual es de a la 8
*/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int i=0;
	unsigned char b1[8]="0111";
	unsigned char b2[8]="1111";
	unsigned char b[4]="01";
	unsigned char resultado[4];
	//printf("Binario: %s", b);
	//printf("\nVersion polinomial\n");
	//binPol(b);	
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

	//tablaMult(); //si se quiere hacer el archivo con la tabla quitar comentarios
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

void multBin(unsigned char *b1, unsigned char *b2, unsigned char *res){
	int j=0, i=0, cont=0, aux=0, unos=0;
	unsigned char copyB2[4];
	unsigned char auxB2[4];
	unsigned char r[4]="0011"; //residuo del polinomio irreducible x^4+x+1	
	unsigned char mult[4][4];
	unsigned char listaMult[4][4];
	unsigned char resultado[4];

	for(i=0; i<4; i++){//primero sin cambios
		mult[0][i]=b2[i];
	}
	for(i=0; i<4; i++){//guardar el valor de b2
			auxB2[i]=b2[i];
	}	
	for(j=0; j<3; j++){	
		for(i=0; i<4; i++){
			copyB2[i]=b2[i];
		}
		if(b2[0]=='0') { //si el bit mas significativo es 0
			b2[3]='0';//corrimiento
			for(i=0; i<3; i++){
				b2[i]=copyB2[i+1];
			}
		}else{ //si el bit mas significativo es 1
			b2[3]='0';//Corrimiento
			for(i=0; i<3; i++){
				b2[i]=copyB2[i+1];
			}//XOR con el residuo			
			for(i=0; i<4; i++){		
				if (b2[i]==r[i]){
					b2[i]='0';
				}else{
					b2[i]='1';
				}
			}
		}
		//printf("\n%s", b2);
		for(i=0; i<4; i++){
			mult[j+1][i]=b2[i];
			printf("%c",b2[i]);
		}
		printf("\n");	
	}
	for(i=0; i<4; i++){//valor original de b2
		b2[i]=auxB2[i];
	}
	
	for(i=0, aux=3;i<4;i++,aux--){
		if(b1[i]=='1'){
			for(j=0;j<4;j++)
				listaMult[cont][j]=mult[aux][j];
			cont++;
		}	
	}	

	
	for(i=0;i<4;i++){
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
	
	for(i=0; i<4; i++){
		res[i]=resultado[i]; //valor que devuelve
	}
	
}

void tablaMult(){
	unsigned char numeros[16][4]={"0000", "0001", "0010", "0011", 
								  "0100", "0101", "0110", "0111",
								  "1000", "1001", "1010", "1011",
								  "1100", "1101", "1110", "1111"};
	int i=0, j=0, k=0;
	unsigned char resultado[4];
	FILE* fichero;
    fichero = fopen("TablaMultiplicar.txt", "wt");
    fprintf (fichero, "\t");
    for(i=0;i<16;i++){//encabezado
    	for(j=0;j<4;j++){
    		fprintf (fichero, "%c", numeros[i][j]);
    	}
    	fprintf (fichero, "\t");
	}
	fprintf (fichero, "\n");
	for(i=0;i<16;i++){
    	fprintf (fichero, "--------");
	}
	fprintf (fichero, "\n");
	for(i=0;i<16;i++){
		for(j=0;j<4;j++){//columna
    		fprintf (fichero, "%c", numeros[i][j]);
		}
		fprintf (fichero, "|\t");
		for(k=0;k<16;k++){
			multBin(numeros[k], numeros[i], resultado);
			for(j=0;j<4;j++){//contenido
    			fprintf (fichero, "%c", resultado[j]);
    		}
    		fprintf (fichero, "\t");
		}
    	
    	fprintf (fichero, "\n");
	}
    fclose(fichero);
    printf("\n\nArchivo creado");
	
}
