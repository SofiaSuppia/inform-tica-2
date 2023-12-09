#include <iostream>
#include <math.h>//Inclusión de la libreria de matematicas
using namespace std;

int main(int argc, char *argv[]) {
	float numero=0, resultado=0, anguloRadianes=0, anguloGrado=0, enRadianes=0;
	float seno1=0, seno2=0, coseno1=0, coseno2=0, tangente1=0, tangente2=0;
	//FUNCIONES MATEMATICAS
	cout<<"REDONDEOS."<<endl; 	
	cout<<"Ingrese un numero:"<<endl;
	cin>>numero;

	//Redondeo para arriba.
	resultado=ceil(numero);
	cout<<"Redondeo para arriba de "<<numero<<" es "<<resultado<<". Calculado con la funcion ceil."<<endl;	
	cout<<"________________________________________________________________ \n"<<endl;
	
	//Redondeo para abajo.
	resultado=floor(numero);
	cout<<"Redondeo para abajo de "<<numero<<" es "<<resultado<<". Calculado con la funcion floor."<<endl;
	cout<<"________________________________________________________________ \n"<<endl;
	
	cout<<"CALCULO DE RAICES Y POTENCIAS."<<endl;
	cout<<"Ingrese un numero:"<<endl;
	cin>>numero;
	
	// Calculo la raiz cuadrada del numero ingresado. Uso de la funcion sqrt
	resultado = sqrt (numero);
	cout<<"La raiz cuadradada de "<<numero<<" es "<<resultado<<". Calculado con la funcion sqrt."<<endl;
	cout<<"________________________________________________________________ \n"<<endl;
		
	/* Calculo de la raiz cuadrada del numero ingresado. Uso de la funcion pow (numero, potencia)
	Teniendo en cuenta que la raiz cuadrada es lo mismo que calcular la potencia de 1/2.*/
	resultado = pow (numero, 0.5); //El primer valor corresponde a la base y el segundo al exponente.
	cout<<"La raiz cuadradada de "<<numero<<" es "<<resultado<<". Calculado con la funcion pow."<<endl;
	cout<<"________________________________________________________________ \n"<<endl;
	
	/* Calculo de la raiz cubica del numero ingresado. Uso de la funcion cbrt*/
	resultado = cbrt (numero);
	cout<<"La raiz cubica de "<<numero<<" es "<<resultado<<". Calculado con la funcion cbrt."<<endl;	
	cout<<"________________________________________________________________\n"<<endl;
	
	/* Calculo de la raiz cubica del numero ingresado. Uso de la funcion pow (numero, potencia)
	Teniendo en cuenta que la raiz cubica es lo mismo que calcular la potencia de 1/3.
	En este caso como es un numero periodico se recomienda poner muchos valores para que se acerque al resultado.*/
	resultado = pow (numero, 0.333333333); //El primer valor corresponde a la base y el segundo al exponente.
	cout<<"La raiz cubica de "<<numero<<" es "<<resultado<<". Calculado con la funcion pow."<<endl;
	cout<<"________________________________________________________________\n"<<endl;
	cout<<"CALCULOS DE SENO, CONSENO Y TANGENTE\n"<<endl;
	
	/*Las funciones seno, conseno y tagente en la libreria matematicas realiza los calculos 
	ingresando los valores en RADIANES. Si se desea ingresar el valor en GRADOS se debera 
	realizar la conversion correspondiente, con la siguiente formula:
	
	angulo_en_radianes=((angulo_en_grado*M_PI)/180)
	
	M_PI = es la constante de PI en la libreria.
	
	Las funciones son: 
	sin = seno
	cos = coseno
	tan = tangente
	
	*/
	//Calculo del seno ingresando el valor en radianes.
	cout<<"Para ingresar un numero decimal escribirlo con punto. Ej.: 1.5708 \n"<<endl;
	cout<<"Introduce un angulo (en radianes) para calcular el seno: ";
	cin>>anguloRadianes;
	seno1 = sin(anguloRadianes);
	cout<<"El seno de "<<anguloRadianes<<" es "<<seno1<<". Uso de sin."<<endl;
	
	cout<<"________________________________________________________________\n"<<endl;
	
	//Calculo del seno ingresando el valor en grados.
	cout<<"Introduce un angulo (en grado) para calcular el seno: ";
	cin>>anguloGrado;
	enRadianes=((anguloGrado*M_PI)/180); //conversion de grados a radianes.
	seno2 = sin(enRadianes);
	cout<<"El seno de "<<enRadianes<<" es "<<seno2<<". Uso de sin."<<endl;
	
	cout<<"________________________________________________________________\n"<<endl;
	
	//Calculo del coseno ingresando el valor en radianes.
	cout<<"Introduce un angulo (en radianes) para calcular el coseno: ";
	cin>>anguloRadianes;
	seno1 = cos(anguloRadianes);
	cout<<"El coseno de "<<anguloRadianes<<" es "<<coseno1<<". Uso de cos."<<endl;
	
	cout<<"________________________________________________________________\n"<<endl;
	
	//Calculo del coseno ingresando el valor en grados.
	cout<<"Introduce un angulo (en grado) para calcular el coseno: ";
	cin>>anguloGrado;
	enRadianes=((anguloGrado*M_PI)/180); //conversion de grados a radianes.
	seno2 = cos(enRadianes);
	cout<<"El coseno de "<<enRadianes<<" es "<<coseno2<<". Uso de cos."<<endl;
	
	cout<<"________________________________________________________________\n"<<endl;
	
	//Calculo de la tangente ingresando el valor en radianes.
	cout<<"Introduce un angulo (en radianes) para calcular la tangente: ";
	cin>>anguloRadianes;
	seno1 = tan(anguloRadianes);
	cout<<"El tangente de "<<anguloRadianes<<" es "<<tangente1<<". Uso de tan."<<endl;
	
	cout<<"________________________________________________________________\n"<<endl;
	
	//Calculo de la tangente ingresando el valor en grados.
	cout<<"Introduce un angulo (en grado) para calcular la tangente: ";
	cin>>anguloGrado;
	enRadianes=((anguloGrado*M_PI)/180); //conversion de grados a radianes.
	seno2 = tan(enRadianes);
	cout<<"El tangente de "<<enRadianes<<" es "<<tangente2<<". Uso de tan."<<endl;
	
	cout<<"________________________________________________________________\n"<<endl;
	
	
	return 0;
}

