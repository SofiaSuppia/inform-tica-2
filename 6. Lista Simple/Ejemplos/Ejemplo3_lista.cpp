//IMPLEMENTACION CON FUNCIONES 
//LISTA SIMPLEMENTE ENLAZADA



#include <iostream>
using namespace std;

struct node{
	int data;
	struct node *next;
};

void menu();
void push(struct node **, int);
void append(struct node **, int);
void print_list(struct node *);
void delete_node(struct node **, int);
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
			push(&head,dato);
			break;
		case 3: 
			print_list(head);
			break;
		case 4: 
			printf("\n\nIngrese un número entero a borrar\n");
			scanf("%d", &dato);
			delete_node(&head, dato);
			break;
		}
	}while(op!=5);
	return 0;
}

void menu(void){
	printf("\n1.- Agregar un nodo al final\n");
	printf("2.- Agregar un nodo al comienzo\n");
	printf("3.- Impresion de la lista\n");
	printf("4.- Borrar un valor de la lista\n");
	printf("5.- Salir\n");
}
	
void push(struct node ** head, int node_data){
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

void delete_node(struct node **head, int node_data){
	struct node *temp=NULL;
	temp=*head;
	if(head==NULL){
		printf("Lista vacia\n");
		exit(1);
	}else{
		struct node* prev=NULL;
		struct node* current=NULL;
		if(node_data==(*head)->data){
			temp=*head;
			*head=(*head)->next;
			free(temp);
		}else{
			prev=*head;
			current=(*head)->next;
			while(current!=NULL and current->data!=node_data){
				prev=current;
				current=current->next;
			}
			if(current!=NULL){
				temp=current;
				prev->next = current->next;
				free(temp);
			}
		}
	}
}
