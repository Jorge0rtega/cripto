/*
	Nombre: Ortega Silva Jorge Eduardo
	Fecha: 20/04/2022
	Descripcion: Multiplicacion de dos matrices en hexadecimal (mixcolumn)
*/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	unsigned char m1[16][2]={"02","03","01","01","01","02","03","01","01","01","02","03","03","01","01","02"};//matriz uno
	unsigned char m2[16][2]={"87","F2","4D","97","6E","4C","90","EC","46","E7","4A","C3","A6","8C","D8","95"};//matriz dos
	mixcolumn(m1, m2);
}

void mixcolumn(unsigned char *M1, unsigned char *M2){

	unsigned char resultado[16][2];
	unsigned char bin1[8]="00000000";
	unsigned char bin2[8]="00000000";
	unsigned char auxM1[2]="00";
	unsigned char auxM2[2]="00";
	unsigned char res1[8]="00000000";
	unsigned char auxResT[8]="00000000";
	unsigned char resT[8]="00000000";
	unsigned char hexa[2]="00";
	int i=0, j=0,k=0, l=0, m=0;
	//inicio del metodo
	for(i=0, k=0, l=0, m=8;k<16;i=i+m, l=l+2){
			
		strncpy(auxM1, M1 + l, 2);//extraccion de los dos caracteres de las matrices
		strncpy(auxM2, M2 + i, 2);
		//printf("\n%s", auxM1);
		//printf("\n%s", auxM2);
		hexaBin(auxM1, bin1);
		//printf("\n%s", bin1);
		hexaBin(auxM2, bin2);
		//printf("\n%s", bin2);
		multBin(bin1, bin2, res1);// multiplicacion de los numeros binarios elegidos
		//printf("\n%s\n",res1);
		
		
		for(j=0; j<8; j++){	//XOR 	
			if (res1[j]==auxResT[j]){
				resT[j]='0';
			}else{
				resT[j]='1';
			}
		}
		for(j=0; j<8; j++){	
			auxResT[j]=resT[j];//guardar el resultado del XOR para la siguiente multiplicacion
		}
		//printf("\n\n l= %d", l);
		//printf("\n\n i= %d", i);
		if((l+2)%8==0 && l!=0){
			//printf("\n\n\nResultado: %s",resT);
			binHexa(resT, hexa);
			strcpy(resT, "00000000");//reset
			strcpy(auxResT, "00000000");//reset
			//printf("\n\nResultado en Hexa: %s", hexa);
			resultado[k][0]=hexa[0];//asignacion de los resultados en la matriz del resultado final
			resultado[k][1]=hexa[1];
			k++;
			if(k==0 || k==4|| k==8|| k==12)i=-8;//para el corrimiento de las filas de la segunda matriz 
			if(k==1 || k==5|| k==9|| k==13)i=-6;
			if(k==2 || k==6|| k==10|| k==14)i=-4;
			if(k==3 || k==7|| k==11|| k==15)i=-2;
			if(k>=0 && k<=3){	//para el corrimiento de las filas de la primera matriz 			
				l=-2;
			}
			if(k>=4 && k<=7){
				l=6;
			}
			if(k>=8 && k<=11){
				l=14;
			}
			if(k>=12 && k<=15){
				l=22;
			}
							
		}
	}
	printf("Multiplicacion de las dos matrices (Mixcolumn)\n\n");
	for(j=0; j<16; j++){
		printf("%c%c ",resultado[j][0],resultado[j][1]);//mixcolumn
		if((j+1)%4==0 && j!=0){
			printf("\n");
		}
	}
	
	
	
}

void hexaBin(unsigned char *h, unsigned char *b){
	//printf("%d",h[0]);
	//printf("%d",h[1]);
	if(h[0]==48){
		b[0]='0'; b[1]='0'; b[2]='0'; b[3]='0';
	}
	if(h[0]==49){
		b[0]='0'; b[1]='0'; b[2]='0'; b[3]='1';
	}
	if(h[0]==50){
		b[0]='0'; b[1]='0'; b[2]='1'; b[3]='0';
	}
	if(h[0]==51){
		b[0]='0'; b[1]='0'; b[2]='1'; b[3]='1';
	}
	if(h[0]==52){
		b[0]='0'; b[1]='1'; b[2]='0'; b[3]='0';
	}
	if(h[0]==53){
		b[0]='0'; b[1]='1'; b[2]='0'; b[3]='0';
	}
	if(h[0]==54){
		b[0]='0'; b[1]='1'; b[2]='1'; b[3]='0';
	}
	if(h[0]==55){
		b[0]='0'; b[1]='1'; b[2]='1'; b[3]='1';
	}
	if(h[0]==56){
		b[0]='1'; b[1]='0'; b[2]='0'; b[3]='0';
	}
	if(h[0]==57){
		b[0]='1'; b[1]='0'; b[2]='0'; b[3]='1';
	}
	if(h[0]==65){
		b[0]='1'; b[1]='0'; b[2]='1'; b[3]='0';
	}
	if(h[0]==66){
		b[0]='1'; b[1]='0'; b[2]='1'; b[3]='1';
	}
	if(h[0]==67){
		b[0]='1'; b[1]='1'; b[2]='0'; b[3]='0';
	}
	if(h[0]==68){
		b[0]='1'; b[1]='1'; b[2]='0'; b[3]='1';
	}
	if(h[0]==69){
		b[0]='1'; b[1]='1'; b[2]='1'; b[3]='0';
	}
	if(h[0]==70){
		b[0]='1'; b[1]='1'; b[2]='1'; b[3]='1';
	}
	
	
	
	if(h[1]==48){
		b[4]='0'; b[5]='0'; b[6]='0'; b[7]='0';
	}
	if(h[1]==49){
		b[4]='0'; b[5]='0'; b[6]='0'; b[7]='1';
	}
	if(h[1]==50){
		b[4]='0'; b[5]='0'; b[6]='1'; b[7]='0';
	}
	if(h[1]==51){
		b[4]='0'; b[5]='0'; b[6]='1'; b[7]='1';
	}
	if(h[1]==52){
		b[4]='0'; b[5]='1'; b[6]='0'; b[7]='0';
	}
	if(h[1]==53){
		b[4]='0'; b[5]='1'; b[6]='0'; b[7]='1';
	}
	if(h[1]==54){
		b[4]='0'; b[5]='1'; b[6]='1'; b[7]='0';
	}
	if(h[1]==55){
		b[4]='0'; b[5]='1'; b[6]='1'; b[7]='1';
	}
	if(h[1]==56){
		b[4]='1'; b[5]='0'; b[6]='0'; b[7]='0';
	}
	if(h[1]==57){
		b[4]='1'; b[5]='0'; b[6]='0'; b[7]='1';
	}
	if(h[1]==65){
		b[4]='1'; b[5]='0'; b[6]='1'; b[7]='0';
	}
	if(h[1]==66){
		b[4]='1'; b[5]='0'; b[6]='1'; b[7]='1';
	}
	if(h[1]==67){
		b[4]='1'; b[5]='1'; b[6]='0'; b[7]='0';
	}
	if(h[1]==68){
		b[4]='1'; b[5]='1'; b[6]='0'; b[7]='1';
	}
	if(h[1]==69){
		b[4]='1'; b[5]='1'; b[6]='1'; b[7]='0';
	}
	if(h[1]==70){
		b[4]='1'; b[5]='1'; b[6]='1'; b[7]='1';
	}
}

void binHexa(unsigned char *b, unsigned char *h){
	//printf("%d",h[0]);
	//printf("%d",h[1]);
	if(b[0]==48 & b[1]==48 & b[2]==48 & b[3]==48){
		h[0]='0';
	}
	if(b[0]==48 & b[1]==48 & b[2]==48 & b[3]==49){
		h[0]='1';
	}
	if(b[0]==48 & b[1]==48 & b[2]==49 & b[3]==48){
		h[0]='2';
	}
	if(b[0]==48 & b[1]==48 & b[2]==49 & b[3]==49){
		h[0]='3';
	}
	if(b[0]==48 & b[1]==49 & b[2]==48 & b[3]==48){
		h[0]='4';
	}
	if(b[0]==48 & b[1]==49 & b[2]==48 & b[3]==49){
		h[0]='5';
	}
	if(b[0]==48 & b[1]==49 & b[2]==49 & b[3]==48){
		h[0]='6';
	}
	if(b[0]==48 & b[1]==49 & b[2]==49 & b[3]==49){
		h[0]='7';
	}
	if(b[0]==49 & b[1]==48 & b[2]==48 & b[3]==48){
		h[0]='8';
	}
	if(b[0]==49 & b[1]==48 & b[2]==48 & b[3]==49){
		h[0]='9';
	}
	if(b[0]==49 & b[1]==48 & b[2]==49 & b[3]==48){
		h[0]='A';
	}
	if(b[0]==49 & b[1]==48 & b[2]==49 & b[3]==49){
		h[0]='B';
	}
	if(b[0]==49 & b[1]==49 & b[2]==48 & b[3]==48){
		h[0]='C';
	}
	if(b[0]==49 & b[1]==49 & b[2]==48 & b[3]==49){
		h[0]='D';
	}
	if(b[0]==49 & b[1]==49 & b[2]==49 & b[3]==48){
		h[0]='E';
	}
	if(b[0]==49 & b[1]==49 & b[2]==49 & b[3]==49){
		h[0]='F';
	}
	
	
	
	if(b[4]==48 & b[5]==48 & b[6]==48 & b[7]==48){
		h[1]='0';
	}
	if(b[4]==48 & b[5]==48 & b[6]==48 & b[7]==49){
		h[1]='1';
	}
	if(b[4]==48 & b[5]==48 & b[6]==49 & b[7]==48){
		h[1]='2';
	}
	if(b[4]==48 & b[5]==48 & b[6]==49 & b[7]==49){
		h[1]='3';
	}
	if(b[4]==48 & b[5]==49 & b[6]==48 & b[7]==48){
		h[1]='4';
	}
	if(b[4]==48 & b[5]==49 & b[6]==48 & b[7]==49){
		h[1]='5';
	}
	if(b[4]==48 & b[5]==49 & b[6]==49 & b[7]==48){
		h[1]='6';
	}
	if(b[4]==48 & b[5]==49 & b[6]==49 & b[7]==49){
		h[1]='7';
	}
	if(b[4]==49 & b[5]==48 & b[6]==48 & b[7]==48){
		h[1]='8';
	}
	if(b[4]==49 & b[5]==48 & b[6]==48 & b[7]==49){
		h[1]='9';
	}
	if(b[4]==49 & b[5]==48 & b[6]==49 & b[7]==48){
		h[1]='A';
	}
	if(b[4]==49 & b[5]==48 & b[6]==49 & b[7]==49){
		h[1]='B';
	}
	if(b[4]==49 & b[5]==49 & b[6]==48 & b[7]==48){
		h[1]='C';
	}
	if(b[4]==49 & b[5]==49 & b[6]==48 & b[7]==49){
		h[1]='D';
	}
	if(b[4]==49 & b[5]==49 & b[6]==49 & b[7]==48){
		h[1]='E';
	}
	if(b[4]==49 & b[5]==49 & b[6]==49 & b[7]==49){
		h[1]='F';
	}
}

void multBin(unsigned char *b1, unsigned char *b2, unsigned char *res){
	int j=0, i=0, cont=0, aux=0, unos=0;
	unsigned char copyB2[8];
	unsigned char auxB2[8];
	unsigned char r[8]="00011011"; //residuo del polinomio irreducible x^4+x+1	
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
