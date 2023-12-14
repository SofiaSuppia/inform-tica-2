/*Crear un programa con el siguiente menu de opciones: 
- Agregar un nodo a la cola. (se deben agregar 5 valores)
- Borrar el primer nodo de la cola.
- Imprimir cola.
- Suma de los valores de la cola.
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;         // Valor almacenado en el nodo
	struct node *link; // Puntero al siguiente nodo en la cola
};

// Prototipos de funciones
int menu();                         // Funcion para mostrar el menu y obtener la opcion del usuario
void push(struct node **, struct node **, int);  // Funcion para agregar un nodo a la cola
void pop(struct node **, struct node **);         // Funcion para eliminar el primer nodo de la cola
void print(struct node *);                        // Funcion para imprimir la cola
int add(struct node *);                           // Funcion para calcular la suma de los valores en la cola

int main(int argc, char *argv[]) {
	struct node *front = NULL;  // Puntero al primer nodo de la cola (inicialmente nulo)
	struct node *back = NULL;   // Puntero al ultimo nodo de la cola (inicialmente nulo)
	int value = 0, op = 0, i = 0;
	
	do {
		op = menu();  // Mostrar el menu y obtener la opcion del usuario
		
		switch(op) {
		case 1: 
			for(i = 0; i < 5; i++) {
				printf("Ingrese el dato a insertar\n");
				scanf("%d", &value);
				push(&front, &back, value);  // Llamar a la funcion push para agregar un nodo a la cola
			}
			break;
		case 2: 
			pop(&front, &back);  // Llamar a la funcion pop para eliminar el primer nodo de la cola
			break;
		case 3: 
			print(front);  // Llamar a la funcion print para imprimir la cola
			break;
		case 4: 
			printf("Suma: %d\n", add(front));  // Llamar a la funcion add para calcular la suma de los valores en la cola
			break;
		}
	} while(op < 5);  // Continuar hasta que el usuario elija salir (opcion 5 en el menu)
	
	return 0;
}

// Funcion para mostrar el menu y obtener la opcion del usuario
int menu(void) {
	int op = 0;
	do {
		printf("--------------------------------------------\n");
		printf("1.- Agregar un nodo a la cola\n");
		printf("2.- Borrar el primer nodo de la cola\n");
		printf("3.- Imprimir cola\n");
		printf("4.- Suma de los valores de la cola\n");
		printf("5.- Salir\n");
		scanf("%d", &op);  // Leer la opcion del usuario
		printf("--------------------------------------------\n");
	} while((op < 1) || (op > 5));
	return op;
}

// Funcion para agregar un nodo a la cola
void push(struct node **front, struct node **back, int d) {
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));  // Asignacion de memoria para el nuevo nodo
	if(temp == NULL) {
		printf("No hay suficiente memoria");
		exit(0);
	}
	temp->data = d;  // Asignar el dato al nuevo nodo
	temp->link = NULL;
	if(*back == NULL) {  // Insercion del primer nodo
		*back = temp;
		*front = *back;
	} else {  // Insercion del resto de los nodos
		(*back)->link = temp;
		*back = temp;
	}
}

// Funcion para eliminar el primer nodo de la cola
void pop(struct node **front, struct node **back) {
	struct node *temp;
	if((*front == *back) && (*back == NULL)) {
		printf("Vacia\n");
		exit(0);
	}
	temp = *front;
	*front = (*front)->link;
	if(*back == temp) {
		*back = (*back)->link;
	}
	printf("Primer nodo borrado de la cola\n");
	free(temp);  // Liberar la memoria del nodo eliminado
}

// Funcion para imprimir la cola
void print(struct node *front) {
	struct node *temp = NULL;
	temp = front;
	printf("Impresion de la cola\n");
	while(temp != NULL) {
		printf("%d\n", temp->data);
		temp = temp->link;
	}
}

// Funcion para calcular la suma de los valores en la cola
int add(struct node *front) {
	int addition = 0;
	struct node *temp = NULL;
	temp = front;
	while(temp != NULL) {
		addition += temp->data;
		temp = temp->link;
	}
	return addition;
}
