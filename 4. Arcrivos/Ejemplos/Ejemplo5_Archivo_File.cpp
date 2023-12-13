#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void check_null(FILE *fp);
void write_file(FILE *fp);
void read_file(FILE *fp);

int main(int argc, char *argv[]) {
	
	FILE *fp=NULL;
	write_file(fp);
	read_file(fp);
	return 0;
}

void check_null(FILE *fp){
	if(fp==NULL){
		printf("Imposible abrir el archivo");
		exit(1);
	}
}
	
void write_file(FILE *fp){
	char data='0';
	fp=fopen("./Texto.txt", "w");
	check_null(fp);
	printf("Ingrese datos [. para finalizar]: \n");
	do{
		scanf("%c", &data);
		fputc(data, fp);
	}while(data!='.');
	
	fclose(fp);
}

void read_file(FILE *fp){
	char data='0';
	fp=fopen("./Texto.txt", "r");
	check_null(fp);
	printf("\nLos datos del archivo\n");
	while(!feof(fp)){
		data=getc(fp);
		printf("%c",data);
	}
	fclose(fp);
}
