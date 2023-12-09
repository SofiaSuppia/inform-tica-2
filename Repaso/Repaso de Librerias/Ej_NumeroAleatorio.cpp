#include <iostream>
#include <ctime>
using namespace std;

int main(int argc, char *argv[]) {
		int numero=0, cant=0;
		srand(time(NULL)); //Funcion para generar numeros random
		
		printf("NUMEROS RANDOM - ¿COMO DEFINIR EL RANGO?\n");
		printf("\nCaso 1: Numeros random entre el 0 y 99.\n");
		for(int i=0; i<100; i++){
			numero = rand() % 100;//hasta+1
			printf("%d-", numero);
			if(numero==99)
				cant++;
		}
		printf("\nCantidad de 99 %d.\n", cant);
		cant=0;
		printf("\n\nCaso 2: Numeros random entre 1 y 100.\n");
		for(int i=0; i<100; i++){
			numero = rand() % 100 + 1;//hasta+desde
			printf("%d-", numero);
			if(numero==100)
				cant++;
		}
		printf("\nCantidad de 100 %d.\n", cant);
		
		cant=0;
		printf("\n\nCaso 3: Numeros random entre 1990 y 2020.\n");
		for(int i=0; i<100; i++){
			numero = rand() % 31 + 1990;//(hasta-desde+1)+desde
			printf("%d-", numero);
			if(numero==1990)
				cant++;
		}
		printf("\nCantidad de 1990 %d.\n", cant);
	return 0;
}

