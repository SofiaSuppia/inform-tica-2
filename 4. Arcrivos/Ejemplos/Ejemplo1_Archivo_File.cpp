/*Ingrese caracteres (no importa si hay espacios o enter), 
para indicar el fin de la carga escriba "$"
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
	
	char data='0';
	
	FILE *fp;
	fp=fopen("./prueba.txt", "w");
	if(fp==NULL){
		printf("Imposible abrir el archivo");
		exit(1);
	}
	
	do{
		scanf("%c", &data);
		fputc(data, fp);
	}while(data!='$');
	
	fclose(fp);
	
	fp=fopen("./prueba.txt", "r");
	if(fp==NULL){
		printf("Imposible abrir el archivo");
		exit(1);
	}
	
	while(!feof(fp)){
		data=getc(fp);
		printf("%c",data);
	}
	fclose(fp);

		
	return 0;
}

