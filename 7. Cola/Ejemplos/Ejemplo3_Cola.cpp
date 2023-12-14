#include <stdio.h>
#include <stdlib.h>

// Definicion de la estructura persona
struct persona {
	char nombre[10];
	int edad;
};

// Definicion de la estructura del nodo
struct node {
	struct persona p;
	struct node *link;
};

// Prototipos de funciones
int menu();
void push(struct node **, struct node **, struct persona);
void pop(struct node **, struct node **);
void print(struct node *);

int main(int argc, char *argv[]) {
	struct node *front = NULL;
	struct node *back = NULL;
	int op = 0;
	struct persona p;
	
	do {
		op = menu(); // Mostrar el menu y obtener la opcion del usuario
		
		switch(op) {
		case 1:
			printf("Ingrese el nombre y la edad de la persona a insertar\n");
			scanf("%s %d", p.nombre, &p.edad); // Leer el nombre y la edad de la persona
			push(&front, &back, p); // Llamar a la funcion push para agregar una persona
			break;
		case 2:
			pop(&front, &back); // Llamar a la funcion pop para eliminar una persona
			break;
		case 3:
			print(front); // Llamar a la funcion print para imprimir la cola de personas
			break;
		}
	} while(op != 4); // Continuar hasta que el usuario elija salir (opcion 4 en el menu)
	
	return 0;
}

// Funcion para mostrar el menu y obtener la opcion del usuario
int menu(void) {
	int op = 0;
	do {
		printf("\n1.- Agregar una persona a la cola\n");
		printf("2.- Borrar una persona de la cola\n");
		printf("3.- Imprimir cola de personas\n");
		printf("4.- Salir\n");
		scanf("%d", &op); // Leer la opcion del usuario
	} while((op < 1) || (op > 4));
	return op;
}

// Funcion para agregar una persona a la cola
void push(struct node **front, struct node **back, struct persona p) {
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node)); // Asignacion de memoria para el nuevo nodo
	if (temp == NULL) {
		printf("No hay suficiente memoria");
		exit(0);
	}
	temp->p = p; // Asignar la persona al nuevo nodo
	temp->link = NULL;
	if (*back == NULL) { // Insercion del primer nodo
		*back = temp;
		*front = *back;
	} else { // Insercion del resto de los nodos
		(*back)->link = temp;
		*back = temp;
	}
}

// Funcion para eliminar una persona de la cola
void pop(struct node **front, struct node **back) {
	struct node *temp;
	if ((*front == *back) && (*back == NULL)) {
		printf("Vacia\n");
		exit(0);
	}
	temp = *front;
	*front = (*front)->link;
	if (*back == temp) {
		*back = (*back)->link;
	}
	free(temp); // Liberar la memoria del nodo eliminado
}

// Funcion para imprimir la cola de personas
void print(struct node *front) {
	struct node *temp = NULL;
	// Impresion de toda la cola de personas
	temp = front;
	while (temp != NULL) {
		printf("%s\t%d\n", temp->p.nombre, temp->p.edad);
		temp = temp->link;
	}
	printf("\n");
}
