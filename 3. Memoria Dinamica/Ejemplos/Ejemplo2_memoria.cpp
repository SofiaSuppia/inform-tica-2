#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
	int *p=NULL;
	int cantidad=0, ii=0, valor=0;
	printf("Ingrese la cantidad de elementos: \n");
	scanf("%d", &cantidad);
	p=(int *)malloc(cantidad*sizeof(int));
	if(p==NULL){
		printf("No hay memoria disponible\n");
		exit(1);
	}else{
		for(ii=0;ii<cantidad;ii++){
			printf("Ingrese el elemento %d\n",ii);
			scanf("%d", &valor);
			*(p+ii)=valor;
		}
		for(ii=0; ii<cantidad;ii++){
			printf("%d\n", *(p+ii));
		}
	}
	free(p);
	return 0;
}

