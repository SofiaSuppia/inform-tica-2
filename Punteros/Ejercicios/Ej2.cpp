/*Cargar las 3 notas de un alumno como valores enteros. Luego mostrar el promedio teniendo 
en cuenta si tiene parte decimal.*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int nota1=0, nota2=0,nota3=0;
    float prom=0;
    printf("Ingrese las tres notas de cada alumno (solo numeros enteros): \n");
    scanf("%d %d %d",&nota1,&nota2,&nota3);
    prom = (float) (nota1+nota2+nota3)/3;
    printf("\nEl promedio de las tres notas es: %0.2f",prom);
    return 0;
}
