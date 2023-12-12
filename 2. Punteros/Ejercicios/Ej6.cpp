/* Desarrolle un programa que declare e inicialice un vector de 5 
valores (4.5,8,2.3,1.1,3). Luego, se pide que calcule y muestre 
la sumatoria y el promedio. Utilice punteros para realizar el 
ejercicio.
*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float vec []= {4.5,8,2.3,1.1,3};
    float *ptr_vec = vec;

    printf("\n VALORES \n");
    for (int i = 0; i < 5; i++)
    {
        printf("%0.2f\t",*(ptr_vec+i));
    }

    float suma = 0, prom = 0;
    float *ptr_suma = &suma, *ptr_prom = &prom;
    for (int i = 0; i < 5; i++)
    {
        *ptr_suma = *ptr_suma + ptr_vec[i];
    }
    *ptr_prom = *ptr_suma /(float)5;

    printf("\n RESULTADOS \n");
    printf("\nEl resultado de la suma es: %0.2f", *ptr_suma);
    printf("\nEl resultado del promedio es: %0.2f",*ptr_prom);
    return 0;
}
