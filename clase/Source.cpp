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

#define JUGADOR_1 0
#define JUGADOR_2 1

void main()
{


	char campo_jugador[JUGADORES][NUM_FILAS][NUM_COLUMNAS], disparo_jugador[JUGADORES][NUM_FILAS][NUM_COLUMNAS]; //Asignamos una matriz por jugador, filas, columna
	char agua = '~';

	int TAMAÑO_BARCOS[NUM_BARCOS] = { 3, 4, 5, 6 };



	for (int i = 0; i < NUM_FILAS; i++)
	{
		for (int j = 0; j < NUM_COLUMNAS; j++)
		{
			campo_jugador[JUGADOR_1][i][j] = agua;
			campo_jugador[JUGADOR_2][i][j] = agua;
			disparo_jugador[JUGADOR_1][i][j] = agua;
			disparo_jugador[JUGADOR_2][i][j] = agua;
		}
	}


	cout << "Campo 1" << endl;
	for (int i = 0; i < NUM_FILAS; i++)
	{
		for (int j = 0; j < NUM_COLUMNAS; j++)
		{
			cout << campo_jugador[JUGADOR_1][i][j] << " ";
		}
		cout << endl;
	}

	cout << "Campo 2" << endl;
	for (int i = 0; i < NUM_FILAS; i++)
	{
		for (int j = 0; j < NUM_COLUMNAS; j++)
		{
			cout << campo_jugador[JUGADOR_2][i][j] << " ";
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
			// cout << "Barco num: " << tamaño_barco << endl; //DEBUG

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

				short columna_random = (rand() % NUM_FILAS);

				/*cout << "Columna random: " << columna_random + 1 << endl; // DEBUG o error check line
				cout << endl;*/

				short fila_random = (rand() % NUM_COLUMNAS);

				/*cout << "Fila random: " << fila_random + 1 << endl; // DEBUG o error check line
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
		}
	}

	cout << "Campo 1 Barcos" << endl; //Barcos solucionados
	for (int i = 0; i < NUM_FILAS; i++)
	{
		for (int j = 0; j < NUM_COLUMNAS; j++)
		{
			cout << campo_jugador[JUGADOR_1][i][j] << " ";
		}
		cout << endl;
	}

	cout << "Campo 2 Barcos" << endl;
	for (int i = 0; i < NUM_FILAS; i++)
	{
		for (int j = 0; j < NUM_COLUMNAS; j++)
		{
			cout << campo_jugador[JUGADOR_2][i][j] << " ";
		}
		cout << endl;
	}

	Sleep(5000); //CHAT GPT Para parar 5 seg para mirar tablas. DEBUG

	system("cls"); //Limpia la terminal

	//Empieza el juego

	cout << "Hundir la flota" << endl;
	cout << "By @Edusagnier" << endl;
	cout << "" << endl;

	bool ganador = false; //Esta variable nos permitira cerrar el bucle de juego
	bool turno_jugador_1 = true, turno_jugador_2 = false; //Nos permite cambiar de turno de cada jugador cuando sea true

	int count_dado_1 = 0, count_dado_2 = 0; //Contador de cada jugador de cuantos barcos han dado

	short disparo_columna; //Para almacenar los inputs de los jugadores
	short disparo_fila;


	while (ganador == false) // Parara el bucle cuando un jugador de los 2 gane
	{
		while (turno_jugador_1)
		{
			system("cls"); //Limpiamos terminal para borrar lo del otro jugador

			cout << "Turno de Jugador 1" << endl;

			cout << "Campo 1" << endl;
			for (int i = 0; i < NUM_FILAS; i++)
			{
				for (int j = 0; j < NUM_COLUMNAS; j++)
				{
					cout << disparo_jugador[JUGADOR_1][i][j] << " ";
				}
				cout << endl;
			}


			bool disparo_correcto = false;
			bool seguir = false;


			while (disparo_correcto == false)
			{
				cout << "Introduce la fila la cual quieras disparar (1-10)" << endl;
				cin >> disparo_fila;
				disparo_fila = disparo_fila - 1;

				cout << "Introduce la columna la cual quieras disparar (1-10)" << endl;
				cin >> disparo_columna;
				disparo_columna = disparo_columna - 1;

				if (disparo_columna <= 9 && disparo_columna >= 0 && disparo_fila <= 9 && disparo_fila >= 0)
				{
					//cout << "Los numeros de la cordenada estan bien inserado" << endl; //DEBUG
					seguir = true;

				}
				else
				{
					cout << "Los numeros insertados no estan entre 0-10" << endl;
					disparo_correcto = false;
					seguir = false;
				}
	

				if (seguir)
				{
					if (disparo_jugador[JUGADOR_1][disparo_fila][disparo_columna] != agua)
					{
						cout << "Has introducido una cordenada ya insertada" << endl;
						disparo_correcto = false;
					}
					else
					{
						//cout << "Cordenada vacia" << endl; //DEBUG
						disparo_correcto = true;
					}
				}
			}

			if (campo_jugador[JUGADOR_2][disparo_fila][disparo_columna] != agua)
			{
				cout << "Has ACCERTADO barco dado!!" << endl;
				disparo_jugador[JUGADOR_1][disparo_fila][disparo_columna] = 'O';
				count_dado_1++;
			}
			else
			{
				cout << "Has fallado AGUA! " << endl;
				disparo_jugador[JUGADOR_1][disparo_fila][disparo_columna] = 'X';
			}

			cout << "Campo 1" << endl;
			for (int i = 0; i < NUM_FILAS; i++)
			{
				for (int j = 0; j < NUM_COLUMNAS; j++)
				{
					cout << disparo_jugador[JUGADOR_1][i][j] << " ";
				}
				cout << endl;
			}
			

			turno_jugador_1 = false;
			turno_jugador_2 = true;

			if (count_dado_1 == 18) //En caso que de a los 18 barcos GANARA
			{
				cout << "Has hacertado todas, Has ganado jugador 1" << endl;
				ganador = true;
				turno_jugador_1 = false;
				turno_jugador_2 = false;

				cout << "Campo Finalizado Jugador 1" << endl;
				for (int i = 0; i < NUM_FILAS; i++)
				{
					for (int j = 0; j < NUM_COLUMNAS; j++)
					{
						cout << campo_jugador[JUGADOR_1][i][j] << " ";
					}
					cout << endl;
				}

				cout << "Campo Finalizado de GANADOR" << endl;
				for (int i = 0; i < NUM_FILAS; i++)
				{
					for (int j = 0; j < NUM_COLUMNAS; j++)
					{
						cout << campo_jugador[JUGADOR_2][i][j] << " ";
					}
					cout << endl;
				}
			}
			Sleep(3000); //Para dar unos segundos antes de que se limpie la terminal para pasar turno
		}

		while (turno_jugador_2)
		{
			system("cls");

			cout << "Turno de Jugador 2" << endl;

			cout << "Campo 2" << endl;
			for (int i = 0; i < NUM_FILAS; i++)
			{
				for (int j = 0; j < NUM_COLUMNAS; j++)
				{
					cout << disparo_jugador[JUGADOR_2][i][j] << " ";
				}
				cout << endl;
			}


			bool disparo_correcto = false;
			bool seguir = false;
			while (disparo_correcto == false)
			{
				cout << "Introduce la fila la cual quieras disparar (1-10)" << endl;
				cin >> disparo_fila;
				disparo_fila = disparo_fila - 1;

				cout << "Introduce la columna la cual quieras disparar (1-10)" << endl;
				cin >> disparo_columna;
				disparo_columna = disparo_columna - 1;

				if (disparo_columna <= 9 && disparo_columna >= 0 && disparo_fila <= 9 && disparo_fila >= 0)
				{
					//cout << "Los numeros de la cordenada estan bien inserado" << endl; //DEBUG
					seguir = true;

				}
				else
				{
					cout << "Los numeros insertados no estan entre 0-10" << endl;
					disparo_correcto = false;
					seguir = false;
				}

				if (seguir)
				{
					if (disparo_jugador[JUGADOR_2][disparo_fila][disparo_columna] != agua)
					{
						cout << "Has introducido una cordenada ya insertada" << endl;
						disparo_correcto = false;
					}
					else
					{
						//cout << "Cordenada vacia" << endl; //DEBUG
						disparo_correcto = true;
					}
				}
			}

			if (campo_jugador[JUGADOR_1][disparo_fila][disparo_columna] != agua)
			{
				cout << "Has ACCERTADO barco dado!!" << endl;
				disparo_jugador[JUGADOR_2][disparo_fila][disparo_columna] = 'O';
				count_dado_2++;

			}
			else
			{
				cout << "Has fallado AGUA! " << endl;
				disparo_jugador[JUGADOR_2][disparo_fila][disparo_columna] = 'X';
			}


			cout << "Campo 2" << endl;
			for (int i = 0; i < NUM_FILAS; i++)
			{
				for (int j = 0; j < NUM_COLUMNAS; j++)
				{
					cout << disparo_jugador[JUGADOR_2][i][j] << " ";
				}
				cout << endl;
			}

			
			turno_jugador_1 = true;
			turno_jugador_2 = false;

			if (count_dado_2 == 18) //En caso que de a los 18 barcos GANARA
			{
				cout << "Has hacertado todas, Has ganado jugador 2" << endl;
				ganador = true;
				turno_jugador_1 = false;
				turno_jugador_2 = false;

				cout << "Campo Finalizado Jugador 1" << endl;
				for (int i = 0; i < NUM_FILAS; i++)
				{
					for (int j = 0; j < NUM_COLUMNAS; j++)
					{
						cout << campo_jugador[JUGADOR_1][i][j] << " ";
					}
					cout << endl;
				}

				cout << "Campo Finalizado de GANADOR" << endl;
				for (int i = 0; i < NUM_FILAS; i++)
				{
					for (int j = 0; j < NUM_COLUMNAS; j++)
					{
						cout << campo_jugador[JUGADOR_2][i][j] << " ";
					}
					cout << endl;
				}
			}
			Sleep(3000);//Para dar unos segundos antes de que se limpie la terminal para pasar turno
		}
	}
}


