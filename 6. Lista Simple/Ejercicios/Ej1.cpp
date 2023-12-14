/*Crear un programa en la cual se solicite al usuario el ingreso de 5 
valores numericos y luego muestre la lista. */

#include <iostream>
using namespace std;

struct node{
	int data;
	struct node *next;    //DECLARACION DE UN PUNTERO LLAMADO next , A una estructura del mismo tipo.., TIPO NODO  
};

int main(int argc, char *argv[]) {
	
	/*puntero al comienzo de la lista*/
	struct node* head=NULL;          //PRIMERO CREAMOS UN PUNTERO head QUE APUNTARA al comienzo de la lista (PRIMER NODO),PERO POR AHORA ESTA A NULL
	struct node* temp= NULL;			//tenemos que tener punteros auxiliares que nos ayudaran en el trabajo 
	struct node *new_node=NULL;          //puntero a un nuevo nodo que creamos 
	
	/*Asignacion del dato al nuevo nodo */ //RECORDAMOS QUE CADA <ACCION> EN UNA LISTA, SE HACE MEDIANTE SU "data"
	int dato=0, i=0;
	do{
		printf("Ingrese un dato\n");		
		scanf("%d", &dato);                //INGRESAMOS EL dato que SERA EL DATA DEL NUEVO NODO 
		
		new_node = (struct node*)malloc(sizeof(struct node));   //linea 26 y 27 , se lleva a cabo para la creacion de un nuevo nodo
		new_node = (struct node *) new_node;					//CADA VEZ QUE EL DO-WHILE SE REPITA SE CREARA UN NUEVO new_node..
		
		//PROTOCOLO DE ASIGNACION DE MEMORIA 
		if(new_node==NULL){
			printf("No hay memoria disponible");
			exit(1);     //HACE QUE EL PROGRAMA FINALICE AUTOMATICAMENTE 
		}
		
		//SINO ,SIGUE EN LA LINEA 36 .. 
		new_node->data=dato; //ACCEDEMOS MEIDANTE EL PUNTERO new_node A SU data ,QUE SERA IGUAL AL dato QUE SE INGRESO
		new_node->next=NULL;/*como va al final de la lista este nodo apunta a NULL*/
		
		/*Si la lista esta vacia, el nodo ingresado es el primero de la lista*/
		if(head==NULL){
			head=new_node;
		}
		else{/*Buscamos cual es el ultimo NODO*/
			temp=head;   //QUE EL AUXILIAR APUNTE AL MISMO NODO QUE HEAD(OSEA NODO 1)
			while(temp->next!=NULL){  //MIENTRAS QUE EL PUNTERO DE TEMP ES DISTINTO DE NULL,ENTOCES HAY OTRO NODO SIGUIENTE//DEBO DARME CUENTA QUE VOY MOVIENDOME EN LA LISTA CON LA AYUDA DE TEMP ..
				temp=temp->next;		//ENTONCES TEMP SERA IGUAL AHORA AL AL PUNTERO DEL SIGUIENTE NODO..(ENTOCES TEMP SE ASIENTA EN EL NODO 2) ,Y SEGUIRA ESTOSPASOS SUCESIVAMENTE HASTA QUE SE ROMPA EL WHILE ..
			}/*Hacemos que el que era ultimo apunte al nuevo nodo*/
			temp->next=new_node;   //CUANDO SE ROMPA EL WHILE (TEMP ESTARA ASENTADO EN EL ULTIMO NODO),ENTONCES EL PUNTERO DE ESE ULTIMO NODO APUNTARA A new_node(un nodo nuevo que agrego) 
		}
		i++; //CONTADOR PARA IR TENIENDO EN CUENTA CUANTOS "valores numericos" voy agregando..(limite de 5 ) 
	}while(i!=5);
	
	//---------------------------------
	
	//en caso de el usuario no haya puesto nada o lo que haya querido poner no sea valido ,no hay nada que imprimir ..,solo lista vacia .. 
	if(head==NULL){   //SI NO HAY NADA , EL head APUNTA A NULL..
		printf("Lista vacia\n");
		exit(1);
	}
	//SINO, IMPRIMIMOS TODA LA LISTA..
	else{
		node*temp=head;        //TEMP SERA IGUAL A head, YY RECORDARR EL TEMP LO USAMOS PARA MOVERNOS EN LA LISTA ..
		printf("Lista\n");
		while(temp!=NULL){     
			printf("%d\n", temp->data);     //IMPRIMIMOS EL DATA DE CADA NODO EN EL QUE NOS VAMOS ASENTANDO..
			temp=temp->next;       //LUEGO TEMP SERA IGUAL AL PUNTERO QUE TIENE DENTRO.. y SI ESE PUNTERO ES DISTINTO DE NULL ,SEGUIRA SUCESIVAMENTE DENTRO DEL WHILE ... 
		}
		
	}
	return 0;
}
