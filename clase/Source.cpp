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


	for (int i = 0; i < NUM_FILAS; i++)
	{
		for (int j = 0; j < NUM_COLUMNAS; j++)
		{
			campo_jugador_1[i][j] = agua;
			campo_jugador_2[i][j] = agua;
			disparo_jugador_1[i][j] = agua;
			disparo_jugador_2[i][j] = agua;
		}
	}


	cout << "Campo 1" << endl;
	for (int i = 0; i < NUM_FILAS; i++)
	{
		for (int j = 0; j < NUM_COLUMNAS; j++)
		{
			cout << campo_jugador_1[i][j] << " ";
		}
		cout << endl;
	}

	cout << "Campo 2" << endl;
	for (int i = 0; i < NUM_FILAS; i++)
	{
		for (int j = 0; j < NUM_COLUMNAS; j++)
		{
			cout << campo_jugador_2[i][j] << " ";
		}
		cout << endl;
	}

	srand(std::time(NULL));



	for (int i = 0; i < NUM_BARCOS; i++)
	{
		int tamaño_barco = TAMAÑO_BARCOS[i];
		cout << tamaño_barco << endl;
		bool colocado = false;


		while (colocado == false)
		{

			int columna_random = (rand() % 10);
			cout << "Columna random: " << columna_random + 1 << endl; // Debug o error check line

			int fila_random = (rand() % 10);
			cout << "Fila random: " << fila_random + 1 << endl; // Debug o error check line

			int random_posicion = (rand() % 4) + 1; //Sumando uno hacemos que el numero entre 0 i 3 sea entre 1-4 que es mas legible para los humanos 1=ARRIBA 2=ABAJO 3=DERECHA 4=IZQUIERDA
			cout << "Posicion random: " << random_posicion << endl; // Debug o error check line


			if (random_posicion == 1 && fila_random - tamaño_barco >= 0) // ARRIBA
			{

				bool colocar_posible = true;
				for (int i = 0; i < tamaño_barco; ++i)
				{

					if (campo_jugador_1[fila_random - i][columna_random] != '~') { // Barco ya colocado
						colocar_posible = false;
						break;
					}
				}
				if (colocar_posible)
				{

					for (int i = 0; i < tamaño_barco; ++i)
					{
						campo_jugador_1[fila_random - i][columna_random] = 'X'; // Marcando la posición del barco
					}

					for (int i = 0; i < NUM_FILAS; i++)
					{
						for (int j = 0; j < NUM_COLUMNAS; j++)
						{
							cout << campo_jugador_1[i][j] << " ";
						}
						cout << endl;
					}
					colocado = true;
				}

			}
			else if (random_posicion == 2) // ABAJO
			{
				colocado = true;
			}
			else if (random_posicion == 3) // DERECHA
			{
				colocado = true;
			}
			else if (random_posicion == 4) // IZQUIERDA
			{

				colocado = true;
			}



		}

		//FIlA == A VERTICAL (+ abajo - arriba) COLUMNA == Horizontal (--izquierda ++ derecha), 

		/* cout << "Hundir la flota" << endl;
			cout << "By @Edusagnier" << endl;
			cout << "" << endl;

			cout << "Introduce tu nombre Jugador 1: ";
			cin >> jugador[0];


			cout << "Introduce tu nombre Jugador 2: ";
			cin >> jugador[1];

			system("cls");


			cout << "Turno del jugador:" << jugador[0] << endl;
			cout << "" << endl;
		*/

		cout << "";

	}
	


}