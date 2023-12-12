/*Cree un programa que permita reservar memoria para n caracteres (char). 
Luego cargar los n caracteres, imprimirlos y liberar la memoria.
*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    char *ptr;
    int cant_men=0;

    printf("Ingrese la cantidad de memoria ha reservar: \n");
    scanf("%d",&cant_men);
    ptr = (char*)malloc(sizeof(char)*cant_men); //reserva memoria
    //La funcion sizeof, devuelve el tamaño en bytes que ocupa una variable o algun tipo de dato.
	// 1 char - ocupa 1 byte

    printf("\nIngrese una cadena de caracteres: ");
    for (int i = 0; i < cant_men; i++) //carga los valores char al puntero
    {
        scanf(" %c",ptr+i);
    }
    
    printf("\nLa cadena de caracteres es: ");
    for (int i = 0; i < cant_men; i++) //muestra los valores char ingresados a traves del puntero
    {
        printf(" %c",*(ptr+i));
    }
    free(ptr); //libera memoria  
    return 0;
}
