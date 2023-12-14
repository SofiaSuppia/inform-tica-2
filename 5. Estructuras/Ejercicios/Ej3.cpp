/*Crear un programa que gestione el listado de los empleados de la empresa. 
Para ello crear una estructura Empleado, en la cual contenga los siguientes 
datos: legajo, puesto de trabajo, sueldo y anios_antiguedad. Luego, crear un 
vector de estructuras del tipo empleado de tamanio 3. Crear un menu que 
permita las opciones: 

a. agregar un empleado
b. mostrar todos los empleados
c. buscar un empleado por legajo para ver si existe o no.
d. actualizarSueldo(float porcentaje)
e. ordenar por sueldo
f. ordenar por anios_antiguedad
 

*/
#include <stdio.h>

struct empleado
{
	int legajo;
	char puesto[100];
	float sueldo;
	int anios_antiguedad;
};

void agregar(struct empleado[]);
void mostrar(struct empleado[]);
int existe_legajo(struct empleado[]);
void actualizarSueldo(struct empleado[]);
void ordenarSueldo(int, struct empleado[]);
void ordenarAntiguedad(int, struct empleado[]);

int main() {
	
	struct empleado lista[3];
	
	char op = ' ';
	
	do {
		printf("---------------------------------------------------\n");
		printf("MENU DE OPCIONES\n");
		printf("a. Agregar.\nb. Mostrar.\nc. Buscar.\nd. Actualizar Sueldo.\ne. Ordenar por Sueldo.\nf. Ordenar por Anios de Antiguedad.\n");
		scanf(" %c", &op);
		getchar();
		
		switch (op) {
		case 'a':
			agregar(lista);
			break;
		case 'b':
			mostrar(lista);
			break;
		case 'c':
			printf("%s\n", existe_legajo(lista) ? "LEGAJO ENCONTRADO" : "LEGAJO NO ENCONTRADO");
			break;
		case 'd':
			actualizarSueldo(lista);
			mostrar(lista);
			break;
		case 'e':
			ordenarSueldo(3, lista);
			mostrar(lista);
			break;
		case 'f':
			ordenarAntiguedad(3, lista);
			mostrar(lista);
			break;
		}
		
		printf("\nÂ¿Desea seguir (S/N)? ");
		scanf(" %c", &op);
		
	} while (op == 's' || op == 'S');
	
	return 0;
}

void agregar(struct empleado lista[]) {
	printf("---------------------------------------------------\n");
	for (int i = 0; i < 3; i++) {
		printf("\nINGRESE LOS DATOS DE EMPLEADO Nº%d:\n", i + 1);
		printf("legajo: ");
		scanf("%d", &lista[i].legajo);
		printf("Puesto: ");
		scanf("%s", lista[i].puesto);
		printf("Sueldo: ");
		scanf("%f", &lista[i].sueldo);
		printf("Anios de antiguedad: ");
		scanf("%d", &lista[i].anios_antiguedad);
	}
}

void mostrar(struct empleado lista[]) {
	printf("---------------------------------------------------\n");
	printf("Leg.\tPuesto\t\tSueldo\t\tAntiguedad\n");
	for (int i = 0; i < 3; i++) {
		printf("%d\t%s\t\t%.2f\t\t%d\n", lista[i].legajo, lista[i].puesto, lista[i].sueldo, lista[i].anios_antiguedad);
	}
}

int existe_legajo(struct empleado lista[]) {
	printf("---------------------------------------------------\n");
	int buscar_legajo = 0;
	printf("INGRESE EL LEGAJO A BUSCAR:\n");
	scanf("%d", &buscar_legajo);
	for (int i = 0; i < 3; i++) {
		if (buscar_legajo == lista[i].legajo) {
			return 1;
		}
	}
	return 0;
}

void actualizarSueldo(struct empleado lista[]) {
	printf("Ingrese el porcentaje de aumento de sueldo: %%\n");
	float porcentaje = 0;
	scanf("%f", &porcentaje);
	for (int i = 0; i < 3; i++) {
		lista[i].sueldo = lista[i].sueldo + (porcentaje * lista[i].sueldo) / 100;
	}
}

void ordenarSueldo(int tamano, struct empleado lista[]) {
	//orden ascendente
	int i = 0, j = 0;
	struct empleado e;
	for (i = 0; i < tamano - 1; i++) { 
		for (j = 0; j < tamano - 1; j++) {
			if (lista[j].sueldo > lista[j + 1].sueldo) {
				e = lista[j];
				lista[j] = lista[j + 1];
				lista[j + 1] = e;
			}
		}
	}
}

void ordenarAntiguedad(int tamano, struct empleado lista[]) {
	//orden descendente
	int i = 0, j = 0;
	struct empleado e;
	for (i = 0; i < tamano; i++) {
		for (j = 0; j < tamano - 1; j++) { 
			if (lista[j].anios_antiguedad < lista[j + 1].anios_antiguedad) {
				e = lista[j + 1];
				lista[j + 1] = lista[j];
				lista[j] = e;
			}
		}
	}
}
