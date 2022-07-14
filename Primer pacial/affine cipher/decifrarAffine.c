/*
	Nombre: Ortega Silva Jorge Eduardo
	Fecha: 20/02/2022
	Descripcion: algoritmo de descifrado affine
*/
#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include <string.h>

int main (){
	
	char msj[128]={0};
	int printMsj[128]={0};
	int n=26, a=0, b=0, i=0;
	printf("---------Affine cipher---------");
	printf("\nInstrucciones: el mensaje cifrado solo debe contener letras de la A-Z en mayusculas");
	printf("\n\nEscribe el texto a descifrar: ");
	gets(msj);
	printf("Escribe el valor de 'a': ");
	scanf("%d", &a);
	printf("Escribe el valor de 'b': ");
	scanf("%d", &b);
	dAffine(a,b,n,msj,printMsj);
	printf("\nDesifrado: ");// lectura del descifrado
	for(i=0; printMsj[i]!=0; i++){
		printf("%c", printMsj[i] );
	}
    return 0;
}
//funcion para descifrar
void dAffine(int a, int b, int n, char *msj, int *newMsj){//a, b, Z, mensaje, descifrado en entero
	int i=0, stop=0, inverso=0, aux=0;
	int copyMsj[128]={0};
	inverso=inversoMult(a,n);
	for(i=0;stop==0;i++){
		if(msj[i]!=0){
				copyMsj[i]=msj[i]-65;// 65 por el codigo ascii
				aux=((inverso*((copyMsj[i])-b)));
				if(aux>=0)//se aplica modulo, si este es positivo o negativo
					newMsj[i]=(aux%n)+65;
				else
					newMsj[i]=(n-((-1*aux)%n))+65;
		}else{
			stop=1;
		}
	}
}

int inversoMult(int a, int n){ //inveros multiplicativo (a tiene que ser menor a n)
	int u=a, v=n;
	int q=0, x=0, x1=1, x2=0, r=0;
	int resultado;
	while(u!=1){
		q=v/u;
		r=v-(q*u);
		x=x2-(q*x1);
		v=u;
		u=r;
		x2=x1;
		x1=x;
	}
	if(x1>=0)
		return resultado=x1%n;
	else
		return resultado=n+x1;
	
}

