#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <string>
#include <cstdlib>
#include <locale.h> // Libreria que contiene la funcion setlocale
using namespace std; //Permite no utilizar std::

#define NUM_FILAS 10
#define NUM_COLUMNAS 10
#define NUM_BARCOS 4

void main()
{
	setlocale(LC_ALL, ""); // Uso de la funcion setlocale 

	char campo_jugador_1[NUM_FILAS][NUM_COLUMNAS], campo_jugador_2[NUM_FILAS][NUM_COLUMNAS], disparo_jugador_1[NUM_FILAS][NUM_COLUMNAS], disparo_jugador_2[NUM_FILAS][NUM_COLUMNAS];
	char agua = '~';

	int TAMAÑO_BARCOS[NUM_BARCOS] = { 3, 4, 5, 6 };
	string jugador[2];


	for (int i = 0; i < NUM_FILAS; i++) {
		for (int j = 0; j < NUM_COLUMNAS; j++) {
			campo_jugador_1[i][j] = agua;
			campo_jugador_2[i][j] = agua;
			disparo_jugador_1[i][j] = agua;
			disparo_jugador_2[i][j] = agua;
		}
	}


	cout << "Campo 1" << endl;
	for (int i = 0; i < NUM_FILAS; i++) {
		for (int j = 0; j < NUM_COLUMNAS; j++) {
			cout << campo_jugador_1[i][j] << " ";
		}
		cout << endl;
	}

	cout << "Campo 2" << endl;
	for (int i = 0; i < NUM_FILAS; i++) {
		for (int j = 0; j < NUM_COLUMNAS; j++) {
			cout << campo_jugador_2[i][j] << " ";
		}
		cout << endl;
	}

	srand(std::time(NULL));



	for (int i = 0; i < NUM_BARCOS; i++)
	{
		int tamaño_barco = TAMAÑO_BARCOS[i];
		bool colocado = false;


		while (colocado == false) {

			short columna_random = (rand() % 10) + 1;
			cout << "Columna random: " << columna_random << endl; // Debug o error check line

			short fila_random = (rand() % 10) + 1;
			cout << "Fila random: " << fila_random << endl; // Debug o error check line

			short random_posicion = (rand() % 4) + 1; //Sumando uno hacemos que el numero entre 0 i 3 sea entre 1-4 que es mas legible para los humanos 1=ARRIBA 2=DERECHA 3=ABAJO 4=IZQUIERDA
			cout << "Posicion random: " << random_posicion << endl; // Debug o error check line

			if (random_posicion == 1 && columna_random - tamaño_barco >= 0) // ARRIBA
			{
				bool poder_poner = true;

				for (int i = tamaño_barco; i < 0; i--)
				{
					if (campo_jugador_1[fila_random][columna_random - i] != agua)
					{
						poder_poner = false;
						break;
					}
					if (poder_poner)
					{

						for (int i = columna_random; i < tamaño_barco; i++)
						{
							campo_jugador_1[fila_random][i] = tamaño_barco;
						}
						cout << "Campo 1" << endl;
						for (int i = 0; i < NUM_FILAS; i++) {
							for (int j = 0; j < NUM_COLUMNAS; j++) {
								cout << campo_jugador_1[i][j] << " ";
							}
							cout << endl;
						}
						colocado = true;


					}
				}

			}
			else if (random_posicion == 2 && fila_random + tamaño_barco <= 10) // DERECHA	
			{
				bool poder_poner = true;
				for (int i = tamaño_barco; i < 0; i++)
				{
					if (campo_jugador_1[fila_random + i][columna_random] != agua)
					{
						poder_poner = false;
						break;
					}
					if (poder_poner)
					{

						for (int i = fila_random; i < tamaño_barco; i++)
						{
							campo_jugador_1[i][columna_random] = tamaño_barco;
						}
						cout << "Campo 1" << endl;
						for (int i = 0; i < NUM_FILAS; i++) {
							for (int j = 0; j < NUM_COLUMNAS; j++) {
								cout << campo_jugador_1[i][j] << " ";
							}
							cout << endl;
						}
						colocado = true;

					}
				}
			}
			else if (random_posicion == 3 && columna_random + tamaño_barco <= 10) // ABAJO 
			{
				bool poder_poner = true;


			}
			else if (random_posicion == 4 && fila_random - tamaño_barco >= 0) // IZQUIERDA
			{
				bool poder_poner = true;
				for (int i = tamaño_barco; i < 0; i--)
				{
					if (campo_jugador_1[fila_random - i][columna_random] != agua)
					{
						poder_poner = false;
						break;
					}
					if (poder_poner)
					{

						for (int i = fila_random; i < tamaño_barco; i--)
						{
							campo_jugador_1[i][columna_random] = tamaño_barco;
						}
						cout << "Campo 1" << endl;
						for (int i = 0; i < NUM_FILAS; i++) {
							for (int j = 0; j < NUM_COLUMNAS; j++) {
								cout << campo_jugador_1[i][j] << " ";
							}
							cout << endl;
						}
						colocado = true;

					}

				}
			}







		}
		/* cout << "Hundir la flota" << endl;
			cout << "By @Edusagnier" << endl;
			cout << "" << endl;

			cout << "Introduce tu nombre Jugador 1: ";
			cin >> jugador[0];


			cout << "Introduce tu nombre Jugador 2: ";
			cin >> jugador[1];

			system("cls");


			cout << "Turno del jugador:" << jugador[0] << endl;
			cout << "" << endl; */

	}


}