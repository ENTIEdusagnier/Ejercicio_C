#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <cstdlib>

#include <windows.h> // DE CHAT GPT para poder hacer wait el cual me permite ver las tablas hechas para debug

using namespace std; //Permite no utilizar std::

#define NUM_FILAS 10
#define NUM_COLUMNAS 10
#define NUM_BARCOS 4
#define JUGADORES 2

void main()
{


	char campo_jugador[JUGADORES][NUM_FILAS][NUM_COLUMNAS], disparo_jugador[JUGADORES][NUM_FILAS][NUM_COLUMNAS];
	char agua = '~';

	int TAMAÑO_BARCOS[NUM_BARCOS] = { 3, 4, 5, 6 };
	short disparo_columna;


	for (int i = 0; i < NUM_FILAS; i++)
	{
		for (int j = 0; j < NUM_COLUMNAS; j++)
		{
			campo_jugador[0][i][j] = agua;
			campo_jugador[1][i][j] = agua;
			disparo_jugador[0][i][j] = agua;
			disparo_jugador[1][i][j] = agua;
		}
	}


	cout << "Campo 1" << endl;
	for (int i = 0; i < NUM_FILAS; i++)
	{
		for (int j = 0; j < NUM_COLUMNAS; j++)
		{
			cout << campo_jugador[0][i][j] << " ";
		}
		cout << endl;
	}

	cout << "Campo 2" << endl;
	for (int i = 0; i < NUM_FILAS; i++)
	{
		for (int j = 0; j < NUM_COLUMNAS; j++)
		{
			cout << campo_jugador[1][i][j] << " ";
		}
		cout << endl;
	}

	srand(std::time(NULL));




	for (int jugador = 0; jugador < JUGADORES; jugador++)
	{
		/*cout << "Jugador: " << jugador << endl; // DEBUG code
		cout << endl;*/


		for (int i = 0; i < NUM_BARCOS; i++)
		{
			int tamaño_barco = TAMAÑO_BARCOS[i];
			cout << "Barco num: " << tamaño_barco << endl;
			cout << endl;

			char char_barco;
			if (tamaño_barco == 3)
			{
				char_barco = '3';
			}
			else if (tamaño_barco == 4)
			{
				char_barco = '4';
			}
			else if (tamaño_barco == 5)
			{
				char_barco = '5';
			}
			else if (tamaño_barco == 6)
			{
				char_barco = '6';
			}

			bool colocado = false;


			while (colocado == false)
			{

				short columna_random = (rand() % 10);

				/*cout << "Columna random: " << columna_random + 1 << endl; // Debug o error check line
				cout << endl;*/

				short fila_random = (rand() % 10);

				/*cout << "Fila random: " << fila_random + 1 << endl; // Debug o error check line
				cout << endl; */

				short random_posicion = (rand() % 4) + 1; //Sumando uno hacemos que el numero entre 0 i 3 sea entre 1-4 que es mas legible para los humanos 1=ARRIBA 2=ABAJO 3=DERECHA 4=IZQUIERDA

				/*cout << "Posicion random: " << random_posicion << endl; // Debug o error check line
				cout << endl; */


				//FIlA == A VERTICAL (+ abajo - arriba) COLUMNA == Horizontal (--izquierda ++ derecha)

				if (random_posicion == 1 && fila_random - tamaño_barco >= 0) // ARRIBA
				{

					bool colocar_posible_1 = true;

					for (int i = 0; i < tamaño_barco; ++i)
					{

						if (campo_jugador[jugador][fila_random - i][columna_random] != agua)  // Verifica que no haya otro barco en los espacios que va a ocupar
						{
							colocar_posible_1 = false;
							break;
						}
					}

					if (colocar_posible_1)
					{

						for (int i = 0; i < tamaño_barco; ++i)
						{
							campo_jugador[jugador][fila_random - i][columna_random] = char_barco; // Añadimos el barco (Numero a la tabla)
						}

						colocado = true;
					}

				}
				else if (random_posicion == 2 && fila_random + tamaño_barco <= 10) // ABAJO
				{
					bool colocar_posible_2 = true;

					for (int i = 0; i < tamaño_barco; ++i)
					{

						if (campo_jugador[jugador][fila_random + i][columna_random] != agua) // Verifica que no haya otro barco en los espacios que va a ocupar
						{
							colocar_posible_2 = false;
							break;
						}
					}
					if (colocar_posible_2)
					{

						for (int i = 0; i < tamaño_barco; ++i)
						{
							campo_jugador[jugador][fila_random + i][columna_random] = char_barco; // Añadimos el barco (Numero a la tabla)
						}


						colocado = true;
					}

				}
				else if (random_posicion == 3 && columna_random + tamaño_barco <= 10) // DERECHA
				{
					bool colocar_posible_3 = true;

					for (int i = 0; i < tamaño_barco; ++i)
					{

						if (campo_jugador[jugador][fila_random][columna_random + i] != agua) { // Verifica que no haya otro barco en los espacios que va a ocupar
							colocar_posible_3 = false;
							break;
						}
					}
					if (colocar_posible_3)
					{

						for (int i = 0; i < tamaño_barco; ++i)
						{
							campo_jugador[jugador][fila_random][columna_random + i] = char_barco; // Añadimos el barco (Numero a la tabla)
						}
						colocado = true;
					}

				}
				else if (random_posicion == 4 && columna_random - tamaño_barco >= 0) // IZQUIERDA
				{
					bool colocar_posible_4 = true;
					for (int i = 0; i < tamaño_barco; ++i)
					{

						if (campo_jugador[jugador][fila_random][columna_random - i] != agua) { // Verifica que no haya otro barco en los espacios que va a ocupar
							colocar_posible_4 = false;
							break;
						}
					}
					if (colocar_posible_4)
					{

						for (int i = 0; i < tamaño_barco; ++i)
						{
							campo_jugador[jugador][fila_random][columna_random - i] = char_barco; // Añadimos el barco (Numero a la tabla)
						}

						colocado = true;
					}
				}

			}

			cout << endl;

		}

	}

	cout << "Campo 1" << endl;
	for (int i = 0; i < NUM_FILAS; i++)
	{
		for (int j = 0; j < NUM_COLUMNAS; j++)
		{
			cout << campo_jugador[0][i][j] << " ";
		}
		cout << endl;
	}

	cout << "Campo 2" << endl;
	for (int i = 0; i < NUM_FILAS; i++)
	{
		for (int j = 0; j < NUM_COLUMNAS; j++)
		{
			cout << campo_jugador[1][i][j] << " ";
		}
		cout << endl;
	}

	cout << "Hundir la flota" << endl;
	cout << "By @Edusagnier" << endl;
	cout << "" << endl;

	Sleep(5000);

	system("cls"); 


	bool jugador_1_ganado = false, jugador_2_ganado = false;
	bool turno_jugador_1 = true, turno_jugador_2 = false;

	while (jugador_1_ganado == false || jugador_2_ganado == false)
	{
		while (turno_jugador_1) 
		{
			cout << "Turno de Jugador 1" << endl;
		
		
		}
	}


}