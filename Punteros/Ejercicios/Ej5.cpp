/*Escribir un programa que solicite dos numeros y luego una de las operaciones
del menu de opciones: 
a. sumar
b. restar
c. multiplicar
d. dividir dos numeros
e. elevar a una potencia
f. calcular la raiz de numero

Luego mostrar el resultado y preguntar si desea realizar otra operacion o 
terminar el programa.

Utilizar punteros para el calculo de las operaciones
Libreria: #include <math.h>
*/

#include <iostream>
#include <math.h>
using namespace std; 

//int menu();

int main(int argc, char const *argv[])
{
    float num1=0, num2=0;
    int op=0;
    float *ptr_num1=&num1, *ptr_num2=&num2;
    do
    {
        
        printf("Ingrese dos numeros:\n");   
		scanf("%f%f",&num1, &num2);
		printf("Menu de operaciones:\n"); 
		printf("1. Sumar\n"); 
		printf("2. Restar\n"); 
		printf("3. Multiplicar\n"); 
		printf("4. Dividir\n"); 
		printf("5. Potencia\n"); 
		printf("6. Raiz cuadrada\n");
		scanf("%d",&op);
        switch (op)
        {
        case 1:
            printf("Resultado de la suma: %0.2f\n",*ptr_num1+*ptr_num2);
            break;
        case 2:
            printf("Resultado de la resta: %0.2f\n",*ptr_num1-*ptr_num2);
            break;
        case 3:
            printf("Resultado de la multiplicacion: %0.2f\n",(*ptr_num1)*(*ptr_num2));
            break;
        case 4:
            printf("Resultado de la division: %0.2f\n",(*ptr_num1)/(*ptr_num2));
            break;
        case 5:
            printf("Resultado de la potencia: %0.2f\n",pow(*ptr_num1,(*ptr_num2)));
            break;
        case 6:
            printf("Resultado de la raiz: %0.2f\n",pow(*ptr_num1,(1/(*ptr_num2)))); 
			printf("Resultado de la raiz cuadrada de n1: %0.2f\n",sqrt(*ptr_num1)); 
			printf("Resultado de la raiz cuadrada de n2: %0.2f\n",sqrt(*ptr_num2));
            break;
        }
    } while (op!=0);
    
    return 0;
}

/*int menu(){
    int op = 0;
    printf("--------------- MENU DE OPCIONES ------------------------\n");
    printf("\nIngrese la opcion que desea: \n");
    printf("1- Suma\n");
    printf("2- Resta\n");
    printf("3- Multiplicacion\n");
    printf("4- Division de dos numeros\n");
    printf("5- Elevar a una potencia\n");
    printf("6- Calcular la raiz de un numero\n");
    printf("\nIngrese la opcion que desea: ");
    scanf("%d",&op);
    return 0;
}*/

