#include <iostream>
using namespace std; 
int main(int argc, char *argv[]){
	int cuenta=125, *p=0, x=0;
	cout<<"______________________Valores Iniciales______________________"<<endl;
	cout<<"Cuenta: "<<cuenta<<endl;
	cout<<"Direccion de memoria de Cuenta: "<<&cuenta<<endl;
	cout<<"El valor de p: "<<p<<endl;
	cout<<"El valor de x: "<<x<<endl;
	cout<<"\n____________________Asignacion al Puntero____________________"<<endl;
	p=&cuenta; //se asigna la direccion de la variable (cuenta) al puntero (p)
	cout<<"El valor de p: "<<p<<endl;
	cout<<"\n_________________Asignacion a la Variable x__________________"<<endl;
	x=*p;
	cout<<"El valor al que apunta el puntero p: "<<*p<<endl;
	cout<<"El valor de x: "<<x<<endl;
	return 0; 
} 




