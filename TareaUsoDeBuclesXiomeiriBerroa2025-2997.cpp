
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {

	char respuesta;

	// 'do' repite el procesamiento de grupos mientras el usuario responda s.
	do {

		cout << "Registro de calificaciones" << endl;

		int totalEstudiantes = 1;

		cout << "Ingrese la cantidad de estudiantes" << endl;
		cin >> totalEstudiantes;

		// 'while' valida que la cantidad de estudiantes sea mayor a 0, si no se cumple repite la condicion.
		while (totalEstudiantes <= 0) {

			cout << "Ingrese un numero mayor a 0. " << endl;
			cin >> totalEstudiantes;
		}


		string nombre;
		int calificacion;
		int sumaNotas = 0;
		double promedio;

		int aprobados = 0;
		int reprobados = 0;
		double sumaPromediosGrupo = 0;
		double promedioGrupo;

		double mayorPromedio = -1;
		string mejorEstudiante;

		// Este primer 'for' hace que por cada estudiante se le pregunte su nombre y calcular el promedio.
		for (int i = 1; i <= totalEstudiantes; i++) {

			cout << "Nombre del estudiante: " << endl;
			cin >> nombre;

			sumaNotas = 0;

			// 2do 'for' hace que 4 veces se le pregunte sobre la calificacion de cada esrudiante.
			for (int j = 1; j <= 4; j++) {

				cout << "Ingrese las calificacione: " << j << ": " << endl;
				cin >> calificacion;

				// 'while' valida que la calificacion puesta por el usuario sea mayor a 0 y menor a 100, si no se cumple repite la condicion.
				while (calificacion < 0 || calificacion > 100) {
					cout << "La calificacion debe estar entre 0 y 100." << endl;
					cout << "Ingrese nuevamente la calificacion " << j << ": " << endl;
					cin >> calificacion;

				}

				sumaNotas = sumaNotas + calificacion;



			}

			promedio = sumaNotas / 4.0;

			cout << fixed << setprecision(2);
			cout << "Promedio: " << promedio << endl;

			if (promedio >= 70) {

				cout << "Aprobado" << endl;

			}
			else {
				cout << "Reprobado" << endl;
			}

			if (promedio >= 70) {
				cout << "Aprobado" << endl;
				aprobados++;

			}
			else {
				cout << "Reprobado" << endl;
				reprobados++;
			}

			sumaPromediosGrupo = sumaPromediosGrupo + promedio;

			if (promedio > mayorPromedio) {

				mayorPromedio = promedio;
				mejorEstudiante = nombre;

			}

		}

		promedioGrupo = sumaPromediosGrupo / totalEstudiantes;

		cout << endl;
		cout << "===== RESUMEN DEL GRUPO =====" << endl;

		cout << "Estudiantes aprobados: " << aprobados << endl;
		cout << "Estudiantes reprobados: " << reprobados << endl;

		cout << "Promedio general del grupo: "
			<< promedioGrupo << endl;

		cout << "Mejor estudiante: " << mejorEstudiante << endl;

		cout << "Promedio mas alto: " << mayorPromedio << endl;

		cout << "\nDesea procesar otro grupo? (s/n): " << endl;
		cin >> respuesta;
		
      //'while' permite repetir el programa completo mientras el usuario responda 's' o 'S'.
	} while (respuesta == 's' || respuesta == 'S');

	cout << "Programa finalizado." << endl;


		return 0;

}
