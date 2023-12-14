/*Elaborar un sistema de stock, en la cual posee una cola de productos 
con los siguientes atributos: codigo, nombre, cantidad, precio lista. 
Desarrollar las siguientes funciones:
- Agregar un nuevo producto.
- Borrar el primer nodo de la cola.
- Mostrar el stock. 
- Descontar stock.
- Reponer stock.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct product{
	int code;
	char name[10];
	int amount;
	float price;
};

struct node{
	struct product p;
	struct node *link;
};

int menu();
void push(struct node **, struct node **, struct product);
void pop(struct node **, struct node **);
void print(struct node *);
void discount(struct node *, int, int);
void replace(struct node *, int, int);

int main(int argc, char *argv[]) {
	
	struct node *front = NULL;
	struct node *back = NULL;
	struct product p;
	int op=0, code=0, amount=0;
	do{
		op=menu();
		switch(op){
		case 1: 
			printf("Ingrese un producto:\nCodigo: ");
			scanf("%d", &p.code);
			printf("Nombre: ");
			scanf(" %s", p.name);
			printf("Cantidad: ");
			scanf("%d", &p.amount);
			printf("Precio: ");
			scanf("%f", &p.price);
			push(&front, &back, p);
			break;
		case 2: 
			pop(&front, &back);
			break;
		case 3: 
			print(front);
			break;
		case 4: 
			printf("Ingrese el codigo del producto y la cantidad a descontar:\n");
			scanf("%d%d", &code, &amount);
			discount(front, code, amount);
			break;
		case 5:
			printf("Ingrese el codigo del producto y la cantidad a descontar:\n");
			scanf("%d%d", &code, &amount);
			replace(front, code, amount);
			break;
		}
	} while(op<6);
	return 0;
}

int menu(void){
	int op=0;
	do{
		printf("--------------------------------------------\n");
		printf("1.- Agregar un nodo a la cola (producto)\n");
		printf("2.- Borrar el primer nodo de la cola\n");
		printf("3.- Imprimir cola\n");
		printf("4.- Descontar stock\n");
		printf("5.- Reponer stock\n");
		printf("6.- Salir\n");
		scanf("%d", &op);
		printf("--------------------------------------------\n");
	}while((op<1)||(op>6));
	return op;
}
	
void push(struct node **front, struct node **back, struct product p){
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	if(temp==NULL){
		printf("No hay suficiente memoria");
		exit(0);
	}
	temp->p=p;
	temp->link=NULL;
	if(*back==NULL){ //Insercion del primer nodo
		*back=temp;
		*front=*back;
	}else{ //Insercion del resto de los nodos
		(*back)->link =temp;
		*back=temp;
	}
}
		
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
	printf("Primer nodo borrado de la cola\n");
	free(temp);
}
			
void print(struct node *front){
	struct node *temp = NULL;
	temp=front;
	printf("Impresion de la cola\n");
	printf("Cod.\tNombre\tCant.\tPrecio\n");
	while(temp!=NULL){
		printf("%d\t%s\t%d\t%f\n", temp->p.code, temp->p.name, temp->p.amount, temp->p.price);		
		temp=temp->link;
	}
}

void discount(struct node *front, int code, int amount){
	struct node *temp = NULL;
	temp=front;
	while(temp!=NULL){
		if(temp->p.code==code){
			temp->p.amount=temp->p.amount-amount;
		}
		temp=temp->link;
	}
}

void replace(struct node *front, int code, int amount){
	struct node *temp = NULL;
	temp=front;
	while(temp!=NULL){
		if(temp->p.code==code){
			temp->p.amount=temp->p.amount+amount;
		}
		temp=temp->link;
	}
}
