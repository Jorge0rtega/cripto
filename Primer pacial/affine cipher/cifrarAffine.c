/*
	Nombre: Ortega Silva Jorge Eduardo
	Fecha: 20/02/2022
	Descripcion: algoritmo de cifrado affine
*/
#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include <string.h>

int main (){
	
	char msj[128]={0};
	int printMsj[128]={0};
	int key[2]={0};
	int n=26, a=0, b=0, i=0;
	keyAffine(n,key);
	a=key[0];
	b=key[1];
	printf("---------Affine cipher---------");
	printf("\nInstrucciones: solo escribir letras de la A-Z en mayusculas");
	printf("\n\nEscribe el texto a cifrar: ");
	gets(msj);
	printf("\nSu clave: a= %d,	b= %d\n",a,b);
	eAffine(a,b,n,msj,printMsj);
	printf("\nCifrado: ");
	for(i=0; printMsj[i]!=0; i++){
		printf("%c", printMsj[i] );
		msj[i]=printMsj[i];//alistando el mensaje para el desifrado
	}	
    return 0;
}

//funcion para cifrar
void eAffine(int a, int b, int n, char *msj, int *newMsj){//a, b, Z, mensaje, cifrado en entero
	// (ax + b) MOD 26
	//mayusculas 65-90
	int i=0, stop=0;
	int copyMsj[128]={0};
	for(i=0;stop==0;i++){
		if(msj[i]!=0){
				copyMsj[i]=msj[i]-65;// 65 por su valor en codigo ascii
				newMsj[i]=(((a*copyMsj[i])+b)%n)+65;
		}else{
			stop=1;
		}
	}
}

void keyAffine(int n, int *serie){
	int cpm[50]={0}; //serie con numeros coprimos
	int ale1, ale2, ncpm;
	srand(time(0));
	ncpm=coprimos(n,cpm);
	ale1=rand()%(ncpm);//aleatorio de los coprimos
	ale2=rand()%n;// aleatorio entre 0 y n
	serie[0]=cpm[ale1];
	serie[1]=ale2;
}

int coprimos(int n, int *serie){
	int x=0, u=0, v=0;//Variables de respaldo
    int r=0, i=0, j=0;
    //para econtrar el gcd
    for(i=1, j=0; i<n; i++){
    	u=i;
    	v=n;
    	while (v!=0) {
	        x=v;
	        r=u%v;
	        v=r;
	        u=x;
	        //u es el gcd
	    }
	    if(u==1){
	    	serie[j]=i;
	    	j++;
		}
	}
	return j;// total de coprimos
}

int inversoMult(int a, int n){ //a tiene que ser menor a n
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

