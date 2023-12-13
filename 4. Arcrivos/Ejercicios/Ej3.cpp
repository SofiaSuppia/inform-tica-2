/*Escriba un programa que cree un menu de opciones que permita 
a) abrir un archivo, 
b) escribir un archivo, 
c) leer un archivo. 
*/

#include <stdio.h>
#include <stdlib.h>

void check_null(FILE *fp);

int main(int argc, char const *argv[])
{
    FILE *fp;
    int op = 0;
    char cadena[1000];

    do
    {
        printf("\nIngrese la opcion\n1. Abrir un archivo\n2. Escribir un archivo\n3. Leer un archivo\n");
		scanf("%d",&op);
        switch (op)
        {
        case 1:
            fp=fopen("archivo.txt","a");
			check_null(fp);
			printf("\n--------------APERTURA DEL ARCHIVO--------------\n");
			fclose(fp);
            break;
        
        case 2:
            fp=fopen("archivo.txt","a");
			check_null(fp);
			printf("\n--------------ESCRITURA DEL ARCHIVO--------------\n");
			scanf(" %[^\n]",cadena); // para que permita tomar los espacios y corte con el enter. Debe haber un espacio antes del %
			fprintf(fp,"%s\n",cadena);
			fclose(fp);
            break;
        
        case 3:
            printf("\n--------------LECTURA DEL ARCHIVO--------------\n");
			fp=fopen("archivo.txt","r");
			check_null(fp);
			while(fscanf(fp,"%s",cadena)!=EOF)
			{
				printf("%s\n",cadena);
			}
			fclose(fp);
            break;
        }
    } while (op!=0);
    
    return 0;
}

void check_null(FILE *fp){
	if(fp==NULL){
		printf("Imposible abrir el archivo");
		exit(1);
	}
}
