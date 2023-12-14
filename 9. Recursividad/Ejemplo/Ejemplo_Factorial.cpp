#include <iostream>
using namespace std;

int calcularFactorial(int);

int main(int argc, char *argv[]) {
	int i=0, num=0, resultado=1;
	cout<<"Calculo del factorial."<<endl;
	cin>>num;
	for(i=1;i<=num;i++){
		resultado=resultado*i;
	}
	cout<<"El factorial de "<<num<<" es: "<<resultado;
	return 0;
}

int calcularFactorial(int num){
	if(num==0){ //caso base
		return 1;
	}else{ //caso recursivo
		return num*calcularFactorial(num-1);
	}
}
	
/*El caso base es que cuando num vale 0 entonces retorna un 1, 
de lo contrario retorna la multiplicacion de num * el factorial del numero anterior n-1. 

Supongamos que introducimos el numero 3, cuyo factorial es 6 (3*2*1 = 6).
1. n=3 No entra al caso base. Guardamos para despues la operacion 3 * factorial(2)
2. n=2 No entra al caso base. Guardamos para despus la operacion 2 * factorial(1)
3. n=1 No entra al caso base. Guardamos para despus la operacion 1 * factorial(0)
4. n=0 Entra al caso base. Retorna 1, por lo tanto factorial(0) = 1
5. Hacemos la ultima operacion que guardamos 1 * factorial(0) = 1 * 0 = 1, 
	por lo tanto factorial(1) = 1
6. Hacemos la siguiente operacion que guardamos 2 * factorial(1) = 2 * 1 = 2, 
	por lo tanto factorial(2) = 2
7. Hacemos la siguiente operacion que guardamos 3 * factorial(2) = 3 * 2 = 6
8. El factorial es 6
*/
