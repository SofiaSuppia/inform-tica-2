#include <iostream>
#include <string>
#define tamano 10
using namespace std;

/*1. Crear un programa que pida los siguientes datos de una canción: Artista, Titulo, Duración (en segundos),Tamaño del archivo (en KB). Crear una 
estructura que almacene datos de la canción y luego los muestre por pantalla.*/

struct cancion
{
	string artista;
	string titulo;
	int duracion;
	int tamanio;
};


int main(int argc, char *argv[]) {
	
	struct cancion can;
	cout<<"Ingrese los siguientes datos de la cancion: "<<endl;
	cout<<"Artista: ";
	//getline (cin, nombre de la variable string, caracter delimitador); 
	getline(cin,can.artista,'\n'); //Ingresa los nombres hasta que presione enter (\n). 
	cout<<"Titulo: ";
	getline(cin,can.titulo,'\n');
	cout<<"Duracion: ";
	cin>>can.duracion;
	cout<<"Tamaño: ";
	cin>>can.tamanio;
	
	cout<<"\nDatos de la canción: "<<endl;
	cout<<"Artista: "<<can.artista<<endl;
	cout<<"Titulo: "<<can.titulo<<endl;
	cout<<"Duracion: "<<can.duracion<<endl;
	cout<<"Tamaño: "<<can.tamanio<<endl;
	
	return 0;
}
