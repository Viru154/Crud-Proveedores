#pragma once
#include "Persona.h"
#include "ConexionBD.h"
#include <mysql.h>
#include <iostream>
using namespace std;
class Cliente : Persona {
	//Atributos!
private: string nit;
	   //Constructor!
public:
	Cliente(string nom, string ape, string dir, int tel, string fn, string n) : Persona(nom, ape, dir, tel, fn) {
		nit = n;
	}

	void setNit(string n) { nit = n; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setFN(string fn) { fecha_nacimiento = fn; }
	void setTelefono(int tel) { telefono = tel; }

	// get (mostrar)
	string getNit() { return nit; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	string getFN() { return fecha_nacimiento; }
	int getTelefono() { return telefono; }

	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW  fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select * from clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << endl;
				}
			}
			else {
				cout << "Error al ingresar la Informacion X.X" << endl;
			}
		}
		else {
			cout << "Error en la Conexion x.x" << endl;
		}
		cn.cerrar_conexion();
	}
};



