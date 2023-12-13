#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
	
	FILE *fptr;
	int id=0, ii=0;
	char nombre[30];
	float sueldo=0;
	fptr=fopen("database.txt", "w+");
	if(fptr==NULL){
		printf("El archivo no existe\n");
		return (1);
	}
	for(ii=0; ii<3;ii++){
		scanf("%d", &id);
		scanf("%s", nombre);
		scanf("%f", &sueldo);
		fprintf(fptr,"%d %s %f\n", id, nombre, sueldo);
	}
	fclose(fptr);
	
	while(!feof(fptr)){
		fscanf(fptr,"%d %s %f\n", &id, &nombre, &sueldo);
		printf("%d %s %f\n", id, nombre, sueldo);
	}
	fclose(fptr);
	return 0;
}

