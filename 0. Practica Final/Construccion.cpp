/*Implementa un programa que gestione los datos de un proyecto de construcción utilizando un TDA. 
El TDA debe almacenar información sobre las diferentes tareas del proyecto, incluyendo nombre 
de la tarea, duración estimada (entero) y estado de la tarea (pendiente/terminada/retrasada). 
Desarrolla las siguientes funciones para:

1. Agregar una nueva tarea al proyecto.
2. Mostrar la lista de tareas por consola y generar un archivo txt llamado "proyecto.txt".
3. Eliminar una tarea del proyecto.
4. Calcular el porcentaje de avance del proyecto.
5. Ordenar las tareas por duración estimada usando quicksort.
Crea un menú de opciones para que el usuario pueda realizar diferentes acciones.

USANDO COLAS*/

#include <iostream>
using namespace std;

struct proyecto
{
    char nombre[20];
    int tiempo;
    int estado;
    int tarea;
};

struct nodo
{
    struct proyecto p;
	struct nodo *link;
};

int menu();
void push(struct nodo **front, struct nodo **back, struct proyecto p);
void pop(struct nodo **front, struct nodo **back);
void mostrar(struct nodo *front);
void generarArchivo(struct nodo *front);
float porcentajeAvance(struct nodo *front);

int main(int argc, char const *argv[])
{
    struct nodo *front = NULL;
	struct nodo *back = NULL;
    struct proyecto p;
    int op = 0;
    FILE *fp=NULL;

    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            printf("\nIngrese el nombre del proyecto: ");
            scanf(" %s",&p.nombre);
            printf("\nIngrese el tiempo destinado al proyecto: ");
            scanf("%d",&p.tiempo);
            printf("\nIngrese el estado del proyecto del proyecto (1. Pendiente/ 2. Terminada/ 3. Retrasada): ");
            scanf("%d",&p.estado);
            switch (p.estado)
            {
            case 1:
                p.tarea = 1;
                break;
            case 2:
                p.tarea = 2;
                break;
            case 3:
                p.tarea = 3;
                break;
            }
            push(&front, &back, p);
            break;
        
        case 2:
            mostrar(front);
            generarArchivo(front);
            break;
        
        case 3:
            pop(&front, &back);
            break;
        
        case 4:
            printf("El porcentaje de avance del proyecto es: %.2f%%\n", porcentajeAvance(front));
            break;
        
        case 5:
            /* code */
            break;
        }
    } while (op<6);
    
    return 0;
}

int menu(){
	int op=0;
	do{
		printf("--------------------------------------------\n");
		printf("1.- Agregar una nueva tarea al proyecto.\n");
		printf("2.- Mostrar la lista de tareas por consola y generar un archivo txt llamado proyecto.txt.\n");
		printf("3.- Eliminar una tarea del proyecto.\n");
		printf("4.- Calcular el porcentaje de avance del proyecto.\n");
		printf("5.- Ordenar las tareas por duración estimada usando quicksort.\n");
		printf("6.- Salir\n");
		scanf("%d", &op);
		printf("--------------------------------------------\n");
	}while((op<1)||(op>6));
	return op;
}

void push(struct nodo **front, struct nodo **back, struct proyecto p){
	struct nodo *temp;
	temp=(struct nodo *)malloc(sizeof(struct nodo));
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

void mostrar(struct nodo *front){
	struct nodo *temp = NULL;
	temp=front;
	printf("Impresion de los proyectos\n");
	printf("Nombre.\tTiempo\tEstado\n");
	while(temp!=NULL){
		printf("%s\t%d\t%d\n", temp->p.nombre, temp->p.tiempo, temp->p.estado);		
		temp=temp->link;
	}
}

void generarArchivo(struct nodo *front) {
    FILE *fp = fopen("proyecto.txt", "w");
    if (fp != NULL) {
        fprintf(fp, "%-20s\t%-20s\t%-20s\n", "Nombre del proy.", "Tiempo", "Estado");
        struct nodo *temp = front;
        while (temp != NULL) {
            fprintf(fp, "%-20s\t%-20d\t%-20d\n", temp->p.nombre, temp->p.tiempo, temp->p.estado);
            temp = temp->link;
        }
        fclose(fp);
        printf("\nEl proyecto ha sido guardado en el archivo 'proyecto.txt'.\n");
    } else {
        printf("No se pudo abrir el archivo 'proyecto.txt' para escritura.\n");
    }
}

void pop(struct nodo **front, struct nodo **back){
	struct nodo *temp;
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

float porcentajeAvance(struct nodo *front) {
    struct nodo *temp = front;
    int tareasTotales = 0;
    int tareasTerminadas = 0;

    while (temp != NULL) {
        tareasTotales++;
        if (temp->p.tarea == 2) {  // Tarea terminada
            tareasTerminadas++;
        }
        temp = temp->link;
    }

    if (tareasTotales > 0) {
        return static_cast<float>(tareasTerminadas) / tareasTotales * 100;
    } else {
        return 0.0;  // Si no hay tareas, el avance es 0%
    }
}