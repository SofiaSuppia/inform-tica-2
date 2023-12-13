#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define TAM 3

using namespace std;

struct measurement{
	float temp;
	float hum;
	int id;
};


void check_null(FILE *fp);

int main(int argc, char *argv[]) {
	struct measurement m_array[TAM];
	int ii=0;
	FILE *fp=NULL;
	
	fp=fopen("measurement_db.txt", "w");
	check_null(fp);
	
	for(ii=0; ii<TAM; ii++){
		printf("Medicion nro %d:\n", ii);
		scanf("%f",&m_array[ii].temp);
		scanf("%f",&m_array[ii].hum);
		m_array[ii].id=ii;
		fwrite(&m_array[ii], sizeof(m_array[ii]),1,fp);
	}
	fclose(fp);
	
	fp=fopen("measurement_db.txt", "r");
	check_null(fp);
	
	for(ii=0;ii<TAM;ii++){
		fread(&m_array[ii], sizeof(struct measurement),1,fp);
	}
	fclose(fp);
	
	
	for(int ii=0; ii<3;ii++){
		printf("Temperatura \t%f\n", m_array[ii].temp);
		printf("Humedad \t%f\n", m_array[ii].hum);
		printf("Id \t%d\n", m_array[ii].id);
	}
	
	return 0;
}

void check_null(FILE *fp){
	if(fp==NULL){
		printf("Imposible abrir el archivo");
		exit(1);
	}
}

