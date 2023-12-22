#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <string>
#include <cstdlib>
#include <locale.h> // Libreria que contiene la funcion setlocale
using namespace std; //Permite no utilizar std::


void main()
{
	setlocale(LC_ALL, ""); // Uso de la funcion setlocale
	
	char campo[10][10];

	string jugador[2];
	
	
	for (int i = 0; i < 10; i++)
	{
		campo[i][i] = '~';
	}
	
	cout << campo[1][2] ;

	cout << "Hundir la flota" << endl;
	cout << "By Edu" << endl;
	cout << "" << endl;

	cout << "Introduce tu nombre Jugador 1: ";
	cin >> jugador[0];
	

	cout << "Introduce tu nombre Jugador 2: ";
	cin >> jugador[1];

	system("cls");


	cout << "Turno del jugador:" << jugador[0] << endl;
	cout << "" << endl;

	


	cout << "Barcos" << endl;
	cout << "4 Barcos de 1 cuadrado:" << endl;
	cout << "3 Barcos de 2 cuadrados:" << endl;
	cout << "2 Barcos de 3 cuadrados:" << endl;
	cout << "1 Barco de 4 cuadrados" << endl;
	
}