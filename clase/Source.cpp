#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std; //Permite no utilizar std::


void main()
{
	/*


	std::cout << "Hello World!" << std::endl;

	int numero_entero = 3;
	std::cout << numero_entero << std::endl;
	float numero_decimal;

	numero_decimal = 8.888; //Se puede poner 8.888f para recalcar el tipo de variable (No neccesario en c++)

	prova = 'h';

	bool como_estas = true;

	como_estas = false;

	std::cout << prova << std::endl;

	std::cout << como_estas << std::endl;


	float variable_2 = variable_1;
	std::cout << variable_2 << std::endl;

	//char tt = 'm';
	//float lol = -5.4;
	//short op = 31000;
	//unsigned long po = 2150000000;

	// + suma entre valores - resta entre variables / divide % residuo divisiom ++ suma incremental -- resta incremental
	//+= suma a la variable -= resta variable ...

	//int base = 4;

	//int area = base * base;

	//std::cout <<"Area és: " << area << std::endl;

	//double pi = 3.1415926535;
	//float radio = 10.5;

	//float area_circulo = pi * radio;

	//std::cout << "Area del circulo és: " << area_circulo << std::endl;


	cout << "	     *" << std::endl;
	cout << "	   * * *" << std::endl;
	cout << "	  * * * *" << std::endl;
	cout << "	 * * * * *" << std::endl;
	cout << "	* * * * * *" << std::endl;

	//string nom;
	//cout << "Quin és el teu nom? " << std::endl;
	//cin >> nom;

	//short edad;
	//cout << "Quina és la teva edad? " << std::endl;
	//cin >> edad;


	//cout << "El teu nom és: " << nom << " amb l'edad de: " << edad << "años";
	//cout << &nom; //indica la direcion de memoria

	float num_1, num_2;

	cout << "Num 1?: " << std::endl;
	cin >> num_1;
	cout << "Num 2?: " << std::endl;
	cin >> num_2;

	float suma_nums = num_1 + num_2;

	cout << "La suma és: " << suma_nums << std::endl;

	// para cuando es 0 i suma impares i pares
	int valor_usr;
	int suma_pares = 0;
	int suma_impares = 0;
	bool permanecer = 1;

	while (permanecer == 1){
		cout << "Introduce un numero: \n";
		cin >> valor_usr;

		if (valor_usr == 0)
		{
			permanecer = 0;
			cout << "suma pares = " << suma_pares << endl << "suma impares = " << suma_impares;
		}
		else if (valor_usr % 2 == 0)
		{
			suma_pares = suma_pares + valor_usr;
		}else {

			suma_impares = suma_impares + valor_usr;
		}
	}


	int random_1, random_2, multiplicacion;
	int respuesta, contador = 0;


	bool respuesta_fallada = false;

	while (respuesta_fallada == false)
	{
		srand(time(NULL));
		random_1 = rand() % 10 + 1;
		random_2 = rand() % 10 + 1;

		multiplicacion = random_1 * random_2;

		cout << "Cual es el resultado de esta multiplicacion: " << random_1 <<"+"<< random_2 << endl;
		cin >> respuesta;

		if (respuesta == multiplicacion)
		{
			cout << "Pregunta correcta";
			contador++;
		}
		else {
			cout << "Has fallado" << endl << "Respuestas accertadas: "<< contador;
			respuesta_fallada = true;
		}

	}


	int usr_num[10];
	int suma=0;
	int promedio = 0;

	for ( int i = 0; i < 10; i++)
	{
		cout << "Introduce un numero positivo:" << endl;
		cin >> usr_num[i];

		if (usr_num[i] < 0 )
		{

			while (usr_num[i] < 0)
			{
				cout << "Numero inccorecto ha de ser positivo:" <<endl;
				cin >> usr_num[i];
			}
		}
		cout << "Valor correcto" << endl;
		suma = suma + usr_num[i];


	}
	promedio = suma / 10;
	cout << "El promedio de tus numeros es:" << promedio;




	int num_usr_operacion[2];
	int resultado = 0;
	int operacion = 5;



	do {
		cout << "Introduce un numero;" << endl;
		cin >> num_usr_operacion[0];
		cout << "Introduce otro numero;" << endl;
		cin >> num_usr_operacion[1];

		cout << "Elige una opcion de las siguientes:" << endl;
		cout << "1. Suma" << endl;
		cout << "2. Resta" << endl;
		cout << "3. Multiplicacion" << endl;
		cout << "4. Division" << endl;
		cout << "5. Salir" << endl;
		cin >> operacion;

		switch (operacion) {

		case 1:
			operacion = 1;
			resultado = num_usr_operacion[0] + num_usr_operacion[1];
			cout << "El resultado de la suma es: " << resultado << endl;
			break;
		case 2:
			operacion = 2;
			resultado = num_usr_operacion[0] - num_usr_operacion[1];
			cout << "El resultado de la resta es: " << resultado << endl;
			break;

		case 3:
			operacion = 3;
			resultado = num_usr_operacion[0] * num_usr_operacion[1];
			cout << "El resultado de la multiplicacion es: " << resultado << endl;
			break;
		case 4:
			operacion = 4;
			resultado = num_usr_operacion[0] / num_usr_operacion[1];
			cout << "El resultado de la division es: " << resultado << endl;
			break;
		case 5:
			operacion = 5;
			break;
		}

	} while (operacion != 5);


	int num_filas;
	int num = 1;
	int num_1 = 1;

	cout << "Numero de filas de numeros:" << endl;
	cin >> num_filas;

	for (int i = 0; i <= num_filas; i++)
	{
		for (int j = 0; j <= i; j++ )
		{
			cout << num << " ";
			num++;


		}
		cout << endl;
	}



	int user_num1;
	int user_num2;
	int num_large = 0;
	int num_small = 0;

	cout << "Introduce un numero: ";
	cin >> user_num1;

	cout << "Introduce otro numero: " << endl;
	cin >> user_num2;

	if (user_num1 >= user_num2)
	{
		num_large = user_num1;
		num_small = user_num2;
	}
	else
	{
		num_large = user_num2;
		num_small = user_num1;
	}

	for (int i = num_small; i <= num_large ; i++)
	{
		if (i % 2 == 0)
		{
			continue;
		}

		if (i % 7 == 0)
		{
			break;
		}
		cout << i << endl;

	}
	*/

	string listado = "    A   B   C   D   E   F   G   H   I   J";
	string fila = "  +---+---+---+---+---+---+---+---+---+---+";
	
	string column = " |   |   |   |   |   |   |   |   |   |   |";
	
	string columnas[10];

	string jugador[2];
	
	
	for (int i = 0; i <= 8; i++)
	{
		columnas[i]= to_string(i+1) + column;
	}
	
	columnas[9] = "10|   |   |   |   |   |   |   |   |   |   |";

	cout << "Hundir la flota" << endl;
	cout << "By Edu" << endl;
	cout << "" << endl;

	cout << "Introduce tu nombre Jugador 1: ";
	cin >> jugador[0];
	

	cout << "Introduce tu nombre Jugador 2: ";
	cin >> jugador[1];

	system("cls");

	cout << listado << endl;
	cout << fila << endl << columnas[0] << endl 
		<< fila << endl << columnas[1] << endl 
		<< fila << endl << columnas[2] << endl 
		<< fila << endl << columnas[3] << endl 
		<< fila << endl << columnas[4] << endl 
		<< fila << endl << columnas[5] << endl 
		<< fila << endl << columnas[6] << endl 
		<< fila << endl << columnas[7] << endl
		<< fila << endl << columnas[8] << endl
		<< fila << endl << columnas[9] << endl 
		<< fila;

	cout << "Barcos";
	

	
}