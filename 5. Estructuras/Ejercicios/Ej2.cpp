/*Crear un programa que pida los siguientes datos de una cancion: 
Artista, Titulo, Duracion (en segundos),Tamaño del archivo (en KB). 
Crear una estructura que almacene datos de la cancion y luego los
muestre por pantalla.

Ampliar el programa del ejercicio anterior, para que almacene datos 
de hasta 3 canciones en un vector de estructura.
Luego crear un menu que permita las opciones: 
a. agregar una nueva cancion
b. mostrar todas las canciones
c. buscar una cancion por titulo

*/

#include <iostream>
#include <cstring>
using namespace std;

struct cancion
{
	char artista[100];
	char titulo[100];
	int duracion;
	int tamanio;
};

int main(int argc, char const *argv[])
{
    struct cancion cancionero[3]; 
	char op=' ';
	char buscar_titulo[100]={' '};
	bool bandera_encontrado=false;
	
	do{
		printf("MENU DE OPCIONES\n");
		printf("a. Agregar.\nb. Mostrar.\nc. Buscar.\n");
		scanf(" %c", &op);
		//getchat(). Se utiliza principalmente despues de una lectura de datos usando scanf o fgets 
		//para consumir el caracter de nueva linea residual dejado en el bufer de entrada.
		getchar();
		switch(op){
		case 'a': 
			for(int i=0; i<3; i++){
				printf("\nINGRESE LOS DATOS DE LA CANCION Nº%d:\n",i+1);
				printf("Artista: ");
				fgets(cancionero[i].artista, sizeof(cancionero[i].artista), stdin);
				printf("Titulo: ");
				fgets(cancionero[i].titulo, sizeof(cancionero[i].titulo), stdin);
				printf("Duracion: ");
				scanf("%d", &cancionero[i].duracion);
				printf("Tamanio: ");
				scanf("%d", &cancionero[i].tamanio);
				getchar();
				printf("---------------------------------------------------");
			}
			break;
		case 'b':
			for(int i=0; i<3; i++){
				printf("\nDATOS DE CANCION Nº%d:\n", i+1);
				printf("Artista: %s", cancionero[i].artista);
				printf("Titulo: %s", cancionero[i].titulo);
				printf("Duracion: %d\n", cancionero[i].duracion);
				printf("Tamanio: %d\n", cancionero[i].tamanio);
				printf("---------------------------------------------------");
			}
			break;
		case 'c':
			printf("INGRESE EL TITULO DE LA CANCION A BUSCAR:\n");
			fgets(buscar_titulo, sizeof(buscar_titulo), stdin);
			bandera_encontrado=false;
			for(int i=0; i<3; i++){
				if(strcmp(buscar_titulo, cancionero[i].titulo) == 0){
					printf("Titulo de cancion encontrado.\n");
					printf("Artista: %s", cancionero[i].artista);
					printf("Titulo: %s", cancionero[i].titulo);
					printf("Duracion: %d\n", cancionero[i].duracion);
					printf("Tamanio: %d\n", cancionero[i].tamanio);
					bandera_encontrado=true;
				}
			}
			if(bandera_encontrado==false){
				printf("No se encontro el titulo de la cancion.\n");
			}
			break;
		}
		printf("\n¿Desea seguir (S/N)? ");
		scanf(" %c", &op);
		
	}while(op=='s' || op=='S');
	
    return 0;
}
