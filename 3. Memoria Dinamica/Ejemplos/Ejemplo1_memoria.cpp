#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
	int a=10;
	float b=10.30;
	char c='a';
	double d=10.189;
	
	printf("Espacio en bytes de a: %ld\n", sizeof(a));
	printf("Espacio en bytes de b: %ld\n", sizeof(b));
	printf("Espacio en bytes de c: %ld\n", sizeof(c));
	printf("Espacio en bytes de d: %ld\n", sizeof(d));
	return 0;
}
