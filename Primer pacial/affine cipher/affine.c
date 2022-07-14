/*
	Nombre: Ortega Silva Jorge Eduardo
	Fecha: 17/02/2022
	Descripcion: funciones que encuentra el inverso multiplicativo,
	numero coprimos y generador de claves para el algoritmo
	affine cipher
*/
#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include <string.h>

int main (){
	
	char msj[128]={0};
	int printMsj[128]={0};
	int key[2]={0};
	int n=54, a=0, b=0, i=0;
	keyAffine(n,key);
	a=key[0];
	b=key[1];
	printf("ascii: %d", ascii(0));
	printf("ascii: %d", ascii(26));
	printf("ascii: %d", ascii(51));
	printf("ascii: %d", ascii(52));
	printf("ascii: %d", ascii(53));
	
	printf("orden: %d", ordenABC(65));
	printf("orden: %d", ordenABC(97));
	printf("orden: %d", ordenABC(122));
	printf("orden: %d", ordenABC(165));
	printf("orden: %d", ordenABC(164));
	/*
	printf("Escribe el texto a cifrar: ");
	gets(msj);
	printf("TextoPlano: %s\n", msj );
	eAffine(a,b,n,msj,printMsj);//a, b, Z, mensaje, cifrado en entero
	printf("Cifrado: ");
	for(i=0; printMsj[i]!=0; i++){
		printf("%c", printMsj[i] );
		msj[i]=printMsj[i];//alistando el mensaje para el desifrado
	}
	printf("\na= %d,	b= %d",a,b);
	dAffine(a,b,n,msj,printMsj);//a, b, Z, mensaje, descifrado en entero
	printf("\nDesifrado: ");
	for(i=0; printMsj[i]!=0; i++){
		printf("%c", printMsj[i] );
	}*/
    return 0;
}

void dAffine(int a, int b, int n, char *msj, int *newMsj){
	// (ax + b) MOD 26
	//mayusculas 65-90
	//orden
	//0-26 27-52 53 54
	//65-90 97-122 165 164
	//A-Z a-z � �
	int i=0, stop=0, inverso=0, aux=0;
	int copyMsj[128]={0};
	inverso=inversoMult(a,n);
	for(i=0;stop==0;i++){
		if(msj[i]!=0){
			if(msj[i]>=65 && msj[i]<=90){ //A-Z
				copyMsj[i]=msj[i]-65;
				aux=((inverso*((copyMsj[i])-b)));
				if(aux>=0)
					newMsj[i]=(aux%n)+65;
				else
					newMsj[i]=(n-((-1*aux)%n))+65;
			}
			/*
			if(msj[i]>=97 && msj[i]<=122){ //a-z
				copyMsj[i]=msj[i]-71;
				aux=((inverso*((copyMsj[i])-b)));
				if(aux>=0)
					newMsj[i]=(aux%n)+71;
				else
					newMsj[i]=(n-((-1*aux)%n))+71;
			}
			if(msj[i]==165){ //� 
				copyMsj[i]=msj[i]-111;
				aux=((inverso*((copyMsj[i])-b)));
				if(aux>=0)
					newMsj[i]=(aux%n)+111;
				else
					newMsj[i]=(n-((-1*aux)%n))+111;
			}
			if(msj[i]==164){ //�
				copyMsj[i]=msj[i]-110;
				aux=((inverso*((copyMsj[i])-b)));
				if(aux>=0)
					newMsj[i]=(aux%n)+110;
				else
					newMsj[i]=(n-((-1*aux)%n))+110;
			}*/
		}else{
			stop=1;
		}
	}
}

void eAffine(int a, int b, int n, char *msj, int *newMsj){
	// (ax + b) MOD 26
	//mayusculas 65-90
	int i=0, stop=0;
	int copyMsj[128]={0};
	for(i=0;stop==0;i++){
		if(msj[i]!=0){
			
			if(msj[i]>=65 && msj[i]<=90){ //A-Z
				copyMsj[i]=msj[i]-65;
				newMsj[i]=(((a*copyMsj[i])+b)%n)+65;
			}
			if(msj[i]>=97 && msj[i]<=122){ //a-z
				copyMsj[i]=msj[i]-71;
				newMsj[i]=(((a*copyMsj[i])+b)%n)+71;
			}
			if(msj[i]==165){ //�
				copyMsj[i]=msj[i]-113;
				newMsj[i]=(((a*copyMsj[i])+b)%n)+113;
			}
			if(msj[i]==164){ //�
				copyMsj[i]=msj[i]-112;
				newMsj[i]=(((a*copyMsj[i])+b)%n)+112;
				
			}
			printf("%d  ", copyMsj[i]);
			printf("%d  ", newMsj[i]);
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

int ordenABC(int caracter){
	//printf("%d",caracter);
	if(caracter>=65 && caracter<=90){ //A-Z
	 	caracter=caracter-65;
	}
	if(caracter=97 && caracter<=122){ //a-z
		caracter=caracter-71;
	}
	if(caracter==165){ //� 
		caracter=caracter-111;
	}
	if(caracter==164){ //�
		caracter=caracter-110;
	}
	//printf("%d",caracter);
	return caracter;
}

int ascii(int caracter){
	//printf("%d",caracter);
	if(caracter>=0 && caracter<=25){ //A-Z
	 	caracter=caracter+65;
	}
	if(caracter=26 && caracter<=51){ //a-z
		caracter=caracter+71;
	}
	if(caracter==52){ //� 
		caracter=caracter+111;
	}
	if(caracter==53){ //�
		caracter=caracter+110;
	}
	//printf("%d",caracter);
	return caracter;
}
