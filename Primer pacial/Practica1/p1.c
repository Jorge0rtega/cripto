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

int main (){
	
	int serie[50]={0}; //para la segunda opcion
	int keyInverso[3]={0}; //para la tercera opcion
	int i=0, n=0, a=0, ncpm=0, resultado;
	//primer punto
	printf("----Inverso multiplicativo----\n");
	printf("Se encontrara a^-1 mod n\n");
	printf("Recuerde que 'a' tiene que ser menor a 'n' y coprimo de 'n'\n\n");
	printf("Y que 'n' tiene que ser mayor a 0 \n\n");
	printf("Ingrese el valor de a: ");
	scanf("%d", &a);
	printf("\n");
	printf("Ingrese el valor de n: ");
	scanf("%d",&n);
	printf("\n");
	resultado= xgcd(a,n);
	printf("%d^-1 mod %d = %d\n", a, n, resultado);
	//segundo punto
	printf("\n\n\n----Numeros coprimos----\n");
	printf("Recuerde que 'n' deber ser mayor a 1\n");
	printf("Ingresa la n a la que se le encontrara su conjunto de numeros coprimos: ");
	scanf("%d", &n);
	printf("\n");
	ncpm=coprimos(n,serie);
	printf("\nZ*n={ "); 
	for(i=0;i<ncpm;i++){
		printf("%d  ",serie[i]); 
	}
	printf("}\n");
	// tercer punto
	printf("\n\n\n----Affine cipher y a^-1 mod n----\n");
	printf("Se encontrara una llave valida para Affine cipher (k=(a,b))\n");
	printf("Ademas se entrara a^-1 mod n\n");
	printf("Recuerde que 'n' deber ser mayor a 1\n");
	printf("Ingrese el valor de n: ");
	scanf("%d",&n);
	printf("\n");
	affine(n, keyInverso);
	printf("K=(%d, %d)\n", keyInverso[0], keyInverso[1]);
	printf("\n%d^-1 mod %d = %d", keyInverso[0], n, keyInverso[2]);
    return 0;
}

void affine(int n, int *serie){
	int cpm[50]={0}; //serie con numeros coprimos
	int ale1, ale2, ncpm;
	srand(time(0));
	ncpm=coprimos(n,cpm);
	ale1=rand()%(ncpm);//aleatorio de los coprimos
	ale2=rand()%n;// aleatorio entre 0 y n
	serie[0]=cpm[ale1];
	serie[1]=ale2;
	serie[2]=xgcd(serie[0],n);
	
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

int xgcd(int a, int n){ //calcula los inversos
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
