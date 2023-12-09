/*Desarrolle un programa para una inmobiliaria en donde permita gestionar el pago de las expensas de un 
edificio.  los edificios y barrios cerrados.  Algunas consideraciones:
- Las expensas se pagan antes del día 10 de cada mes, sino tiene un recargo de $100 por día de retraso 
dentro del mismo mes que corresponde la expensa, en caso contrario será del $200 por día de los días excedentes.
- Las expensas de cada vivienda se calculan de acuerdo a la cantidad de m2. (1 m2 = $100).

N° Vivienda     Cant. m2    Monto Expensa ($)*  Día Pago del mes    Recargo*    Monto total ($)*
    1               70          7000                  8                0            7000
    2               150         15000                 11              100           15100

*Son columnas calculadas.
Crear un menú de opciones que se repita hasta que el usuario indique “salir” con las siguientes funciones:

1- Generar expensas. En esta función se debe cargar y calcular los datos del arreglo para 5 viviendas.
 1a-La columna número de vivienda debe completarse con números consecutivos empezando por 1.
 2a- La columna cant. de m2 debe obtenerse mediante números aleatorios entre 30 y 500.
 3a- La columna día de pago del mes con números aleatorios entre el 0 y 60. El cero es que el residente aún no pagó. Por lo tanto, aún no se puede calcular el monto total a pagar.
 4a- La columna monto de expensa, recargo y monto total son columnas calculadas en base a los datos anteriores, para cada una de ellas crear una función distinta.
2- Mostrar la expensa de una vivienda en particular. Esta función debe solicitar el número de cliente y luego mostrar el detalle de su expensa.
3- Mostrar la recaudación del mes de la inmobiliaria.
4- Mostrar un listado de las viviendas que han pagado con retraso y que aún no han pagado.
5- Mostrar todas las expensas emitidas en el mes. */

#include <stdio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;


void generar_expensas(int [5][6]);
int calcular_monto_expensa(int);
int calcular_recargo(int);
int calcular_monto_total(int, int, int);
void mostrar_vivienda(int [5][6]);
int calcular_recaudacion(int [5][6]);
void mostrar_retraso_moroso(int[5][6]);
void mostrar(int[5][6]);

int main(int argc, char *argv[]) {
	
	int v[5][6]={0};
	char opcion = ' ';
	srand(time(NULL));
	generar_expensas(v);
	
	do{
		printf("\nMenu de opciones\n");
		printf("\nA. Generar Expensas.");
		printf("\nB. Mostrar expensa de una vivienda en particular.");
		printf("\nC. Recaudación total.");
		printf("\nD. Mostrar pago con retraso y morosos.");
		printf("\nE. Mostrar todas las expensas.");
		printf("\nS. Salir.");
		printf("\nIngrese opcion: ");
		
	
		scanf(" %c", &opcion);
		switch(opcion){
		case 'A':
		case 'a':
			generar_expensas(v);
			break;
		case 'B':
		case 'b':
			mostrar_vivienda(v);
			break;
		case 'C':
		case 'c':
			printf("\nRecaudacion: $%d\n",calcular_recaudacion(v));
			break;
		case 'D':
		case 'd':
			mostrar_retraso_moroso(v);
			break;
		case 'E':
		case 'e':
			mostrar(v);
			break;
		case 'S':
		case 's':
			printf("\nAdios");
		}
	}while(opcion != 'S' && opcion != 's');
	return 0;
}

//Desarrollo de las funciones

void generar_expensas(int v[5][6]){
	int i=0;
	
	for(i=0;i<5;i++){
		//columna 1: Num Vivienda
		v[i][0] = i+1;
		
		//columna 2: m2 entre 30 y 500.
		v[i][1] = rand()%471+30;
		
		//columna 3: monto de la expensa
		v[i][2] = calcular_monto_expensa(v[i][1]);
		
		//columna 4: dia de pago 0 y 60.
		v[i][3] = rand()%61;
		
		//Columna 5: recargo
		v[i][4] = calcular_recargo(v[i][3]);
		
		//Columna 6: monto total
		v[i][5] = calcular_monto_total(v[i][2], v[i][4], v[i][3]);
	}
}
	
int calcular_monto_expensa(int cant_m2){
	int monto_expensa=cant_m2*100;
	return monto_expensa;
}
	
int calcular_recargo(int dia_pago){
	int recargo=0;
	if(dia_pago==0 || dia_pago<=10){
		recargo=0; //aun no pago o pago antes del 10 inclusive
	}else{
		if (dia_pago > 10 && dia_pago <= 30) {
			recargo = 100 * (dia_pago - 10);
		}else{
			if (dia_pago > 30) {
				recargo = (100*20)+(200*(dia_pago - 30));
			}
		} 
	}
	return recargo;
}

int calcular_monto_total(int expensas, int recargo, int dia_pago){
	int monto_total=0;
	if(dia_pago!=0){ // si es cero es que aun no pago, por lo cual no se puede calcular el monto total
		monto_total=expensas+recargo;	
	}
	return monto_total;
}

void mostrar_vivienda(int v[5][6]){
	int j=0, num=0;
	printf("\nIngrese el numero de vivienda: ");
	scanf("%d", &num);
	
	printf("\nNum.\tM2\tExpensa\tDia\tRecargo\tTotal\n");
	for(j = 0; j < 6; j++) {
		printf("%d\t",v[num-1][j]);
	}
}

int calcular_recaudacion(int v[5][6]){
	int i=0, recaudacion=0;
	for(i = 0; i < 5; i++) {
		recaudacion+=v[i][5];
	}
	return recaudacion;
}

void mostrar_retraso_moroso(int v[5][6]){
	int i=0, j=0;
	printf("\nLISTADO DE EXPENSAS PAGADAS CON DEMORA O ADEUDADA");
	printf("\nNum.\tM2\tExpensa\tDia\tRecargo\tTotal\n");
	for(i = 0; i < 5; i++) {
		if(v[i][3]>10 || v[i][5]==0){
			for(j = 0; j < 6; j++) {
				printf("%d\t",v[i][j]);
			}
			printf("\n");
		}
	}
}
	
void mostrar(int v[5][6]){
	int i=0, j=0;
	printf("\nLISTADO COMPLETO DE EXPENSAS");
	printf("\nNum.\tM2\tExpensa\tDia\tRecargo\tTotal\n");
	for(i = 0; i < 5; i++) {
		for(j = 0; j < 6; j++) {
			printf("%d\t",v[i][j]);
		}
		printf("\n");
	}
}