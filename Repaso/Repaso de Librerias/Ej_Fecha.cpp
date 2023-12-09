#include <iostream>
#include <ctime>
using namespace std;

int main() {
	//Se obtiene la fecha y hora actual del sistema.
	time_t now = time(0);
	/*La fecha y hora que nos trae esta representada en el Tiempo Universal Coordinado (UTC),
	 * que es la cantidad de segundos que han transcurrido desde el 1 de enero de 1970 hasta hoy.Ej. */
	cout << "Numeros de segundos desde 1 de enero de 1970: " << now << " s."<<endl;
	/*Para poder visualizarla como fecha y hora local. Ej. Thu Mar 30 22:20:58 2017
	 * Se convierte la fecha a una cadena de caracteres.*/
	char* fecha = ctime(&now); //esta conversión se realiza a través de la función ctime()
	cout << "\nFecha y hora local es: " << fecha<< endl;
  /*Para poder visualizar cada uno de los componentes de la fecha por separado, es necesario
   * crear un objeto de la estructura tm de la librería ctime y se asigna la fecha actual por medio
   * de la función localtime().
   */
     tm *ltm = localtime(&now);
     /* La estrcutura tm esta compuesta por los siguientes atributos:
      * tm_sec;   // Segundos pasados del minuto (0-61)
      * tm_min;   // Minutos pasados de la hora (0-59)
      * tm_hour;  // Horas desde medianoche (0-23)
      * tm_mday;  // Dia del mes (1-31)
      * tm_mon;   // Número del mes (0-11)
      * tm_year;  // Años transcurridos desde 1900
      * tm_wday;  // Dia de semana (0-6; Domingo = 0)
      * tm_yday;  // Dia del año (0-365)
      * tm_isdst; /* Adelanto de hora para horario de verano 1=Si; 0=No; -1=Indefinido */
     cout << "di�a: "<<ltm->tm_mday<<endl;
     cout << "mes: "<<ltm->tm_mon<<endl;
     cout << "anio: "<<ltm->tm_year+1900<<endl;
	return 0;
}
