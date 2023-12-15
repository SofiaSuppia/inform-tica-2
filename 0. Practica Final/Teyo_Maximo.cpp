#include <iostream>
using namespace std;
//TEMA A
struct producto{
	int codigo;
	char descripcion[20];
	int precio_lista;
	int precio_publico;
	int stock;
	int vendido;
	struct producto *p_next;
};

void cargar_producto(struct producto **head,int contador);
void registrar_venta(struct producto *head);
void mostrar(struct producto *head);
void grabar_archivo(struct producto *head,FILE *fp);

int main(int argc, char *argv[]) {
	
	struct producto *head=NULL;
	char opcion=' ',eleccion=' ';
	int contador=0;
	FILE *fp=NULL;
	
	do{
		printf("\n----MENU----\n");
		printf("a- Cargar un producto\n");
		printf("b- Registrar una venta\n");
		printf("c- Mostrar listado de ventas\n");
		printf("d- Grabar archivo\n");
		printf("Opcion: ");
		scanf(" %c",&opcion);
		
		switch(opcion){
		case 'a':
		case 'A':
			contador++;
			cargar_producto(&head,contador);
			break;
		case 'b':
		case 'B':
			registrar_venta(head);
			break;
		case 'c':
		case 'C':
			mostrar(head);
			break;
		case 'd':
		case 'D':
			grabar_archivo(head,fp);
			break;
			
		}
		
		printf("\n¿Desea seguir? s/n  ");
		scanf(" %c",&eleccion);
	} while(eleccion=='s' || eleccion=='S');
	
	
	return 0;
}

void cargar_producto(struct producto **head,int contador){
	
	struct producto *new_node=NULL;
	struct producto *temp=NULL;
	
	new_node=(struct producto *) malloc(sizeof(struct producto));
	
	if(new_node==NULL){
		printf("\nNo hay memoria suficiente");
		exit(1);
	}
	
	new_node->codigo=contador;
	printf("\nIngrese descripcion del producto: ");
	scanf("%s",&new_node->descripcion);
	printf("\nIngrese precio de lista: ");
	scanf("%d",&new_node->precio_lista);
	new_node->precio_publico=new_node->precio_lista+new_node->precio_lista*0.4;
	printf("\nIngrese stock del producto: ");
	scanf("%d",&new_node->stock);
	new_node->vendido=0;
	new_node->p_next=NULL;
	
	if(*head==NULL){
		*head=new_node;
	}
	else{
		temp=*head;
		while(temp->p_next!=NULL){
			temp=temp->p_next;
		}
		temp->p_next=new_node;
	}
	
}
	
void registrar_venta(struct producto *head){
	
	struct producto *temp=NULL;
	int codigo=0,cant=0;
	
	temp=head;
	printf("\nIngrese el codigo del producto: ");
	scanf("%d",&codigo);
	printf("\nIngrese cantidad vendido: ");
	scanf("%d",&cant);
	
	while(temp!=NULL){
		if(temp->codigo==codigo){
			if(temp->stock>=cant){
				temp->stock=temp->stock-cant;
				temp->vendido=temp->vendido+cant;
			}
			else{
				printf("\nNo hay stock disponible");
			}
		}
		temp=temp->p_next;
	}
}
	
void mostrar(struct producto *head){
	
	struct producto *temp=NULL;
	int tot_ventas=0,recaudacion_tot=0,recaudacion_lista=0,ganancias=0;
	
	temp=head;
	printf("\n---LISTADO DE VENTAS---\n");
	while(temp!=NULL){
		printf("CODIGO: %d\tDESCRIPCION: %s\tPRECIO LISTA: $%d\tPRECIO AL PUBLICO: $%d\tSTOCK: %d\tVENDIDO: %d\n",temp->codigo,temp->descripcion,temp->precio_lista,temp->precio_publico,temp->stock,temp->vendido);
		tot_ventas=tot_ventas+temp->vendido;
		recaudacion_tot=recaudacion_tot+temp->vendido*temp->precio_publico;
		recaudacion_lista=recaudacion_lista+temp->vendido*temp->precio_lista;
		temp=temp->p_next;
	}
	
	printf("\n\nTotal de ventas: %d",tot_ventas);
	printf("\nRecaudacion total: $%d",recaudacion_tot);
	ganancias=recaudacion_tot-recaudacion_lista;
	printf("\nGanancias: $%d",ganancias);
}
	
void grabar_archivo(struct producto *head,FILE *fp){
	
	struct producto *temp=NULL;
	
	temp=head;
	fp=fopen("pedido.txt","w");
	if(fp==NULL){
		printf("\nNo se puede abrir el archivo");
		exit(2);
	}
	while(temp!=NULL){
		if(temp->stock==0){
			fprintf(fp,"CODIGO: %d\tDESCRIPCION: %s\tPRECIO LISTA: $%d\tPRECIO AL PUBLICO: $%d\tSTOCK: %d\tVENDIDO: %d\n",temp->codigo,temp->descripcion,temp->precio_lista,temp->precio_publico,temp->stock,temp->vendido);
		}
		temp=temp->p_next;
	}
	fclose(fp);
	
	temp=head;
	fp=fopen("pedido.txt","r");
	if(fp==NULL){
		printf("\nNo se puede abrir el archivo");
		exit(2);
	}
	while(temp!=NULL){
		if(temp->stock==0){
		fscanf(fp,"CODIGO: %d\tDESCRIPCION: %s\tPRECIO LISTA: $%d\tPRECIO AL PUBLICO: $%d\tSTOCK: %d\tVENDIDO: %d\n",&temp->codigo,&temp->descripcion,&temp->precio_lista,&temp->precio_publico,&temp->stock,&temp->vendido);
		printf("CODIGO: %d\tDESCRIPCION: %s\tPRECIO LISTA: $%d\tPRECIO AL PUBLICO: $%d\tSTOCK: %d\tVENDIDO: %d\n",temp->codigo,temp->descripcion,temp->precio_lista,temp->precio_publico,temp->stock,temp->vendido);
		}
		temp=temp->p_next;
	}
	fclose(fp);
	
}
