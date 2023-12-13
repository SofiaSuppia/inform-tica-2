/*Crear un programa que pregunte al usuario cuantos precios de 
acciones de la bolsa de valores desea introducir, reserve espacio 
para dicha cantidad de precios. Los precios pueden ser ingresados 
por teclado u obtenerlos de manera aleatoria. Luego el programa 
debera poder mostrar todos los precios ingresados, mostrar el 
precio promedio de la accion, y agregar mas precios, es decir 
aumentar la cantidad de reserva de espacio. Una vez que el 
usuario desea terminar, el programa debera liberar la memoria. 
Disee este ejercicio  de manera modular, es decir utilizando 
funciones, puede agregar un menu de opciones.*/

#include <stdio.h>
#include <stdlib.h>

int menu();
void cargar(float *precio, int cant);
void mostrarPrecios(float *precio, int cant);
float calcularPromedio(float *precios, int cantidad);

int main(int argc, char const *argv[])
{
    int cant = 0, op = 0;
    float *precio = 0;

    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            // Ingresar precios de acciones
            printf("\nIngrese la cantidad de precios que desea introducir: ");
	        scanf("%d", &cant);
	        if (precio != NULL) {
		        free(precio); // Liberar memoria si ya se ingresaron precios antes
	        }
	        precio = (float *)malloc(cant * sizeof(float));
            cargar(precio,cant);
            break;
        
        case 2:
            // Mostrar precios ingresados
	        if (cant > 0) {
		        mostrarPrecios(precio, cant);
	        } else {
		        printf("\nNo se han ingresado precios todavia.\n");
	        }
            break;

        case 3:
            // Calcular precio promedio
			if (cant > 0) {
				float promedio = calcularPromedio(precio, cant);
				printf("\nEl precio promedio de las acciones es: %.2f\n", promedio);
			} else {
				printf("\nNo se han ingresado precios todavia.\n");
			}
            break;
        
        case 4:
            // Agregar mas precios
            if (cant > 0) {
            int nuevaCantidad;
            printf("\nIngrese la cantidad de precios adicionales que desea agregar: ");
            scanf("%d", &nuevaCantidad);
            precio = (float *)realloc(precio, (cant + nuevaCantidad) * sizeof(float));
            printf("\nIngrese los precios adicionales de las acciones:\n");
            for (int i = cant; i < cant + nuevaCantidad; i++) {
                scanf("%f", &precio[i]);
            }
            cant += nuevaCantidad;
            } else {
            printf("\nNo se han ingresado precios todav�a.\n");
            }
            break;
        
        case 5:
            // Terminar y liberar memoria
			if (precio != NULL) {
				free(precio);
			}
			printf("\nPrograma finalizado. Memoria liberada.\n");
			return 0;
            break;
        }
    } while (op!=0);
    
    return 0;
}

int menu(){
    int op = 0;
    printf("\n---------------------------------------------------------------");
    printf("\n Menu de Opciones\n");
    printf("1. Ingresar precios de acciones\n");
    printf("2. Mostrar precios ingresados\n");
    printf("3. Calcular precio promedio\n");
    printf("4. Agregar mas precios\n");
    printf("5. Terminar y liberar memoria\n");
    printf("\nSeleccione la opcion que desea: ");
    scanf("%d",&op);
    printf("\n---------------------------------------------------------------");
    return op;
}

void cargar(float *precio, int cant){
    printf("\nIngrese los precios de las acciones:\n");
	for (int i = 0; i < cant; i++) {
		scanf("%f", precio + i); //es lo mismo que &precios[i]
	}
}

// Funcion para mostrar los precios de las acciones
void mostrarPrecios(float *precio, int cant) {
	printf("\nPrecios de las acciones: \n");
	for (int i = 0; i < cant; i++) {
		printf("%0.2f \t", *(precio+i));
	}
	printf("\n");
}

// Funcion para calcular el precio promedio de las acciones
float calcularPromedio(float *precios, int cantidad) {
	float suma = 0.0;
	for (int i = 0; i < cantidad; i++) {
		suma += *(precios+i);
	}
	return suma / cantidad;
}

