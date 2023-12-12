#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
	int *p=NULL;
	int ii=0;
	/*Solicitando espacio para 15 valores enteros*/
	p=(int *) malloc (15 *sizeof(int));
	/*Carga de datos*/
	for(ii=0;ii<15;ii++){
		*(p+ii)=ii;
	}
	printf("Start address %p\n", p);
	/*Impresion de datos*/
	for(ii=0;ii<15;ii++){
		printf("%d\n",*(p+ii));
	}
	/*Redimension de la memoria*/
	p=(int *) realloc(p,25* sizeof(int));
	/*Carga de nuevos datos*/
	for(ii=0;ii<10;ii++){
		*(p+ii+14)=ii;
	}
	printf("Start address %p\n", p);
	/*Impresion de datos*/
	for(ii=0;ii<25;ii++){
		printf("%d\n",*(p+ii));
	}
	/*Impresion de posiciones de memoria*/
	for(ii=0;ii<25;ii++){
		printf("%d\n",(p+ii));
	}
	free(p);
	return 0;
}

