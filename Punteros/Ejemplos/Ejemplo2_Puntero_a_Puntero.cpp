#include<iostream>
using namespace std;

int main(int argc, char *argv[]){
	int a=10, *puntero1, **puntero2; //Se utiliza ** para referir al puntero de puntero
	cout<<"Valor de A = "<<a<<endl;
	cout<<"Direccion de A = "<<&a<<endl;
	cout<<"\nASIGNACION DE A EN PUNTERO 1"<<endl;	
	puntero1=&a;

	cout<<"Valor de puntero 1 = "<<puntero1<<endl;
	cout<<"Direccion de puntero1 = "<<&puntero1<<endl;
	cout<<"Valor al que apunta puntero 1 = "<<*puntero1<<endl;

	cout<<"\nASIGNACION DE PUNTERO 1 EN PUNTERO 2"<<endl;
	puntero2=&puntero1;
	cout<<"Valor de puntero 2 = "<<puntero2<<endl;
	cout<<"Valor al que apunta puntero 2 = "<<*puntero2<<endl;
	cout<<"Valor al que apunta puntero 2 a puntero 1 = "<<**puntero2<<endl;
	return 0;
}
