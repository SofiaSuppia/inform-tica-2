#include <iostream>
using namespace std;

#define n1 0
#define n2 1

int calcularFibonacci(int);

int main(int argc, char *argv[]) {
	int i=0, num=0;
	cout<<"Ingrese cuantos numeros de la serie Fibonacci desea ver:"<<endl;
	cin>>num;
	for(i=1;i<=num;i++){
		cout<<calcularFibonacci(i)<<"-";
	}
	return 0;
}

int calcularFibonacci(int num){
	if(num==1){ //caso base
		return n1;
	}else if(num==2){ //caso base
		return n2;
	}else{ //caso recursivo
		return calcularFibonacci(num-1)+calcularFibonacci(num-2);
	}
}
