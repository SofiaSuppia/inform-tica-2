/* 9.  Cree un programa que permita reservar memoria para arreglo de enteros 2x3. 
Luego cargar los valores de manera aleatoria. Realizar un menu de opciones que muestre la 
sumatoria, muestre todos los valores y al finalizar el programa libere la memoria. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    int nbytes=0, filas=0, columnas=0, sumatoria=0;
    int *valores=NULL; 
    char opcion=0; 
    printf("Ingrese el numero de filas: ");
    scanf("%d", &filas);
    printf("Ingrese el numero de columnas: ");
    scanf("%d", &columnas);
    nbytes=filas*columnas;
    valores = (int*) malloc(nbytes*sizeof(int));
    if (valores==NULL){
        printf("No hay memoria disponible");
        exit (1);
    }
    else{
    for (int i = 0; i < nbytes; i++)
    {
        *(valores+i)=rand() % 100+1;
    }
    do
    {
        printf("\nQue desea hacer?\na. Mostrar la sumatoria\nb. Mostrar valores\ns. Salir\n");
        scanf(" %c", &opcion);
        switch (opcion)
    {
    case 'a':
        sumatoria=0;
        for (int ii = 0; ii < nbytes; ii++)
        {
            sumatoria=sumatoria+*(valores+ii);
        }
        printf("%d", sumatoria);
        break;
    case 'b':
        for (int ii = 0; ii < nbytes; ii++)
        {
            printf("%d\t", *(valores+ii));
        }
        break;
    case 's':
        free(valores);
        break;
    default:
        break;}
    } while (opcion!='s'&&opcion!='S');
    }
    return 0;
}
