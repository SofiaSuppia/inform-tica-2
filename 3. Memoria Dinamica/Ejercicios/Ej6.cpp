/*Crear un programa que pregunte al usuario cuantos caracteres desea introducir, 
reserve espacio para dicho numero de caracteres, le permita al usuario 
introducirlos desde teclado. Por ultimo se los muestre todos seguidos y en el 
orden inverso al que fueron introducidos. 
Crear funciones para cargar, mostrar en orden y mostrar en orden inverso. 
Utilizar funciones.*/

#include <iostream>
using namespace std;

void cargar(char *ptr, int cant);
void mostrarOrden(char *ptr, int cant);
void mostrarOrdenInverso(char *ptr, int cant);

int main(int argc, char const *argv[])
{
    char *ptr;
    int cant = 0;

    printf("Ingrese la cantidad de memoria ha reservar: ");
    scanf("%d",&cant);
    ptr = (char*)malloc(sizeof(char)*cant);//reserva memoria

    if (ptr == NULL)
    {
        printf("\nNo se ha podido reservar la memoria solicitada\n");
    }else
    {
        printf("\nSe ha podido reservar la memoria solicitada\n");
    }
    cargar(ptr,cant);
    mostrarOrden(ptr,cant);
    mostrarOrdenInverso(ptr,cant);

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

void mostrarOrdenInverso(char *ptr, int cant){
    printf("\n---------------------------------------------------------------");
    printf("\nLos caracteres ingresados en orden inverso son: ");
    for (int i = cant-1; i >= 0; i--)
    {
        printf(" %c",*(ptr+i));
    }
    printf("\n---------------------------------------------------------------");
}

