//EJEMPLO DE IMPLEMENTACION CON FUNCIONES 
//LISTA SIMPLEMENTE ENLAZADAS

#include <iostream>
using namespace std;

struct node{
	int data;
	struct node *next;
};

//PROTOTIPOS DE LAS FUNCIONES 
void menu();
void push(struct node **, int);  //ESTA ES LA MEJOR FORMA ..PERO NO LA UNICA ,AQUI ESTAMOS PASANDO A LA FUNCION UN PUNTERO ,(Y PARA QUE LA FUNCION NO VAYA )
void append(struct node **, int);  //A ESTAR MODIFICANDO EL PUNTERO QUE LE PASE..,(RECORDEMOS ,SI PASO POR VALOR ESTE NO PUEDE SER MODIFICADO,AHORA SI PASO )
void print_list(struct node *);		//POR PUNTERO ,ESTE SI PUEDE SER MODIFICADO (ELEMNTO AL QUE APUNTA , EN ESTE CASO ,ESTRUCTURA NODO..)
									//ENTONCES LE PONEMOS UN PUNTERO DOBLE ,(DE ESTA FORMA NO SE TRABAJRA CON EL PUNTERO SIMPLE ,ESTARA A SALVO DE MOFICACIONES,
								//Y TRABAJAREMOS CON SU PUNTERO DOBLE (SOLO EN LAS FUNCIONES..),PUNTERO DOBLE:"PUNTERO QUE APUNTA A OTRO PUNTERO","PUNTERO DE UN PUNTERO"..
int main(int argc, char *argv[]) {
	
	int dato=0, op=0;	
	struct node* head=NULL;
	
	do{
		menu();
		scanf("%d", &op);
		switch(op){
		case 1: 
			printf("Ingrese un dato\n");
			scanf("%d", &dato);
			append(&head,dato);
			break;
		case 2: 
			printf("Ingrese un dato\n");
			scanf("%d", &dato);
			push(&head,dato);            //PASAMOS LA DIRECCION DE MEMORIA DE UN PUNTERO , EL PUNTERO HEAD 
			break;
		case 3: 
			print_list(head);
			break;
		}
	}while(op!=4);
	return 0;
}

void menu(void){
	printf("\n1.- Agregar un nodo al final\n");
	printf("2.- Agregar un nodo al comienzo\n");
	printf("3.- Impresion de la lista\n");
	printf("4.- Salir\n");
}

void push(struct node ** head, int node_data){          //usamos lo que ya comentamos de puntero dobles 
	struct node * new_node=NULL;
	new_node = (struct node*)malloc(sizeof(struct node));
	if(new_node==NULL){
		printf("No hay memoria disponible");
		exit(0);
	}
	new_node->data =node_data;
	new_node->next=(*head);
	(*head)=new_node;
}


void append(struct node **head, int node_data){
	struct node* new_node = NULL;
	new_node = (struct node*)malloc(sizeof(struct node));
	if(new_node==NULL){
		printf("No hay memoria disponible");
		exit(0);
	}
	struct node *temp=*head;
	new_node->data =node_data;
	new_node->next=NULL;
	if(*head == NULL){
		*head=new_node;
		return;
	}
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=new_node;
}
	
void print_list(struct node *head){
	struct node *temp=NULL;
	temp=head;
	printf("Lista completa\n");
	while(temp!=NULL){
		printf("%d\t", temp->data);
		temp=temp->next;
	}
}
