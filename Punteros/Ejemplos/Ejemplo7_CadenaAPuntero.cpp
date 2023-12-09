#include <iostream>
#include <string> //Se incluye la libreria
using namespace std; 

int main(int argc, char *argv[]) {
	string cadena=" ";
	cout<<"Ingrese una cadena: "<<endl;
	getline(cin,cadena,'\n');
	//Sin punteros
	cout<<"\nCADENA SIN PUNTEROS:\n\n";
	for(int i=0; i<(int)cadena.size();i++){ //size() devuelve el valor en bytes
		cout<<"cadena["<<i<<"]="<<cadena[i]<<endl;
	}
	//Con punteros
  	char *ptrCadena=&cadena[cadena.size()];
	cout<<"\nCADENA CON PUNTEROS:\n\n";
 	for(int i=0; i<(int)cadena.size();i++){
		ptrCadena[i]=cadena[i];	
		cout<<"ptrCadena["<<i<<"]="<<ptrCadena[i]<<endl;
	}	
	return 0;
}

