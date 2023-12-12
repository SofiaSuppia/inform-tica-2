#include<iostream>
using namespace std;
#define PI_DEFINE 3.1416;
int main() {
	cout << "El valor de PI_DEFINE es " << PI_DEFINE;
/* Tener en cuenta que la instrucción #define no se esta creando una constante sino una expresión. Por ejemplo, si intentamos mostrar PI_DEFINE de la siguiente manera:
cout << "El valor de PI_DEFINE es " << PI_DEFINE << endl;
Veremos que no funciona, ya que PI_DEFINE no es una variable, es por ello que para este caso se 
debe utilizar una constante. Por ejemplo: */
	const float PI_CONSTANTE  = 3.1416; //Se declara una constante llamada PI_CONSTANTE
	cout << "\nEl valor de PI_CONSTANTE es " << PI_CONSTANTE <<"."<<endl;
	return 0;
}
