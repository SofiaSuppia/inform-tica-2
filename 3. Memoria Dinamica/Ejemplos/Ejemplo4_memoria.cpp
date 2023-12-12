#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define M 4
#define N 5


using namespace std;

int main(int argc, char *argv[]) {
	int ii=0, jj=0;
	/*Columnas*/
	int **A=(int **)malloc(M * sizeof(int *));
	if(A==NULL){
		printf("No hay memoria suficiente");
		exit(0);
	}
	/*Filas*/
	for(ii=0;ii<M;ii++){
		*(A+ii)=(int *)malloc(N * sizeof(int));
		if(*(A+ii)==NULL){
			printf("No hay memoria suficiente");
			exit(0);
		}
	}
	/*Carga de datos*/
	for(ii=0;ii<M;ii++){
		for(jj=0;jj<N;jj++){
			*(*(A+ii)+jj)=rand()%100;
		}
	}
	/*Impresion de datos*/
	for(ii=0;ii<M;ii++){
		for(jj=0;jj<N;jj++){
			printf("%d\t",*(*(A+ii)+jj));
		}
		printf("\n");
	}
	/*Liberacion de filas*/
	for(ii=0;ii<M;ii++){
		free(*(A+ii));
	}
	free(A);
	
	return 0;
}

