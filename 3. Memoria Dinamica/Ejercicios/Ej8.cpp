/*Crear un programa en la cual contenga un menu de opciones con distintas 
operaciones:
a. Reserva de memoria e introducción de datos enteros
b. Agregar reserva de memoria e introducción de nuevos datos enteros
c. Mostrar los datos en el orden y orden invertido al que fueron introducidos
*/
#include <iostream>
using namespace std;

int menu();
void reservarCargar(int *ptr, int cant);
void mostraOrden(int *ptr, int cant);
void cargarNuevo(int *ptr, int cant, int cant_plus);
void mostrarOrdenInverso(int *ptr, int cant);

int main(int argc, char const *argv[])
{
    int *ptr;
    int op = 0, cant = 0, cant_plus = 0;

    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            printf("Cuantos caracteres desea introducir: ");
            scanf("%d",&cant);

            ptr=(int*)malloc(cant*(sizeof(int)));
            if (ptr == NULL)
            {
                printf("\nNo se ha podido reservar la memoria solicitada\n");
            }else
            {
                printf("\nSe ha podido reservar %d espacio de memoria\n",cant*sizeof(int));
                //si cant*(sizeof(int)) recordar que 1 int - ocupa 4 bytes
            }       
            reservarCargar(ptr,cant);
            mostraOrden(ptr,cant);
            break;
        
        case 2:
            //Redimencionamiento de la memoria dinámica
            printf("\n\nIngrese la cantidad de caracteres que va agregar: ");
            scanf("%d",&cant_plus);
            ptr = (int*)realloc(ptr,(cant_plus+cant)*sizeof(int)); //agregamos mas reserva de memoria

            if (ptr == NULL)
            {
                printf("\nNo se ha podido reservar la memoria solicitada\n");
            }else
            {
                printf("\nSe ha podido reservar %d espacio de memoria\n",(cant_plus+cant)*sizeof(char));
            }
            cargarNuevo(ptr,cant,cant_plus);
            break;
        
        case 3:
            mostraOrden(ptr,(cant_plus+cant));
            mostrarOrdenInverso(ptr,(cant_plus+cant));
            break;
        }
    } while (op!=0);
    free(ptr);
    return 0;
}

int menu(){
    int op = 0;
    printf("\n---------------------------------------------------------------");
    printf("\n Menu de Opciones\n");
    printf("1. Reserva de memoria e introduccion de datos enteros\n");
    printf("2. Agregar reserva de memoria e introduccion de nuevos datos enteros\n");
    printf("3. Mostrar los datos en el orden y orden invertido al que fueron introducidos\n");
    printf("\nSeleccione la opcion que desea: ");
    scanf("%d",&op);
    return op;
}

void reservarCargar(int *ptr, int cant){
    printf("\nIngrese una cadena de caracteres: \n");
    for (int i = 0; i < cant; i++) //carga los valores int al puntero
    {
        scanf("%d",ptr+i);
    }
}

void mostraOrden(int *ptr, int cant){
    printf("\n---------------------------------------------------------------");
    printf("\nLos caracteres ingresados en orden son: ");
    for (int i = 0; i < cant; i++)
    {
        printf("%d",*(ptr+i));
    }
    printf("\n---------------------------------------------------------------");
}

void cargarNuevo(int *ptr, int cant, int cant_plus){
    printf("\nIngrese los %d caracteres nuevos: ",cant_plus);
    for (int i = 0; i < cant_plus; i++)
    {
        scanf("%d",ptr+cant+i);
    }
}

void mostrarOrdenInverso(int *ptr, int cant){
    printf("\n---------------------------------------------------------------");
    printf("\nLos caracteres ingresados en orden inverso son: ");
    for (int i = cant-1; i >= 0; i--)
    {
        printf("%d",*(ptr+i));
    }
    printf("\n---------------------------------------------------------------");
}