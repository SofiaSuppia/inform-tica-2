/* Cree un programa que permita reservar memoria para n caracteres (char). 
Luego cargar los n caracteres e imprimirlos por pantalla.

El usuario desea agregar mas caracteres, por lo que ingresa la n cantidad de 
caracteres a agregar. Luego cargar los n caracteres, imprimirlos y finalmente 
liberar la memoria.
*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    char *ptr;
    int cantm = 0, cant_plus = 0;

    printf("Ingrese la cantidad de memoria ha reservar: ");
    scanf("%d",&cantm);
    ptr = (char*)malloc(sizeof(char)*cantm);//reserva memoria

    printf("\nIngrese una cadena de caracteres: \n");
    for (int i = 0; i < cantm; i++) //carga los valores char al puntero
    {
        scanf(" %c",ptr+i);
    }
    
    printf("\n---------------------------------------------------------------");
    printf("\nLos caracteres ingresados en orden son: ");
    for (int i = 0; i < cantm; i++)
    {
        printf(" %c",*(ptr+i));
    }
    printf("\n---------------------------------------------------------------");

    printf("\nIngrese la cantidad de caracteres que va agregar: ");
    scanf("%d",&cant_plus);
    ptr = (char*)realloc(ptr,(cant_plus+cantm)*sizeof(char)); //agregamos mas reserva de memoria

    printf("\nIngrese los %d caracteres nuevo: ");
    for (int i = 0; i < cant_plus; i++)
    {
        scanf(" %c",ptr+cantm+i);
    }
    
    printf("\n---------------------------------------------------------------");
    printf("\nLos caracteres ingresados en orden son: ");
    for (int i = 0; i < (cant_plus+cantm); i++)
    {
        printf(" %c",*(ptr+i));
    }
    printf("\n---------------------------------------------------------------");

    free(ptr); //libera memoria 
    return 0;
}
