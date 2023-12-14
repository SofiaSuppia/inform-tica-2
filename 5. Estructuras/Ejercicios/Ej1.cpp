/*Crear un programa que pida los siguientes datos de una cancion: 
Artista, Titulo, Duracion (en segundos),Tamaño del archivo (en KB). 
Crear una estructura que almacene datos de la cancion y luego los
muestre por pantalla.
*/

#include <stdio.h>

struct cancion
{
    char artista[100];
    char titulo[100];
    int duracion;
    int tamanio;
};


int main(int argc, char const *argv[])
{
    struct cancion can;
    printf("Ingrese los siguientes datos de la cancion:\n");
    printf("Artista: ");
	fgets(can.artista, sizeof(can.artista), stdin);
	printf("Titulo: ");
	fgets(can.titulo, sizeof(can.titulo), stdin);
	printf("Duracion: ");
	scanf("%d", &can.duracion);
	printf("Tamanio: ");
	scanf("%d", &can.tamanio);
	
	printf("\nDatos de la cancion:\n");
	printf("Artista: %s", can.artista);
	printf("Titulo: %s", can.titulo);
	printf("Duracion: %d\n", can.duracion);
	printf("Tamanio: %d\n", can.tamanio);
    return 0;
}
