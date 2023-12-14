/*Crear un programa que pida los siguientes datos de una persona: 
nombre, apellido, celular.
Crear una estructura que almacene datos de persona y luego los 
muestre por pantalla.
*/

#include <stdio.h>
#include <string.h>

struct persona
{
	char nombre[100];
	char apellido[100];
	long celular;
};

int main() {
	
	struct persona p;
	printf("Ingrese los siguientes datos de persona:\n");
	printf("Nombre: ");
	fgets(p.nombre, sizeof(p.nombre), stdin);
	p.nombre[strcspn(p.nombre, "\n")] = '\0'; // Elimina el caracter de nueva li­nea
	printf("Apellido: ");
	scanf("%s", p.apellido);
	printf("Celular: ");
	scanf("%ld", &p.celular);
	
	printf("\nDatos de persona:\n");
	printf("Nombre: %s\n", p.nombre);
	printf("Apellido: %s\n", p.apellido);
	printf("Celular: %ld\n", p.celular);
	
	return 0;
}

