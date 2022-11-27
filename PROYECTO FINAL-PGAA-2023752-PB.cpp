#include <iostream>
#include <string.h>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;
int a;
struct articulo {
	int contador;
	int anioarticulo;
	string nombre;
	string descripcion;
	string genero;
	string clasificacion;
	int inventario;
	float precio;
	float psubtotal;
	float piva;
	float ptotal;

}articulo[3];

int i = 0;

void agregar();
void borrar();
void mostrar();
void comprar();
void cargarArchivo();
void guardarArchivo();
void FECHA();
void PRECIO();
void modificar();


int main() {
	cargarArchivo();
	system("color 2");
	int opc;
	do {
		system("cls");
		system("color 2");
		cout << "\tBienvenido a GAME OVER, que desea hacer?\n\n";
		cout << "\t\t1) Agregar un juego\n\t\t2) Borrar un juego\n\t\t3) Mostrar juegos\n\t\t4) Comprar juego\n\t\t5) Salir de GAME OVER\n\t\t6) limpiar pantalla\n\t\t7) modificar\n";
		do {
			cin.clear();
			cin >> opc;
			if (cin.fail()) {
				system("cls");
				cout << "\t\nUse solo numeros\n";
				cout << "\tBienvenido a GAME OVER, que desea hacer?\n\n";
				cout << "\t\t1) Agregar un juego\n\t\t2) Borrar un juego\n\t\t3) Mostrar juegos\n\t\t4) Comprar juego\n\t\t5) Salir de GAME OVER\n\t\t6) limpiar pantalla\n\t\t7) modificar\n";
			}
		} while (cin.fail());
		switch (opc) {

		case 1:
			system("cls");
			agregar();
			break;

		case 2:
			system("cls");
			borrar();
			break;

		case 3:
			system("cls");
			mostrar();
			break;

		case 4:
			system("cls");
			comprar();
			break;

		case 5:
			system("cls");
			guardarArchivo();

		case 6:
			system("cls");
			break;

		case 7:
			system("cls");
			modificar();

			exit(0);
			break;
		default:
			break;

		}
	} while (opc != 5);

}

void agregar() {
	i = 0;
	bool siono = false;
	system("cls");
	for (i; i <= 2; i++) {
		if (articulo[i].anioarticulo == NULL && i <= 2) {

			do {
				cout << "\n\tIngrese la fecha de lanzamiento del juego (4 digitos)\n";
				do {
					cin.clear();
					cin >> articulo[i].anioarticulo;
					if (cin.fail()) {
						system("cls");
						cout << "\n\tLa fecha debe contener solo numeros\n";
						cout << "\n\tIngrese la fecha del juego (4 digitos)\n";
					}
				} while (cin.fail());
				if (articulo[i].anioarticulo >= 1111 && articulo[i].anioarticulo <= 9999) {
					siono = true;
				}
				else {
					system("cls");
					cout << "\n\tLa fecha debe de ser de 4 digitos\n";
				}
			} while (siono == false);

			siono = false;
			do {
				cout << "\n\tIngrese el precio del juego\n";
				do {
					cin.clear();
					cin >> articulo[i].precio;
					if (articulo[i].precio == false) {

						cout << "\n\tEl precio debe contener solo numeros\n";
						cout << "\n\tIngrese el precio del juego\n";
					}
				} while (cin.fail());
				if (articulo[i].precio >= 0 && articulo[i].precio <= 9999999) {
					siono = true;
				}
				else {
					system("cls");
					cout << "No se puede agregar un valor negativo\n";
				}
			} while (siono == false);

			siono = false;
			do {
				cout << "\n\tCuantos juegos va a agregar al inventario?\n";
				do {
					cin.clear();
					cin >> articulo[i].inventario;
					if (articulo[i].inventario == false) {

						cout << "\n\tEl inventario debe contener solo numeros\n";
						cout << "\n\tCuantos articulo va a agregar al inventario?\n";
					}
				} while (cin.fail());
				if (articulo[i].inventario >= 0 && articulo[i].inventario <= 9999999) {
					siono = true;
				}
				else {
					system("cls");
					cout << "No puede haber inventario negativo\n";
				}
			} while (siono == false);

			cout << "\n\tIngrese el nombre de su juego\n";
			cin.ignore();
			getline(cin, articulo[i].nombre);

			cout << "\n\tIngrese el descripcion de su juego\n";
			cin;
			getline(cin, articulo[i].descripcion);

			cout << "\n\tIngrese el genero de su juego\n";
			cin;
			getline(cin, articulo[i].genero);

			cout << "\n\tIngrese el clasificacion de su juego\n";
			cin;
			getline(cin, articulo[i].clasificacion);

			return;
		}

	}
	if (articulo[3].anioarticulo != NULL) {
		cout << "Todos los espacios estan llenos\n";

	}

	return;
}

void borrar() {
	int borrarcdg;
	int i = 0;
	cout << "Ingresela fecha del juego a borrar\n";
	for (int i = 0; i <= 2; i++) {
		if (articulo[i].anioarticulo == NULL) {
			continue;
		}
		else {
			cout << articulo[i].anioarticulo << " - " << articulo[i].nombre << "\n";
		}
	}

	do {
		cin.clear();
		cin >> borrarcdg;
		if (cin.fail()) {
			cout << "La fecha debe contener solo numeros\n";
			cout << "Ingrese la fecha del juego a borrar\n";
		}
	} while (cin.fail());

	for (int i = 0; i <= 2; i++) {

		if (borrarcdg == articulo[i].anioarticulo) {

			articulo[i].anioarticulo = articulo[i + 1].anioarticulo;
			articulo[i].nombre = articulo[i + 1].nombre;
			articulo[i].precio = articulo[i + 1].precio;
			articulo[i].contador = articulo[i + 1].contador;
			articulo[i].descripcion = articulo[i + 1].descripcion;
			articulo[i].genero = articulo[i + 1].genero;
			articulo[i].clasificacion = articulo[i + 1].clasificacion;

			articulo[i + 1].anioarticulo = NULL;
			articulo[i + 1].nombre = ' ';
			articulo[i + 1].descripcion = ' ';
			articulo[i + 1].genero = ' ';
			articulo[i + 1].clasificacion = ' ';
			articulo[i + 1].precio = NULL;
			articulo[i + 1].contador = NULL;



			return;

		}

	}




	cout << "El articulo no existe\n";
	system("PAUSE");
	return;
}

void mostrar() {
	int i = 0;
	int e = i;
	if (articulo[0].anioarticulo != NULL) {
		cout << "LISTA - FECHA - NOMBRE - PRECIO - INVENTARIO - DESCRIPCION - GENERO - CLASIFICACION \n";
		for (i; i <= 2; i++) {


			articulo[i].contador = i + 1;



			if (articulo[i].anioarticulo == NULL) {
				continue;
			}
			else {

				cout << " " << articulo[i].contador << " - " << articulo[i].anioarticulo << " - " << articulo[i].nombre << " - " << articulo[i].precio << " - " << articulo[i].inventario << " - " << articulo[i].descripcion << " - " << articulo[i].genero << " - " << articulo[i].clasificacion << " - ""\n";
			}
		}
	}
	else {
		cout << "La lista esta vacia\n";
	}
	system("PAUSE");
	return;
}

void comprar() {
	bool siono = false;
	int borrarcdg;
	int cantidad;
	float subtotal;
	float total;
	float iva;
	//int i = 0;
	int contadorInventario = 0;
	int contadorCantidad = 0;

	int b;

	if (articulo[i].anioarticulo == NULL) {
		cout << "La lista esta vacia\n";
		system("PAUSE");
		return;
	}
	else {
		cout << "Ingrese la fecha del juego a comprar\n";
		for (int i = 0; i <= 2; i++) {

			if (articulo[i].anioarticulo == NULL) {
				continue;
			}
			else {
				cout << articulo[i].anioarticulo << " - " << articulo[i].nombre << " - " << articulo[i].descripcion << "\n";
			}
		}
	}

	do {
		cin.clear();
		//cin.ignore();
		cin >> borrarcdg;
		if (cin.fail()) {
			cout << "la fecha debe contener solo numeros\n";
			cout << "Ingrese la fecha del juego a comprar\n";
		}
	} while (cin.fail());

	for (int i = 0; i <= 2; i++) {
		if (borrarcdg == articulo[i].anioarticulo) {

			siono = true;

			break;;
		}
		else {
			cout << "fecha no encontrado\n";
			return;
		}
	}

	if (siono == true) {
		cout << "juego encontrado\nCuantos va a comprar?\n";
		do {
			cin.clear();
			//cin.ignore();
			cin >> cantidad;
			if (cin.fail()) {
				cout << "La cantidad debe contener solo numeros\n";
				cout << "Cuantos va a comprar\n";
				system("PAUSE");
			}
		} while (cin.fail());

		contadorInventario = articulo[i].inventario;
		contadorCantidad = cantidad;
		int contadorCantidad2 = cantidad;

		while (cantidad > articulo[i].inventario) {
			cantidad = cantidad - 1;
			if (cantidad == articulo[i].inventario) {
				break;
			}
		}
		articulo[i].inventario = articulo[i].inventario - cantidad;

		subtotal = articulo[i].precio * cantidad;
		iva = subtotal * .16;
		total = subtotal + iva;

		cout << " - COMPRA - \ FECHA - NOMBRE\n" << articulo[i].anioarticulo << " - " << articulo[i].nombre << "\nPrecio en unidades: " << articulo[i].precio << " (Unidades pedidas: " << contadorCantidad << ", de: " << contadorInventario << " disponibles, solo se cobraran las disponibles)" << "\nSubtotal: " << subtotal << "\nIVA: " << iva << "\nTotal: " << total << "\n";
		system("PAUSE");
		if (articulo[i].inventario <= 0) {
			int b = i;


			articulo[i].anioarticulo = articulo[i + 1].anioarticulo;
			articulo[i].nombre = articulo[i + 1].nombre;
			articulo[i].precio = articulo[i + 1].precio;
			articulo[i].contador = articulo[i + 1].contador;
			articulo[i].inventario = articulo[i + 1].inventario;
			articulo[i].descripcion = articulo[i + 1].descripcion;
			articulo[i].genero = articulo[i + 1].genero;
			articulo[i].clasificacion = articulo[i + 1].clasificacion;

			articulo[i + 1].anioarticulo = NULL;
			articulo[i + 1].nombre = ' ';
			articulo[i + 1].precio = NULL;
			articulo[i + 1].contador = NULL;
			articulo[i + 1].inventario = NULL;
			articulo[i + 1].descripcion = ' ';
			articulo[i + 1].genero = ' ';
			articulo[i + 1].clasificacion = ' ';


			return;

		}



		system("PAUSE");
		return;

	}
	else {
		cout << "El juego no existe\n";
		system("PAUSE");
		return;
	}

}

void guardarArchivo() {
	ofstream archivo;

	archivo.open("articulos.txt");

	if (archivo.fail()) {
		cout << "\n\tNo se pudo abrir el archivo\n";

	}


	for (int i = 0; i <= 2; i++) {
		archivo << articulo[i].anioarticulo << endl;
		archivo << articulo[i].precio << endl;
		archivo << articulo[i].inventario << endl;
		archivo << articulo[i].descripcion << endl;
		archivo << articulo[i].genero << endl;
		archivo << articulo[i].clasificacion << endl;
		if (i != 2)
			archivo << articulo[i].nombre << endl;
		else
			archivo << articulo[i].nombre;
	}
	cout << "\t\nSe ha guardado correctamente\n";
	system("PAUSE");

}

void cargarArchivo() {
	ifstream archivo;
	int i = 0;
	archivo.open("articulos.txt");
	string line = "";

	if (archivo.fail()) {
		cout << "\n\tNo se pudo abrir el archivo\n";
		system("PAUSE");
		return;
	}

	while (!archivo.eof()) {
		getline(archivo, line);
		articulo[i].anioarticulo = stoi(line);
		getline(archivo, line);
		articulo[i].precio = stof(line);
		getline(archivo, line);
		articulo[i].inventario = stoi(line);
		getline(archivo, articulo[i].nombre);
		getline(archivo, articulo[i].descripcion);
		getline(archivo, articulo[i].genero);
		getline(archivo, articulo[i].clasificacion);
		i++;
	}
	cout << "\n;\tSe ha cargado exitosamente el archivo\n";
	system("PAUSE");

	return;
}


void modificar() {
	system("color 2");
	int opc;
	do {
		system("cls");
		system("color 2");
		cout << "\tmodificar\n\n";
		cout << "\t\t8)FECHA\n\t\t9)PRECIO\n\t\t10)LISTA\n\t\t\n";
		do {
			cin.clear();
			cin >> opc;
			if (cin.fail()) {
				system("cls");
				cout << "\t\nUse solo numeros\n";
				cout << "\tmodificar\n\n";
				cout << "\t\t8)FECHA\n\t\t9)PRECIO\n\t\t10)LISTA\n\t\t\n";
			}
		} while (cin.fail());
		switch (opc) {

		case 8:
			system("cls");
			FECHA();
			break;

		}
	} while (opc != 5);
}
void FECHA() {
	int cambiarcg;
	int i = 0;
	cout << "Ingresela fecha del juego a MODIFICAR\n";
	for (int i = 0; i <= 2; i++) {
		if (articulo[i].anioarticulo == NULL) {
			continue;
		}
		else {
			cout << articulo[i].anioarticulo << " - " << articulo[i].nombre << "\n";
		}
	}

	do {
		cin.clear();
		cin >> cambiarcg;
		if (cin.fail()) {
			cout << "La fecha debe contener solo numeros\n";
			cout << "Ingrese la fecha del juego a MODIFICAR\n";
		}
	} while (cin.fail());

	for (int i = 0; i <= 2; i++) {

		if (cambiarcg == articulo[i].anioarticulo) {

			articulo[i].anioarticulo = articulo[i + 1].anioarticulo;
			articulo[i].nombre = articulo[i + 1].nombre;
			articulo[i].precio = articulo[i + 1].precio;
			articulo[i].contador = articulo[i + 1].contador;
			articulo[i].descripcion = articulo[i + 1].descripcion;
			articulo[i].genero = articulo[i + 1].genero;
			articulo[i].clasificacion = articulo[i + 1].clasificacion;

			articulo[i + 1].anioarticulo = NULL;
			articulo[i + 1].nombre = ' ';
			articulo[i + 1].descripcion = ' ';
			articulo[i + 1].genero = ' ';
			articulo[i + 1].clasificacion = ' ';
			articulo[i + 1].precio = NULL;
			articulo[i + 1].contador = NULL;
			return;
		}
	}
	cout << "El articulo no existe\n";
	system("PAUSE");
	return;
}
