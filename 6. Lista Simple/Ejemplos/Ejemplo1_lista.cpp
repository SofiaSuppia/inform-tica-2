//EJEMPLO DE LISTA SIMPLEMENTE ENLAZADA ..

#include <iostream>
using namespace std;

//CREAMOS LA ESTRUCTURA
struct node{
	int data;
	struct node *next;
};

int main(int argc, char *argv[]) {
	
	//CREAMOS LOS PUNTEROS 
	struct node* head=NULL;
	struct node* temp= NULL;
	struct node *new_node=NULL;

	int dato=0;
	printf("Ingrese numeros [fin=0]\n");
	
	//CREAMOS UN BUCLE 
	do{
		scanf("%d", &dato);
		if(dato!=0){
			new_node = (struct node*)malloc(sizeof(struct node)); 
			
			if(new_node==NULL){
				printf("No hay memoria disponible");
				exit(1);
			}
			//SI NO SUCEDIO LO DEL IF ,SIGUE EL CODIGO .. 
			new_node->data=dato;
			new_node->next=NULL;
			//----------AQUI YA CREE EL PRIMER NODO..------(LINEA 33 Y 34)
			if(head==NULL){
				head=new_node;
			}
			else{ //SI EL NODO QUE CREO, NO ES EL PRIMERO ..
				temp=head;
				while(temp->next!=NULL){  //NECESITO MOVERME EN LA LISTA HASTA ENCONTRAR EL ULTIMO NODO..
					temp=temp->next;  
				}
				//CUANDO YA LO ENCONTRE.. (EL NEXT DEL ULTIMO  APUNTARA  AL NUEVO ,EL QUE AGREGO.. )
				temp->next=new_node;
			}
		}
	}while(dato!=0);
	//--------------------------HASTA AQUI HEMOS CODEADO PARA CREAR LA CANTIDAD DE NODOS QUE SE QUISIERA..-----------------
	
	
	//mostrar un nodo
	temp=head;
	if(head==NULL){
		printf("Lista vacia\n");
		exit(1);
	}else{
		node*temp=head;
		printf("Lista completa\n");
		while(temp!=NULL){
			printf("%d\t", temp->data);
			temp=temp->next;
		}
		
	}
	
	//borrar un nodo
	temp=head;   //CREAMOS UN AUXILIAR PARA NO PERDER EL HEAD,DE MODO QUE USAREMOS ESTE AUXILIAR Y NO EL HEAD ..
	if(head==NULL){
		printf("Lista vacia\n");
		exit(1);
	}
	else{
		struct node* prev=NULL;      //CREAMOS DOS PUNTEROS AUXILIARES MAS ..
		struct node* current=NULL;
		printf("\nIngrese el dato a borrar\n");   //INGRESAMOS DATO A BORRAR..(ELEMENTO QUE QUIERO BORRAR DE LA LISTA..)
		scanf("%d",&dato);
		if(dato==head->data){   //SI EL DATO ES IGUAL QUE EL QUE EL PRIMER DATO .. (OSEA QUE EL PRIMER ELEMENTO ES EL QUE QUIERO BORRAR..)
			temp=head;				
			head=head->next;	//CAMBIAMOS DE POSICION EL HEAD..
			free(temp);			//LIBERAMOS A TEMP (O SEA BORRAMOS EL NODO ..)
		}
		else{
			prev=head;			//USAMOS LOS AUXILIARES PARA MOVERNOS EN LA LISTA..
			current=head->next;		
			//ENTRAMOS A UN BUCLE PARA VER CUANDO ENCONTREMOS EL NODO CORRECTO(SERA CUANDO LA CONDICION SE ROMPA).. 
			while(current!=NULL and current->data!=dato){  //DE LO CONTRARIO ,SEGUIREMOS MOVIENDONOS EN LA LISTA ..
				prev=current;
				current=current->next;
			}
			//DADO QUE LA CONDICION SE ROMPIO ,SIGNIFICA QUE ENCONTRAMOS EL NODO(ELEMENTO QUE QUIERO BORRAR..)
			if(current!=NULL){		//PROCEDEMOS A BORRAR.. 
				temp=current;
				prev->next = current->next;  //EN CASO DE QUE HAYA UN NODO DESPUES DEL CURRENT ENCONTRADO EL NEXT DE PREV APUNTARA A ÉL,SINO A NULL..
				free(temp);                  //Y LIBERAMOS TEMP ()BORRAMOS EL NODO QUE ENCONTRAMOS ..
			}
		}
	}
	//NOTA:HACE FALTA EL USAR EL PREV  PORQUE SINO CORTAREMOS LA ORGANIZACION DE LOS "ENLACES ".. 
	
	
	
	
	//mostrar un nodo
	temp=head;
	if(head==NULL){
		printf("Lista vacia\n");
		exit(1);
	}else{
		node*temp=head;
		printf("Lista completa\n");
		while(temp!=NULL){
			printf("%d\t", temp->data);
			temp=temp->next;
		}
		
	}
	
	return 0;
}

