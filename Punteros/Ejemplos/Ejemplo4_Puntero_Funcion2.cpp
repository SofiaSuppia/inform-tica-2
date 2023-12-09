#include<iostream>
using namespace std;

int calcularSumaValor (int, int); //suma 2 valores
int calcularSumaPuntero(int *,int,int); // suma 3 valores

int main(int argc, char *argv[]) {
    int *puntero=0, a=5, b=10, resultado=0;
	resultado=calcularSumaValor(a,b);
    cout<<"CUENTAS:\n\n"<<a<<"+"<<b<<"="<<resultado<<"\n\n";
    puntero=&resultado;
    cout<<*puntero<<"+"<<a<<"+"<<b<<"="<<calcularSumaPuntero(puntero, a, b)<<endl;
	return 0;
}

int calcularSumaValor (int a, int b)
{ return a+b;
}
int calcularSumaPuntero(int *puntero, int a,int b) 
{ return (*puntero)+a+b;
}
/*Pero si lo que necesito es solo pasar un parámetro con puntero y 
no modificarlo.  Utilizo return*/
