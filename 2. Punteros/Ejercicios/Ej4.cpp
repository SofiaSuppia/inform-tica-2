/*Escribir un programa que intercambie los valores enteros de a y b 
utilizando punteros*/

#include <iostream>
using namespace std; 

int main(int argc, char const *argv[])
{
    int a = 23, b = 20;
    int *ptr_a=&a, *ptr_b=&b;
    int *ptr_aux=0;

    printf("Valores originales\n");
	printf("a=%d\tb=%d\n", a,b);
	
	//intercambiamos utilizando un puntero auxiliar.
	ptr_aux=ptr_a;
	ptr_a=ptr_b;
	ptr_b=ptr_aux;
	
	printf("Valores intercambiados\n");
	printf("a=%d\tb=%d\n", *ptr_a, *ptr_b);;
    return 0;
}
