/*Restaurante

Desarrolla un programa para gestionar los datos de un restaurante mediante un TDA Lista. 
El TDA debe contener la informacion de los platos disponibles, incluyendo nombre del plato, 
cantidad de platos disponibles (entero), cantidad de platos vendidos (entero) y precio (decimal). 
Implementa las siguientes funciones para:
- Insertar un nuevo plato en el menu.
- Mostrar el menu por consola y generar un archivo txt llamado "menu.txt".
- Eliminar un plato del menu.
- Calcular la recaudacion total de los platos vendidos.
- Ordenar los platos por precio usando quicksort.
Ademas, crea un menu de opciones para que el usuario pueda interactuar con el programa.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definicion de la estructura plato
struct plato {
	char nombre[50];
	int cantidadDisponible;
	int cantidadVendida;
	float precio;
};

// Definicion de la estructura node
struct node {
	struct plato p;
	struct node *next;
};

struct node *agregar_plato(struct node *head, struct plato p);
void mostrar_menu(struct node *head);
void generar_archivo(struct node *head);
struct node *eliminar_plato(struct node *head, char *nombre);
float calcular_recaudacion(struct node *head);
void liberar_memoria(struct node *head);
int contar_nodo(struct node *head);
void pasar_lista_ptr(struct node *head, struct plato *v);
void ordenarQuicksort(struct plato *v, int inicio, int fin);
int dividir(struct plato *v, int inicio, int fin);
void pasar_lista_ptr(struct node *head, struct plato *v);

// Funcion principal
int main() {
	
	struct plato nuevoPlato;
	struct node *head = NULL;
	
	int opcion;
	do {
		printf("\n1. Agregar nuevo plato al menu\n");
		printf("2. Mostrar el menu\n");
		printf("3. Eliminar un plato\n");
		printf("4. Calcular recaudacion total\n");
		printf("5. Ordenar platos por precio\n");
		printf("0. Salir\n");
		printf("Seleccione una opcion: ");
		scanf("%d", &opcion);
		
		switch (opcion) {
		case 1: //Agregar plato al menu
		{	
			printf("Ingrese el nombre del plato (terminar con punto): ");
			scanf("%49[^.]", nuevoPlato.nombre);
			getchar();
			
			printf("Ingrese la cantidad disponible: ");
			scanf("%d", &nuevoPlato.cantidadDisponible);
			printf("Ingrese la cantidad vendida: ");
			scanf("%d", &nuevoPlato.cantidadVendida);
			printf("Ingrese el precio: ");
			scanf("%f", &nuevoPlato.precio);
			
			head = agregar_plato(head, nuevoPlato);
		}	
			break;
		case 2: // Mostrar el menu
		{
			mostrar_menu(head);
			generar_archivo(head);
		}
		break;
		case 3: // Eliminar un plato
		{
			char nombreEliminar[50];
			printf("Ingrese el nombre del plato a eliminar (terminar con punto): ");
			scanf("%49[^.]", nombreEliminar);
			getchar();
			head = eliminar_plato(head, nombreEliminar);
		}
		break;
		case 4:// Calcular recaudacion total
		{	
			printf("Recaudacion total: %.2f\n", calcular_recaudacion(head));
		}
		break;
		case 5: // Ordenar platos por precio usando quicksort
		{	
			if (contar_nodo(head) > 1) {
				struct plato *v = (struct plato*)malloc(contar_nodo(head) * sizeof(struct plato));
				
				if (v == NULL) {
					printf("No hay suficiente espacio de memoria.\n");
					exit(1);
				}
				pasar_lista_ptr(head, v);
				ordenarQuicksort(v, 0, contar_nodo(head) - 1);
				printf("Platos ordenados por precio.\n");
				for (int i = 0; i < contar_nodo(head); i++) {
					printf("%-20s %-20d %-20d %-10.2f\n", v[i].nombre, v[i].cantidadDisponible, v[i].cantidadVendida, v[i].precio);
				}
				free(v);
			}
		}
		break;
		case 0:// Salir del programa
			liberar_memoria(head);
			printf("Saliendo del programa.\n");
			break;
			
		default:
			printf("Opcion no valida.\n");
		}
		
	} while (opcion != 0);
	
	return 0;
}

// Funcion para agregar un nuevo plato al menu
struct node *agregar_plato(struct node *head, struct plato p) {
	// Crear un nuevo nodo
	struct node *nuevoNodo = (struct node *)malloc(sizeof(struct node));
	// Verificar si se asignÃ³ correctamente la memoria
	if (nuevoNodo == NULL) {
		printf("No hay suficiente espacio de memoria.\n");
		exit(1);
	}
	// Asignar el plato al nuevo nodo
	nuevoNodo->p = p;
	// Establecer el siguiente nodo como el actual encabezado del menu
	nuevoNodo->next = head;
	// Devolver el nuevo nodo como el nuevo encabezado del menu
	return nuevoNodo;
}

void mostrar_menu(struct node *head) {
	// Verificar si el menu esta vacio (head es NULL)
	if (head == NULL) {
		printf("El menu esta vacio.\n");
		return;
	}
	// Crear un puntero temporal para recorrer la lista
	struct node *temp = head;
	// Imprimir encabezado del menu
	printf("\nMenu:\n");
	printf("%-20s%-20s%-20s%-20s\n", "Nombre del plato", "Cant. Disponible", "Cant. Vendida", "Precio");
	// Recorrer la lista e imprimir cada plato
	while (temp != NULL) {
		printf("%-20s%-20d%-20d%-20.2f\n", temp->p.nombre, temp->p.cantidadDisponible, temp->p.cantidadVendida, temp->p.precio);
		// Mover al siguiente nodo
		temp = temp->next; 
	}
}


// Generar un archivo "menu.txt
void generar_archivo(struct node *head) {
	// Abrir el archivo "menu.txt" en modo escritura
	FILE *fp = fopen("menu.txt", "w");
	// Verificar si se pudo abrir correctamente el archivo
	if (fp == NULL) {
		printf("El archivo no ha podido ser creado.\n");
		exit(1);
	}
	// Escribir el encabezado en el archivo
	fprintf(fp, "%-20s\t%-20s\t%-20s\t%-20s\n", "Nombre del plato", "Cant. Disponible", "Cant. Vendida", "Precio");
	// Crear un puntero temporal para recorrer la lista
	struct node *temp = head;
	// Recorrer la lista e imprimir cada plato en el archivo
	while (temp != NULL) {
		fprintf(fp, "%-20s\t%-20d\t%-20d\t%-20.2f\n", temp->p.nombre, temp->p.cantidadDisponible, temp->p.cantidadVendida, temp->p.precio);
		// Mover al siguiente nodo
		temp = temp->next;
	}
	// Cerrar el archivo despues de escribir
	fclose(fp);
	// Imprimir un mensaje indicando que el menu ha sido guardado en el archivo
	printf("\nEl menu ha sido guardado en el archivo 'menu.txt'.\n");
}

// Funcion para eliminar un plato del menu
struct node *eliminar_plato(struct node *head, char *nombre) {
	// Inicializar punteros para recorrer la lista
	struct node *current = head;
	struct node *prev = NULL;
	// Recorrer la lista mientras no se llegue al final
	while (current != NULL) {
		// Verificar si el nombre del plato en el nodo actual es igual al nombre proporcionado
		if (strcmp(current->p.nombre, nombre) == 0) {
			// Verificar si el nodo a eliminar es el primer nodo de la lista
			if (prev == NULL) {
				// El plato a eliminar es el primer nodo, actualizar la cabeza de la lista
				head = current->next;
			} else {
				// El nodo a eliminar no es el primer nodo, actualizar el puntero del nodo anterior
				prev->next = current->next;
			}
			// Imprimir mensaje indicando que el plato ha sido eliminado
			printf("Plato eliminado: %s\n", nombre);
			// Liberar la memoria del nodo eliminado
			free(current);
			// Devolver la cabeza de la lista actualizada
			return head;
		}
		// Avanzar al siguiente nodo en la lista
		prev = current;
		current = current->next;
	}
	// Si se llega aqui, el plato no fue encontrado en la lista
	printf("Plato no encontrado: %s\n", nombre);
	// Devolver la cabeza de la lista sin cambios
	return head;
}

// Funcion para calcular la recaudacion total de los platos vendidos
float calcular_recaudacion(struct node *head){
	float recaudacionTotal = 0;
	struct node *temp = head;
	while (temp != NULL) {
		recaudacionTotal += (temp->p.cantidadVendida * temp->p.precio);
		temp = temp->next;
	}
	return recaudacionTotal;
}
	
void liberar_memoria(struct node *head) {
	// Declara un puntero temporal para almacenar el nodo actual a liberar
	struct node *temp;
	// Itera sobre la lista mientras el nodo inicial (head) no sea NULL
	while (head != NULL) {
		// Almacena la referencia al nodo actual en el puntero temporal
		temp = head;
		// Mueve el puntero al siguiente nodo en la lista
		head = head->next;
		// Libera la memoria del nodo actual
		free(temp);
	}
}

int contar_nodo(struct node *head) {
	int cantidad = 0;
	struct node *temp = head;
	while (temp != NULL) {
		cantidad++;
		temp = temp->next;
	}
	return cantidad;
}

// Funcion para pasar la lista a un puntero de estructura
void pasar_lista_ptr(struct node *head, struct plato *v) {
	int i = 0;
	struct node *temp = head;
	while (temp != NULL) {
		v[i++] = temp->p;
		temp = temp->next;
	}
}

// Función recursiva para hacer el Ordenamiento Quicksort
void ordenarQuicksort(struct plato *v, int inicio, int fin) {
	int pivote = 0;
	// Verifica si hay mas de un elemento en el puntero. 
	//Si hay solo un elemento o ninguno, el puntero ya esta ordenado.
	if (inicio < fin) {
		// Llama a la funcion dividir para obtener la posicion del pivote
		pivote = dividir(v, inicio, fin);
		// Ordeno la lista de los menores que el pivote
		ordenarQuicksort(v, inicio, pivote - 1);
		// Ordeno la lista de los mayores que el pivote
		ordenarQuicksort(v, pivote + 1, fin);
	}
}

// Funcion para dividir el puntero y hacer los intercambios
int dividir(struct plato *v, int inicio, int fin) {
	// Elige el primer elemento como pivote
	struct plato pivote = v[inicio];
	//Inicializa dos indices, izq y der, que se moveran hacia el centro del puntero
	int izq = inicio + 1;
	int der = fin;
	// Realiza el proceso de particionamiento buscando elementos mayores y 
	// menores que el pivote y realizando intercambios.
	while (izq <= der) {
		// Encuentra el primer elemento desde la izquierda mayor que el pivote
		while (izq <= der && v[izq].precio <= pivote.precio) {
			izq++;
		}
		// Encuentra el primer elemento desde la derecha menor que el pivote
		while (v[der].precio > pivote.precio) {
			der--;
		}
		// Si aun no se cruzan los i­ndices, intercambia los elementos
		if (izq < der) {
			// Intercambio de elementos
			struct plato aux = v[izq];
			v[izq] = v[der];
			v[der] = aux;
		}
	}
	
	// Pone el pivote en su posicion final despues de los intercambios
	struct plato aux = v[der];
	v[der] = pivote;
	v[inicio] = aux;
	
	// Devuelve la nueva posicion del pivote
	return der;
}




