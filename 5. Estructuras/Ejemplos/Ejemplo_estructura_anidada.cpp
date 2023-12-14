#include <iostream>
#include <string>
using namespace std;

struct fechaNacimiento
{
	int  dia;
	int  mes;
	int anyo;
};

struct datosPersona
{
	string nombre;
	char  inicial;
	struct fechaNacimiento diaDeNacimiento;
	float nota;
};

int main()
{
	datosPersona persona;
	
	persona.nombre = "Ignacio";
	persona.inicial = 'I';
	persona.diaDeNacimiento.mes = 8;
	persona.nota = 7.5;
	cout << "Nombre " << persona.nombre<<endl;
	cout << "Inicial " << persona.inicial<<endl;
	cout << "Dia de nacimiento " << persona.diaDeNacimiento.mes<<endl;
	cout << "La nota es " << persona.nota<<endl;
	
	return 0;
}
