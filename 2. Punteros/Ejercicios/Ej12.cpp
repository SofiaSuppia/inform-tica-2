/* Desarrolle un programa que declare e inicialice un vector de 5 valores aleatorios. 
Luego, crear 3 funciones que permita hallar el valor maximo, minimo y el sumatoria de 
ellos. Finalmente mostrar los resultados. 
Utilice punteros para realizar el ejercicio.*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void buscarMinimo (int *, int *);
void buscarMaximo (int *, int *);
void calcularSumatoria(int *, int *);

int main(int argc, char const *argv[])
{
    int vec[5] = {0};
    int *ptr_vec = vec;

    srand(time(NULL));
    printf("Los valores son: \n");
    for (int i = 0; i < 5; i++)
    {
        *(ptr_vec + i)=rand()%50+1;
        printf("%d \t",*(ptr_vec + i));
    }
    int max =0, min = 0, sum = 0;
    int *ptr_max = &max,*ptr_min = &min,*ptr_sum = &sum;

    buscarMaximo(ptr_vec,ptr_max);
    buscarMinimo(ptr_vec,ptr_min);
    calcularSumatoria(ptr_vec,ptr_sum);

    printf("\n\nRESULTADOS:\n");
	printf("Maximo: %d\n", *ptr_max);
	printf("Minimo: %d\n", *ptr_min);
	printf("Sumatoria: %d\n", *ptr_sum);
    return 0;
}

void buscarMinimo (int *ptr_vec, int *ptr_min){
    for (int i = 0; i < 5; i++)
    {
        if (i == 0)
        {
            *ptr_min = *ptr_vec;
        }else
        {
            if (*ptr_vec < *ptr_min)
            {
                *ptr_min = *ptr_vec;
            }
        }
        ptr_vec++;
    }
}

void buscarMaximo (int *ptr_vec, int *ptr_max){
    for (int i = 0; i < 5; i++)
    {
        if (i == 0)
        {
            *ptr_max = *ptr_vec;
        }else
        {
            if (*ptr_vec > *ptr_max)
            {
                *ptr_max = *ptr_vec;
            }
        }
        ptr_vec++;
    }
}

void calcularSumatoria(int *ptr_vec, int *ptr_sum){
    for (int i = 0; i < 5; i++)
    {
        *ptr_sum += *ptr_vec;
        ptr_vec++;
    }               
}