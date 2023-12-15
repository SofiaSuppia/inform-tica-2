/*Crea un programa para gestionar un inventario de automóviles utilizando un TDA. El Pilas debe
contener información sobre cada automóvil, incluyendo modelo, stock (entero), 
y precio (decimal). Desarrollar las siguientes funciones para:

Agregar un nuevo modelo de automóvil al inventario.
Mostrar el inventario por consola y generar un archivo txt llamado "inventario.txt".
Eliminar un modelo de automóvil del inventario.
Calcular el valor total del inventario.
Ordenar de manera por stock de menor a mayor los modelos disponibles en el inventario 
usando quicksort*/

#include <iostream>
using namespace std;

struct vehiculo{
	char modelo[20];
	int stock;
	float precio;
};

struct nodo{
	struct vehiculo v;
	struct nodo *next;
};

int menu();
void push(struct nodo **sp, struct vehiculo v);
void pop(struct nodo **sp);
void mostrar(struct nodo **sp);
void generarArchivo(struct nodo **sp);
float calcularValorTotal(struct nodo **sp);

int main(int argc, char const *argv[])
{
    int op=0;
	struct nodo *stack_p =NULL;
	struct vehiculo v;
    FILE *fp=NULL;

    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            printf("Ingrese un vehiculo:\nmodelo: ");
			scanf("%s", &v.modelo);
			printf("Cantidad de stock: ");
			scanf("%d", &v.stock);
			printf("Precio: ");
			scanf("%f", &v.precio);
			push(&stack_p, v);
            break;
        
        case 2:
            mostrar(&stack_p);
            generarArchivo(&stack_p);
            break;
        
        case 3:
            pop(&stack_p);
            break;
        
        case 4:
            printf("El valor total del inventario es: %.2f\n", calcularValorTotal(&stack_p));
            break;
        
        case 5:
            /* cnodo */
            break;
        } 
    }while (op<6);
    
    return 0;
}

int menu(void){
	int op=0;
	do{
		printf("--------------------------------------------\n");
		printf("1.- Agregar un nuevo modelo de automóvil al inventario.\n");
		printf("2.- Mostrar el inventario por consola y generar un archivo txt llamado inventario.txt.\n");
		printf("3.- Eliminar un modelo de automóvil del inventario.\n");
		printf("4.- Calcular el valor total del inventario.\n");
		printf("5.- Ordenar de manera por stock de menor a mayor los modelos disponibles en el inventario usando quicksort*/\n");
		printf("6.- Salir\n");
		scanf("%d", &op);
		printf("--------------------------------------------\n");
	}while((op<1)||(op>6));
	return op;
}

void push(struct nodo **sp, struct vehiculo v){

	struct nodo *new_nodo = NULL;
	/* Creacion de memoria*/
	new_nodo = (struct nodo*)malloc(sizeof(struct nodo));
	/*Verificacion de memoria disponible*/
	if(new_nodo==NULL){
		printf("No hay memoria disponible");
		exit(0);
	}
	/*Carga util*/
	new_nodo->v=v;
	/*Asignamos el siguiente del nuevo nodo al stack pointer actual*/
	new_nodo->next=*(sp);
	/*Ahora el nuevo nodo es el stackptr*/
	*(sp)=new_nodo;	
}
	
bool isempty(struct nodo *sp){
	if(sp==NULL)
		return(true);
	else
		return(false);
}

void mostrar(struct nodo **sp){
	if(isempty(*sp)==false){
		printf("Impresion de la pila\n");
		printf("Modelo\tStock\tPrec.\n");
		/*Comenzamos a recorrer desde el stack pointer*/
		struct nodo *temp;
		temp=*(sp);
		while(temp!=NULL){
			printf("%s\t%d\t%.2f\n", temp->v.modelo, temp->v.stock, temp->v.precio);
			temp = temp->next;
			/*Recordar que el ultimo nodo de la stack, en siguiente apunta a NULL*/
		}
	}else{
		printf("Pila vacia\n");
	}
}

void generarArchivo(struct nodo **sp) {
    FILE *fp = fopen("inventario.txt", "w");
    if (fp != NULL) {
        fprintf(fp, "%-20s\t%-20s\t%-20s\n", "Modelo", "Stock", "Precio");
        struct nodo *temp = *sp;
        while (temp != NULL) {
            fprintf(fp, "%-20s\t%-20d\t%-20.2f\n", temp->v.modelo, temp->v.stock, temp->v.precio);
            temp = temp->next;
        }
        fclose(fp);
        printf("\nEl inventario ha sido guardado en el archivo 'inventario.txt'.\n");
    } else {
        printf("No se pudo abrir el archivo 'inventario.txt' para escritura.\n");
    }
}

void pop(struct nodo **sp){
	if(isempty(*sp)==false){
		struct nodo *temp=NULL;	
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

float calcularValorTotal(struct nodo **sp) {
    float valorTotal = 0.0;
    struct nodo *temp = *sp;
    while (temp != NULL) {
        valorTotal += temp->v.stock * temp->v.precio;
        temp = temp->next;
    }
    return valorTotal;
}
