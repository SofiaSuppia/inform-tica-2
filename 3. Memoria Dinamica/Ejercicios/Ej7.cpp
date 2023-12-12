/*Crear un programa que pregunte al usuario cuantos caracteres desea introducir, 
reserve espacio para dicho numero de caracteres, le permita al usuario 
introducirlos desde teclado y luego mostrar por pantalla los valores. Luego, el 
programa pregunta cuantos caracteres desea agregar a la lista de elementos ya 
introducida, agrega espacio de memoria y solicita el ingreso de los nuevos 
valores. Por ultimo, mostrar la lista resultante. Utilizar funciones.*/

#include <iostream>
using namespace std;

void cargar(char *ptr, int cant);
void mostrarOrden(char *ptr, int cant);
void cargarNuevo(char *ptr, int cant, int cant_plus);

int main(int argc, char const *argv[])
{
    char *ptr;
	int cant=0,cant_plus=0;	

    printf("Ingrese la cantidad de memoria ha reservar: ");
    scanf("%d",&cant);
    ptr = (char*)malloc(sizeof(char)*cant);//reserva memoria

    if (ptr == NULL)
    {
        printf("\nNo se ha podido reservar la memoria solicitada\n");
    }else
    {
        printf("\nSe ha podido reservar %d espacio de memoria\n",cant*sizeof(char));
    }

    cargar(ptr,cant);
    mostrarOrden(ptr,cant);

    //Redimencionamiento de la memoria dinámica
    printf("\n\nIngrese la cantidad de caracteres que va agregar: ");
    scanf("%d",&cant_plus);
    ptr = (char*)realloc(ptr,(cant_plus+cant)*sizeof(char)); //agregamos mas reserva de memoria

    if (ptr == NULL)
    {
        printf("\nNo se ha podido reservar la memoria solicitada\n");
    }else
    {
        printf("\nSe ha podido reservar %d espacio de memoria\n",(cant_plus+cant)*sizeof(char));
    }

    cargarNuevo(ptr,cant,cant_plus);
    mostrarOrden(ptr, (cant+cant_plus));

    free(ptr);
    return 0;
}

void cargar(char *ptr, int cant){
    printf("\nIngrese una cadena de caracteres: \n");
    for (int i = 0; i < cant; i++) //carga los valores char al puntero
    {
        scanf(" %c",ptr+i);
    }
}

void mostrarOrden(char *ptr, int cant){
    printf("\n---------------------------------------------------------------");
    printf("\nLos caracteres ingresados en orden son: ");
    for (int i = 0; i < cant; i++)
    {
        printf(" %c",*(ptr+i));
    }
    printf("\n---------------------------------------------------------------");
}

void cargarNuevo(char *ptr, int cant, int cant_plus){
    printf("\nIngrese los %d caracteres nuevos: ",cant_plus);
    for (int i = 0; i < cant_plus; i++)
    {
        scanf(" %c",ptr+cant+i);
    }
}
