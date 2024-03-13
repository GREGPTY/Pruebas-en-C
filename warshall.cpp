#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include "DM4th/DM4th.h"
using namespace std;

//Prototipado
void gotoxy(int, int);
void Menu();
void matriz();
int Warshall(int, int, int);

//Variables Globales
int n = 0;
int **ady;
int op = 0;

//Funciones

//Funcion principal
int main() {
	Menu();
	gotoxy(16, 18); system("pause");
}

//Funcion para posicionamiento en las coordenadas [x, y]
void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

//Funcion de Menu
void Menu() {
	system("cls");
	gotoxy(16, 9); cout << "|-----------------------------------Menu Principal-----------------------------------|" << endl;
	gotoxy(16, 10); cout << "|                                                                                    |" << endl;
	gotoxy(16, 11); cout << "| Ingresar Nueva Matriz __________________________________________________________ 1 |" << endl;
	gotoxy(16, 12); cout << "| Salir __________________________________________________________________________ 2 |" << endl;
	gotoxy(16, 13); cout << "|                                                                                    |" << endl;
	gotoxy(16, 14); cout << "| Opcion:                                                                            |" << endl;
	gotoxy(16, 15); cout << "|                                                                                    |" << endl;
	gotoxy(16, 16); cout << "|------------------------------------------------------------------------------------|" << endl;
	gotoxy(27, 14); cin >> op;

	do {
		switch (op)
		{
		case 1:
			matriz();
			system("pause");
			Menu();
			break;

		case 2:
			gotoxy(16, 18); cout << "Bye..." << endl;
			gotoxy(16, 20); system("pause");
			exit(0);
			break;

		default:
			gotoxy(16, 18); cout << "Lo siento, no he comprendido tu comando, intentalo nuevamente" << endl;
			gotoxy(16, 20); system("pause");
			Menu();
			break;
		}
	} while (op != 2);

}

//Funcion de llenado de matriz
void matriz() {
	system("cls");
	cout << "Para ingresar el tamanio de la matriz solo es necesario colocar un numero (Ej. 3, el cual equivale a una matriz de 3x3)" << endl;
	cout << "Ingrese el Tamanio de la matriz: ";
	cin >> n;
	cout << endl;
	cout << endl;
	cout << "NOTA: El algoritmo de Warshall trabaja unicamente con 0s y 1s, donde 0 indica que no existe relacion entre los nodos y 1 indica que si existe relacion entre los nodos." << endl;
	cout << endl;

	//Proceso para la creacion de la matriz ady
	ady = new int*[n]; //ady es igual un nuevo valor de entero n
	for (int i = 0; i <= n; i++) {
		ady[i] = new int[n]; //ady en la posicion [i] es igual a un nuevo entero n
	}
	ady[n][n]; //se crea una matriz de tamanio ady[n][n], la cual es una matriz cuadratico de tamanio n

	//Proceso para el llenado de la matriz ady
	for (int f = 0; f < n; f++) { //para un entero f ("fila") igual 0, menor o igual que n, f incrementa de 1 en 1
		for (int c = 0; c < n; c++) { //para un entero c ("columna") igual a 0, menor o igual que n, c incrementa de 1 en 1
			cout << "Ingrese los datos de la posicion [ " << f << " ][ " << c << " ]: ";
			cin >> ady[f][c]; //Se ingresa el valor deseado (0 o 1) en la posicion i, j
		}
	}

	cout << endl;
	cout << endl;
	cout << "|--------------------------------------MATRIZ DE ADYACENCIA--------------------------------------|" << endl;
	cout << endl;
	//Proceso para el mostreo de la matriz de adyacencia
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << "|   " << ady[i][j] << "   |";
		}
		cout << endl;
	}

	//Proceso para la conversion de la matriz de adyacencia
	for (int k = 0; k <= n - 1; k++) {
		for (int i = 0; i <= n - 1; i++) {
			for (int j = 0; j <= n - 1; j++) {
				ady[i][j] = Warshall(i, j, k);
			}
		}
	}

	system("pause");
	cout << endl;
	cout << endl;
	cout << "|--------------------------------------MATRIZ DE CLAUSURA TRANSITIVA--------------------------------------|" << endl;
	cout << endl;
	//Proceso para el mostreo de la matriz de clausura transitiva
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << "|   " << ady[i][j] << "   |";
		}
		cout << endl;
	}
	cout<<"\n\n\n"<<endl;
	cout<<"---------------------------------------2da PARTE ---------------------------------------"<<endl;
NDArray<number> caminos = items<number>(
 0,1,0,0,
 0,0,0,1,
 0,0,0,0,
 1,0,1,0
 ).reshape(4,4);
 NDArray<number> resultado = warshall(caminos);
 cout<<"El resultado es:"<<endl;
 cout<<resultado<<endl;
 cin.get();
}

//Funcion que realiza el algoritmo de Warshall
int Warshall(int i, int j, int k) {
	if ((ady[i][j] == 1) || (ady[i][k] == 1) && (ady[k][j] == 1)) { //Si la matriz ady en la posicion i, j es igual a 1 o en la posicion i, k es igual a 1 pero ademas en la posicion k, j es igual a 1
		return 1; //entonces duevuelve el valor 1
	}
	else {
		return 0; //de lo contrario retorna un 0
	}
}
