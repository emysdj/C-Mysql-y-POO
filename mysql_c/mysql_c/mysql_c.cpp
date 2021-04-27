// mysql_c.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include "Cliente.h" 

using namespace std;

int main(){
	string nit, nombres, apellidos, direccion, fecha_nacimiento;
	int telefono;
	cout << "Ingrese Nit:";
	getline(cin, nit);
	cout << "Ingrese Nombres:";
	getline(cin, nombres);
	cout << "Ingrese Apellidos:";
	getline(cin, apellidos);
	cout << "Ingrese Direccion:";
	getline(cin, direccion);
	cout << "Ingrese Telefono:";
	cin >> telefono;
	cin.ignore();
	cout << "Fecha Nacimiento:";
	cin >> fecha_nacimiento;

	string e;
	cout << "Ingrese el ID a Editar: ";
	cin >> e;
	cout << "Ingrese nuevo Nombre: ";
	getline(cin, nombres);
	cout << "Ingrese nuevo Apellido: ";
	getline(cin, apellidos);
	cout << "Ingrese nueva Direccion: ";
	getline(cin, direccion);
	cout << "Ingrese nuevo Telefono: ";
	cin >> telefono;
	cin.ignore();
	cout << "Ingrese nueva Fecha de Nacimiento: ";
	cin >> fecha_nacimiento;


		cout << "Ingrese el idEmpleado a eliminar: ";
		cin >> e;


	Cliente c = Cliente(nombres, apellidos, direccion, telefono, fecha_nacimiento, nit);
	c.crear();
	c.leer();
	c.Actualizar();
	c.eliminar();
	system("pause");
   return 0;
}

