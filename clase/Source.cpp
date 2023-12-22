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

void main()
{
	setlocale(LC_ALL, ""); // Uso de la funcion setlocale
		
	char campo_jugador_1[NUM_FILAS][NUM_COLUMNAS], campo_jugador_2[NUM_FILAS][NUM_COLUMNAS], disparo_jugador_1[NUM_FILAS][NUM_COLUMNAS],disparo_jugador_2[NUM_FILAS][NUM_COLUMNAS];

	string jugador[2];
	
	
	for (int i = 0; i < NUM_FILAS; i++) {
		for (int j = 0; j < NUM_COLUMNAS; j++) {
			campo_jugador_1[i][j] = '~';
			campo_jugador_2[i][j] = '~';
			disparo_jugador_1[i][j] = '~';
			disparo_jugador_2[i][j] = '~';
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


	rand() % 3 + 4;


		
	cout << "Hundir la flota" << endl;
	cout << "By @Edusagnier" << endl;
	cout << "" << endl;

	cout << "Introduce tu nombre Jugador 1: ";
	cin >> jugador[0];
	

	cout << "Introduce tu nombre Jugador 2: ";
	cin >> jugador[1];

	system("cls");


	cout << "Turno del jugador:" << jugador[0] << endl;
	cout << "" << endl;

	
	
	
}