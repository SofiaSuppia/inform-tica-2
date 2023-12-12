#include<iostream>
using namespace std;

int main(int argc, char *argv[]) {
    int a = 43, b = 45;
    // Forma 1
    int *ptr1[2];
    ptr1[0] = &a;
    ptr1[1] = &b;
    //Forma 2
    int *ptr2[2] = {&a, &b};
    //Mostrar
	cout<<"VALORES DE ptr1\n\n";
    cout<<"&a="<<&a<<"\tEs la dirección de A.\n";
    cout<<"ptr1[0]="<<ptr1[0]<<"\tEs la direccion de A.\n";
    cout<<"*ptr[0]="<<*ptr1[0]<<"\t\tEs el valor de A.\n";
	cout<<"\nVALORES DE ptr2\n\n";
    cout<<"&b="<<&b<<"\tEs la dirección de B.\n";
    cout<<"ptr2[1]="<<ptr2[1]<<"\tEs la direccion de B.\n";
    cout<<"*ptr2[1]="<<*ptr2[1]<<"\t\tEs el valor de B.\n";
    return 0;
}
