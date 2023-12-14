#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *link;
};

int main(int argc, char *argv[]) {
	
	struct node *front = NULL; // Puntero al primer nodo de la cola (inicialmente nulo)
	struct node *back = NULL;  // Puntero al Ãºltimo nodo de la cola (inicialmente nulo)
	struct node *temp = NULL;  // Puntero temporal para manipular nodos
	int value;
	printf("Ingrese un elemento: \n");
	scanf("%d", &value);
	
	do {
		/* Creacion de un nuevo nodo */
		temp = (struct node *)malloc(sizeof(struct node)); // Asignacion de memoria para un nuevo nodo
		if (temp == NULL) { // Comprobacion de si hay suficiente memoria
			printf("No hay suficiente memoria");
			exit(0);
		} else {
			temp->data = value; // Asignacion del valor ingresado al nodo
			temp->link = NULL;  // Establecimiento del enlace del nodo como nulo
			
			if (back == NULL) { // Insercion del primer nodo
				back = temp;
				front = back;
			} else { // Insercion del resto de los nodos
				back->link = temp;
				back = temp;
			}
			
			printf("0 para salir\n");
			scanf("%d", &value);
		}
	} while (value != 0);
	
	// Impresion de toda la cola
	temp = front;
	while (temp != NULL) {
		printf("%d", temp->data);
		temp = temp->link;
	}
	
	// Eliminacion de nodos
	do {
		if ((front == back) && (back == NULL)) { // Comprobacion de si la cola esta vaci­a
			printf("Vacia");
			exit(0);
		}
		temp = front;           // Nodo a eliminar es el primer nodo de la cola
		front = (front)->link; // Actualizacion del puntero al primer nodo
		if (front == NULL) {
			back = NULL; // Si el nodo eliminado era el ultimo, se actualiza el puntero al ultimo nodo
		}
		free(temp); // Liberacion de la memoria del nodo eliminado
		
		printf("0 para salir\n");
		scanf("%d", &value);
	} while (value != 0);
	
	// Impresion de toda la cola despues de la eliminacion
	temp = front;
	while (temp != NULL) {
		printf("%d", temp->data);
		temp = temp->link;
	}
	free(temp); // Liberacion del puntero temporal
	return 0;
}

