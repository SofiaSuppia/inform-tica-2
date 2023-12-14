#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *link;
};

int menu();
void push(struct node **, struct node **, int);
void pop(struct node **, struct node **);
void print(struct node *);

int main(int argc, char *argv[]) {
	struct node *front = NULL; // Puntero al primer nodo de la cola (inicialmente nulo)
	struct node *back = NULL;  // Puntero al ultimo nodo de la cola (inicialmente nulo)
	int dato = 0, op = 0;
	do {
		op = menu(); // Mostrar el menu y obtener la opcion del usuario
		switch (op) {
		case 1:
			printf("Ingrese el dato a insertar\n");
			scanf("%d", &dato);
			push(&front, &back, dato); // Llamar a la funcion push para agregar un nodo
			break;
		case 2:
			pop(&front, &back); // Llamar a la funcion pop para eliminar un nodo
			break;
		case 3:
			print(front); // Llamar a la funcion print para imprimir la cola
			break;
		}
	} while (op != 4); // Continuar hasta que el usuario elija salir (opcion 4)
	return 0;
}

// Funcion para mostrar el menu y obtener la opcion del usuario
int menu(void){
	int op=0;
	do{
		printf("\n1.- Agregar un nodo\n");
		printf("2.- Borrar un nodo\n");
		printf("3.- Imprimir cola\n");
		printf("4.- Salir\n");
		scanf("%d", &op);
	}while((op<1)||(op>4));
	return op;
}

// Funcion para agregar un nodo a la cola
void push(struct node **front, struct node **back, int d){
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node)); // Asignacion de memoria para el nuevo nodo
	if(temp==NULL){
		printf("No hay suficiente memoria");
		exit(0);
	}
	temp->data=d; // Asignar el dato al nuevo nodo
	temp->link=NULL;
	if(*back==NULL){ //Insercion del primer nodo
		*back=temp;
		*front=*back;
	}else{ //Insercion del resto de los nodos
		(*back)->link =temp;
		*back=temp;
	}
}

// Funcion para eliminar un nodo de la cola
void pop(struct node **front, struct node **back){
	struct node *temp;
	if((*front==*back)&&(*back==NULL)){
		printf("Vacia\n");
		exit(0);
	}
	temp=*front;
	*front = (*front)->link;
	if(*back==temp){
		*back=(*back)->link;
	}
	free(temp);
}

// Funcion para imprimir la cola
void print(struct node *front){
	struct node *temp = NULL;
	//Impresion de toda la FIFO
	temp=front;
	while(temp!=NULL){
		printf("%d -> ", temp->data);
		temp=temp->link;
	}
	printf("\n");
}
