#include <iostream>
using namespace std;

struct persona
{
	string nombre=" ";
	int cumple=0;
	char ciudad_nacimiento[10]={0};
};

int main(int argc, char *argv[]) { 
	struct persona p={"Sofi", 1008, "CBA"};
	cout<<"Datos: "<<p.nombre<<" "<<p.cumple<<" "<<p.ciudad_nacimiento<<endl;
	
	//Asignamos el puntero a p (p es una estructura)
	struct persona *ptr_p;
	ptr_p=&p;
	
	//Formas de obtener los datos a traves del puntero
	cout<<"Forma 1: "<<(*ptr_p).nombre<<" "<<(*ptr_p).cumple<<" "<<(*ptr_p).ciudad_nacimiento<<endl;
	cout<<"Forma 2: "<<ptr_p->nombre<<" "<<ptr_p->cumple<<" "<<ptr_p->ciudad_nacimiento<<endl;
	
	//Reasignamos valores con punteros.
	ptr_p->nombre="Sofia";
	ptr_p->cumple=25;
	ptr_p->ciudad_nacimiento[0]='C';
	ptr_p->ciudad_nacimiento[1]='A';
	ptr_p->ciudad_nacimiento[2]='B';
	ptr_p->ciudad_nacimiento[3]='A';
	
	cout<<"Datos actualizados: "<<ptr_p->nombre<<" "<<ptr_p->cumple<<" "<<ptr_p>ciudad_nacimiento<<endl;
	
	(*ptr_p).nombre="Sofia Beatriz";
	(*ptr_p).cumple=2510;
	
	cout<<"Datos actualizados: "<<(*ptr_p).nombre<<" "<<(*ptr_p).cumple<<" "<<(*ptr_p).ciudad_nacimiento<<endl;
	
}
