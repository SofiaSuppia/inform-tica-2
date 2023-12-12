/* Cree un programa que permita reservar memoria para n valores enteros. 
Luego cargar los n valores, imprimirlos y liberar la memoria.
*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int *ptr = 0;
    int cant_men = 0;

    printf("Ingrese la cantidad de memoria ha reservar:\n");
    scanf("%d",&cant_men);
    ptr = (int*)malloc(sizeof(int)*cant_men);

    printf("\nIngrese los valores: \n");
    for (int i = 0; i < cant_men; i++)
    {
        scanf("%d",ptr+i);
    }
    
    printf("\nValores:\n");
    for (int i = 0; i < cant_men; i++)
    {
        printf("%d\n",*(ptr+i));
    }
    free(ptr);
    return 0;
}
