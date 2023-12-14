/*Crear una clase Actividad, las mismas corresponden a las actividades de un gym. 
Atributos: nombre, cupo, dias de la semana, horario, cant_inscriptos.

Funciones: mostrar, buscar, mostrar actividades que aun no tienen el cupo lleno.
*/

#include <stdio.h>

struct actividad
{
	char nombre[100];
	int cupo;
	char dias_semana[100];
	char horario[100];
	int cant_inscripto;
};

void agregar(struct actividad[]);
void mostrar(struct actividad[]);
void mostrarActividadDisponible(struct actividad[]);


int main() {
	
	struct actividad lista[3];
	
	char op = ' ';
	
	do {
		printf("---------------------------------------------------\n");
		printf("MENU DE OPCIONES\n");
		printf("a. Agregar.\nb. Mostrar.\nc. Mostrar Actividades Disponibles.\n");
		scanf(" %c", &op);
		
		switch (op) {
		case 'a':
			agregar(lista);
			break;
		case 'b':
			mostrar(lista);
			break;
		case 'c':
			mostrarActividadDisponible(lista);
			break;
		}
		
		printf("\nÂ¿Desea seguir (S/N)? ");
		scanf(" %c", &op);
		
	} while (op == 's' || op == 'S');
	
	return 0;
}

void agregar(struct actividad lista[]) {
	printf("---------------------------------------------------\n");
	for (int i = 0; i < 3; i++) {
		printf("\nINGRESE LOS DATOS DE ACTIVIDAD Nº%d:\n", i + 1);
		printf("Nombre: ");
		scanf("%s", lista[i].nombre);
		printf("Cupo: ");
		scanf("%d", &lista[i].cupo);
		printf("Dias de la semana: ");
		scanf("%s", lista[i].dias_semana);
		printf("Horario: ");
		scanf("%s", lista[i].horario);
		printf("Cantidad de inscriptos: ");
		scanf("%d", &lista[i].cant_inscripto);
	}
}

void mostrar(struct actividad lista[]) {
	printf("---------------------------------------------------\n");
	printf("Nombre\tCupo\tDias de la semana\tHorario\tCant. Inscriptos\n");
	for (int i = 0; i < 3; i++) {
		printf("%s\t%d\t%s\t%s\t%d\n", lista[i].nombre, lista[i].cupo, lista[i].dias_semana, lista[i].horario, lista[i].cant_inscripto);
	}
}

void mostrarActividadDisponible(struct actividad lista[]) {
	printf("---------------------------------------------------\n");
	printf("CUPOS DISPONIBLES\n");
	printf("Nombre\tCupo\tDias de la semana\tHorario\tCant. Inscriptos\n");
	for (int i = 0; i < 3; i++) {
		if (lista[i].cant_inscripto < lista[i].cupo) {
			printf("%s\t%d\t%s\t%s\t%d\n", lista[i].nombre, lista[i].cupo, lista[i].dias_semana, lista[i].horario, lista[i].cant_inscripto);
		}
	}
}
