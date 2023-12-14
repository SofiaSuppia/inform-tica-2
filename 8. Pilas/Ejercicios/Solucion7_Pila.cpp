/*Desarrollar un programa que cree una pila de vehiculos que pasan por un peaje, 
en la cual se deben registrar patente, cantidad de ejes, precio, 
direccion. El precio es segun la cantidad de ejes. 
(1 eje = $100, 2 ejes = $150, 3 ejes = $200 y 4 ejes o mas $300). 
La direccion es a la que se dirige el vehiculo, en este caso puede ser de Norte 
a Sur (NS) o Sur a Norte (SN). Luego, arme un menu de opciones que muestre lo siguiente: 
- Agregar un vehiculo a la pila
- Borrar el ultimo nodo de la pila.
- Mostrar todos los vehiculos. 
- Mostrar los vehiculos por direccion.
. Mostrar los vehiculos por ejes. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

struct vehicle{
	int patent;
	int amount;
	float price;
	char direction[3];
};

struct node{
	struct vehicle v;
	struct node *next;
};

/*Prototipado de funciones*/
int menu(void);
void push(struct node **, struct vehicle);
void pop(struct node **);
void print(struct node **);
bool isempty(struct node *);
void print_direction(struct node **);
void print_axis(struct node **);


int main(int argc, char *argv[]) {
	int op=0;
	struct node *stack_p =NULL;
	struct vehicle v;
	
	do{
		op=menu();
		switch(op){
			case 1:
			{
				printf("Ingrese un vehiculo:\nPatente: ");
				scanf("%d", &v.patent);
				printf("Cantidad de ejes: ");
				scanf("%d", &v.amount);
				switch(v.amount){
				case 1: 
					v.price=100;
					break;
				case 2: 
					v.price=150;
					break;
				case 3: 
					v.price=200;
					break;
				default: 
					v.price=300;
				}
				printf("Direccion [NS o SN]: ");
				scanf("%s", v.direction);
				push(&stack_p, v);
				break;
			}
			case 2:
			{
				pop(&stack_p);
				break;
			}
			case 3:
			{
				print(&stack_p);
				break;
			}
			case 4:
			{
				print_direction(&stack_p);
				break;
			}
			case 5:
			{
				print_axis(&stack_p);
				break;
			}
		}
	} while(op<6);
	return 0;
}

int menu(void){
	int op=0;
	do{
		printf("--------------------------------------------\n");
		printf("1.- Agregar un nodo a la pila (vehiculos)\n");
		printf("2.- Borrar el ultimo nodo de la pila\n");
		printf("3.- Imprimir pila\n");
		printf("4.- Mostrar los vehiculos por direccion\n");
		printf("5.- Mostrar los vehiculos por ejes\n");
		printf("6.- Salir\n");
		scanf("%d", &op);
		printf("--------------------------------------------\n");
	}while((op<1)||(op>6));
	return op;
}
	
void push(struct node **sp, struct vehicle v){

	struct node *new_node = NULL;
	/* Creacion de memoria*/
	new_node = (struct node*)malloc(sizeof(struct node));
	/*Verificacion de memoria disponible*/
	if(new_node==NULL){
		printf("No hay memoria disponible");
		exit(0);
	}
	/*Carga util*/
	new_node->v=v;
	/*Asignamos el siguiente del nuevo nodo al stack pointer actual*/
	new_node->next=*(sp);
	/*Ahora el nuevo nodo es el stackptr*/
	*(sp)=new_node;	
}
	
bool isempty(struct node *sp){
	if(sp==NULL)
		return(true);
	else
		return(false);
}

void pop(struct node **sp){
	if(isempty(*sp)==false){
		struct node *temp=NULL;	
		/*Asignamos en temp el stack pointer actual*/
		temp=*(sp);
		/*Asignamos al stack pointer, el valor siguiente del primer nodo*/
		*(sp)=(*sp)->next;
		/*Liberamos la memoria ocupada por el primer nodo*/
		free(temp);	
	}else{
		printf("Pila vacia\n");
	}
}

void print(struct node **sp){
	if(isempty(*sp)==false){
		printf("Impresion de la pila\n");
		printf("Pat.\tCant.\tPrec.\tDirec.\n");
		/*Comenzamos a recorrer desde el stack pointer*/
		struct node *temp;
		temp=*(sp);
		while(temp!=NULL){
			printf("%d\t%d\t%.2f\t%s\n", temp->v.patent, temp->v.amount, temp->v.price, temp->v.direction);
			temp = temp->next;
			/*Recordar que el ultimo nodo de la stack, en siguiente apunta a NULL*/
		}
	}else{
		printf("Pila vacia\n");
	}
}
	
void print_direction(struct node **sp){
	struct node *temp;
	temp=*(sp);
	printf("Impresion de la pila por direccion NS\n");
	printf("Pat.\tCant.\tPrec.\n");
	while(temp!=NULL){
		if (strcmp(temp->v.direction, "NS") == 0) {
			printf("%d\t%d\t%.2f\n", temp->v.patent,temp->v.amount,temp->v.price);
		}
		temp=temp->next;
	}
	temp=*(sp);
	printf("\nImpresion de la pila por direccion SN\n");
	printf("Pat.\tCant.\tPrec.\n");
	while(temp!=NULL){
		if (strcmp(temp->v.direction, "SN") == 0) {
			printf("%d\t%d\t%.2f\n", temp->v.patent,temp->v.amount,temp->v.price);
		}
		temp=temp->next;
	}
}
		
void print_axis(struct node **sp){
	struct node *temp;
	temp=*(sp);
	printf("Impresion de la cola con 1 eje\n");
	printf("Pat.\tPrec.\tDirec.\n");
	while(temp!=NULL){
		if(temp->v.amount==1){
			printf("%d\t%.2f\t%s\n", temp->v.patent,temp->v.price,temp->v.direction);
		}
		temp=temp->next;
	}
	temp=*(sp);
	printf("\nImpresion de la cola con 2 eje\n");
	printf("Pat.\tPrec.\tDirec.\n");
	while(temp!=NULL){
		if(temp->v.amount==2){
			printf("%d\t%.2f\t%s\n", temp->v.patent,temp->v.price,temp->v.direction);
		}
		temp=temp->next;
	}
	temp=*(sp);
	printf("\nImpresion de la cola con 3 eje\n");
	printf("Pat.\tPrec.\tDirec.\n");
	while(temp!=NULL){
		if(temp->v.amount==3){
			printf("%d\t%.2f\t%s\n", temp->v.patent,temp->v.price,temp->v.direction);
		}
		temp=temp->next;
	}
	temp=*(sp);
	printf("\nImpresion de la cola con 4 eje o mas\n");
	printf("Pat.\tCant.\tPrec.\tDirec.\n");
	while(temp!=NULL){
		if(temp->v.amount>=4){
			printf("%d\t%d\t%.2f\t%s\n", temp->v.patent,temp->v.amount,temp->v.price,temp->v.direction);
		}
		temp=temp->next;
	}
}
