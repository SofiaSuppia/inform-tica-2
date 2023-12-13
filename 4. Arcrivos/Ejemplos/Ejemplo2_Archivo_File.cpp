#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[]) {
	
	FILE *fp;
	fp=fopen("./prueba.txt", "w");
	char cadena [46]="Cadena en un array";
	if(fp==NULL){
		printf("Imposible abrir el archivo");
		exit(1);
	}
	
	fputs("Cadena I", fp);
	fputs("Informatica II - IUA", fp);
	fputs(cadena, fp);
	fclose(fp);
	
	fp=fopen("./prueba.txt", "r");
	if(fp==NULL){
		printf("Imposible abrir el archivo");
		exit(1);
	}
	fgets(cadena, (46+1), fp);
	printf("Cadena recuperada\n%s\n", cadena);
	fclose(fp);
	
	return 0;
}

