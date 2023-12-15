/*Desarrollo un programa que cree una cola de vehiculos que pasan por un peaje, 
en la cual se deben registrar patente, cantidad de ejes, precio, 
direccion. El precio es segun la cantidad de ejes. 
(1 eje = $100, 2 ejes = $150, 3 ejes = $200 y 4 ejes o mas $300). 
La direccion es a la que se dirige el vehiculo, en este caso puede ser de Norte 
a Sur (NS) o Sur a Norte (SN). Luego, arme un menu de opciones que muestre lo siguiente: 
- Agregar un vehiculo a la cola
- Borrar el primer nodo de la cola.
- Mostrar todos los vehiculos. 
- Mostrar los vehiculos por direccion.
. Mostrar los vehiculos por ejes.
- Generar unarchivo de texto llamado vehiculo.txt donde se muestre todos los vehiculos con sus datos 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct vehicle{
	int patent;
	int amount;
	float price;
	char direction[20];
};

struct node{
	struct vehicle v;
	struct node *link;
};

int menu();
void push(struct node **, struct node **, struct vehicle);
void pop(struct node **, struct node **);
void print(struct node *);
void print_direction(struct node *);
void print_axis(struct node *);

int main(int argc, char *argv[]) {
	
	struct node *front = NULL;
	struct node *back = NULL;
	struct vehicle v;
	int op=0;
	do{
		op=menu();
		switch(op){
		case 1: 
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
			push(&front, &back, v);
			break;
		case 2: 
			pop(&front, &back);
			break;
		case 3: 
			print(front);
			break;
		case 4: 
			print_direction(front);
			break;
		case 5:
			print_axis(front);
			break;
		}
	} while(op<6);
	return 0;
}

int menu(void){
	int op=0;
	do{
		printf("--------------------------------------------\n");
		printf("1.- Agregar un nodo a la cola (vehiculos)\n");
		printf("2.- Borrar el primer nodo de la cola\n");
		printf("3.- Imprimir cola\n");
		printf("4.- Mostrar los vehiculos por direccion\n");
		printf("5.- Mostrar los vehiculos por ejes\n");
		printf("6.- Salir\n");
		scanf("%d", &op);
		printf("--------------------------------------------\n");
	}while((op<1)||(op>6));
	return op;
}
	
void push(struct node **front, struct node **back, struct vehicle v){
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	if(temp==NULL){
		printf("No hay suficiente memoria");
		exit(0);
	}
	temp->v=v;
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
	printf("Pat.\tCant.\tPrec.\tDirec.\n");
	while(temp!=NULL){
		printf("%d\t%d\t%.2f\t%s\n", temp->v.patent, temp->v.amount, temp->v.price, temp->v.direction);
		temp=temp->link;
	}
}

void print_direction(struct node *front){
	struct node *temp = NULL;
	temp=front;
	printf("Impresion de la cola por direccion NS\n");
	printf("Pat.\tCant.\tPrec.\n");
	while(temp!=NULL){
		if(strcmp(temp->v.direction, "NS") == 0){
			printf("%d\t%d\t%.2f\n", temp->v.patent, temp->v.amount, temp->v.price);
		}
		temp=temp->link;
	}
	temp=front;
	printf("\nImpresion de la cola por direccion SN\n");
	printf("Pat.\tCant.\tPrec.\n");
	while(temp!=NULL){
		if(strcmp(temp->v.direction, "SN") == 0){
			printf("%d\t%d\t%.2f\n", temp->v.patent, temp->v.amount, temp->v.price);
		}
		temp=temp->link;
	}
}

void print_axis(struct node *front){
	struct node *temp = NULL;
	temp=front;
	printf("Impresion de la cola con 1 eje\n");
	printf("Pat.\tPrec.\tDirec.\n");
	while(temp!=NULL){
		if(temp->v.amount == 1){
			printf("%d\t%.2f\t%s\n", temp->v.patent, temp->v.price, temp->v.direction);
		}
		temp=temp->link;
	}
	temp=front;
	printf("\nImpresion de la cola con 2 ejes\n");
	printf("Pat.\tPrec.\tDirec.\n");
	while(temp!=NULL){
		if(temp->v.amount == 2){
			printf("%d\t%.2f\t%s\n", temp->v.patent, temp->v.price, temp->v.direction);
		}
		temp=temp->link;
	}
	temp=front;
	printf("\nImpresion de la cola con 3 ejes\n");
	printf("Pat.\tPrec.\tDirec.\n");
	while(temp!=NULL){
		if(temp->v.amount == 3){
			printf("%d\t%.2f\t%s\n", temp->v.patent, temp->v.price, temp->v.direction);
		}
		temp=temp->link;
	}
	temp=front;
	printf("\nImpresion de la cola con 4 ejes o más\n");
	printf("Pat.\tCant.\tPrec.\tDirec.\n");
	while(temp!=NULL){
		if(temp->v.amount >= 4){
			printf("%d\t%d\t%.2f\t%s\n", temp->v.patent, temp->v.amount, temp->v.price, temp->v.direction);
		}
		temp=temp->link;
	}
}
	
