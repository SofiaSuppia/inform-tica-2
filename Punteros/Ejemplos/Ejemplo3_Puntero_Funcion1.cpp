#include <iostream>
using namespace std;

int calcularCuboValor (int b); //paso por valor
void calcularCuboPuntero(int *ptr); //paso por referencia
/*Cuando paso por parámetros un puntero, el paso es por referencia, es decir 
que indico la ubicación. Por eso no necesito tener un RETURN*/

int main(int argc, char *argv[]) {
   int a=5;
   cout<<"FUNCION POR VALOR\na="<<a<<endl;
   cout<<"Cubo de a="<<calcularCuboValor(a)<<endl;
   a=3;
   cout<<"\nFUNCION POR REFERENCIA (puntero)\na="<<a<<endl;
   calcularCuboPuntero(&a);
   cout<<"Cubo de a= "<<a<<endl;
   return 0;
}
//funciones
int calcularCuboValor (int b)
{return b*b*b;
}
void calcularCuboPuntero(int* ptr)
{*ptr=(*ptr) * (*ptr) * (*ptr);
}


