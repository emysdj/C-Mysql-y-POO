#pragma once
#include <mysql.h>
#include<iostream>
#include<string>
#include "Persona.h"
#include "ConexionBD.h"
using namespace std;
class Cliente : Persona{
	// Atributos
private: string nit;
	   //constructor 
public:
	Cliente() {

	}
	Cliente(string nom, string ape, string dir, int tel, string fn, string n) : Persona(nom, ape, dir, tel, fn) {
		nit = n;
	}
	//metodos
	//set (modificar)
	void setNit(string n) { nit = n; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	//get (mostrar)
	string getNit() { return nit; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }

	// metodo 
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string t = to_string(telefono);
		if (cn.getconectar()) {
			string  insertar = "INSERT INTO clientes(nit,nombres,apellidos,direccion,telefono,fecha_nacimiento) VALUES ('" + nit + "','" + nombres + "','" + apellidos + "','" + direccion + "'," + t + ",'" + fecha_nacimiento + "')";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getconectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	void leer() {
		int q_estado; 
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string consulta = "select * from clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getconectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());
				cout << "------------------Clientes-------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6]<<endl;
				}
			}
			else {
				cout << "xxx Error al consultar xxx" << endl;
			}
		}
		else {
			cout << "Error en la Conexion ..." << endl;
		}
		cn.cerrar_conexion();
	}
	void Actualizar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();

		string t = to_string(telefono);
		string e;
		string editar = "update empleado set nombres= '" + nombres + "', apellidos= '" + apellidos + "', direccion= '" + direccion + "', telefono= '" + t + "', fecha_nacimiento= '" + fecha_nacimiento + "', nit= '" + nit + "' where id_clientes= '" + e + "'";
		const char* c = editar.c_str();
		q_estado = mysql_query(cn.getconectar(), c);

		if (!q_estado) {
			cout << "Actualizacion exitosa..." << endl;
		}
		else {
			cout << "**** Error al Actualizar ****" << endl;
		}
	}
	void eliminar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();

		string e;
		string eliminar = "delete from db_empresa.clientes where id_clientes= '" + e + "'";
		const char* f = eliminar.c_str();
		q_estado = mysql_query(cn.getconectar(), f);

		if (!q_estado) {
			cout << "Eliminacion Correcta..." << endl;
		}
		else {
			cout << "**** Error al Eliminar****" << endl;
		}
		cn.cerrar_conexion();
	}
};

