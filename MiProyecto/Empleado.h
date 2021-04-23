#pragma once

#include <mysql.h>
#include <iostream>
#include<string.h>
#include<string>
#include "Persona.h"
#include "ConexionBD.h"
using namespace std;
class Empleado :
	public Persona{
	// constructor
public:
	Empleado() {
	}
	Empleado(string nom, string ape, string dir, int tel, string d_pi, string gen, string f_n, string id_p, string f_in_lb, string fe_in ="now()") : Persona (nom, ape, dir,tel ,d_pi, gen, f_n, id_p, f_in_lb, fe_in) {
	}

	// METODOS
	//set (modificar)
	void setNombre(string nom) { nombre = nom; }
	void setApellido(string ape) { apellido= ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	void setDpi(string d_pi) { dpi = d_pi;}
	void setGenero(string gen) { genero = gen; }
	void setFecha_nacimiento(string f_n) { fecha_nacimiento = f_n; }
	void setIdpuesto(string id_p) { idpuesto = id_p; }
	void setFecha_ingreso_labores(string f_in_lb) { fecha_in_lb = f_in_lb; }
	void setFecha_ingreso(string fe_in) { fecha_ingreso = fe_in; }
	//get (mostrar)
	string getNombre() { return nombre; }
	string getApellido() { return apellido; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	string getDpi() { return dpi; }
	string getGenero() { return genero; }
	string getFecha_nacimiento() { return fecha_nacimiento; }
	string getIdPuesto() { return idpuesto; }
	string getFecha_ingreso_labores() { return fecha_in_lb; }
	string getFecha_ingreso() { return fecha_ingreso; }

	// metodo
	void crear_empleado() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string t = to_string(telefono);
		if (cn.getConectar()) {
			string nombre, apellido, direccion, dpi, genero, fecha_nacimiento, idpuesto, fecha_in_lb, t;
			string fecha_ingreso = "now()";
			int telefono;
			cin.ignore();
			cout << "Ingrese nombre:"<<endl;
			getline(cin, nombre);
			cout << ("ingrese apellido:")<<endl;
			getline(cin,apellido);
			cout << "Ingrese direccion: "<<endl;
			getline(cin, direccion);
			cout << "Ingrese telefono" << endl;
			cin >> telefono;
			cin.ignore();
			cout << "Ingrese su DPI" << endl;
			getline(cin,dpi);
			cout << "Ingrese genero (0 o 1)" << endl;
			getline(cin, genero);
			cout << ("Ingrese fecha nacimiento (año, mes, dia): ")<<endl;
			cin >> fecha_nacimiento;
			cin.ignore();
			cout << ("Ingrese  el idpuesto")<<endl;
			getline(cin, idpuesto);
			cout << ("Ingrese la fecha de labor")<<endl;
			cin >> fecha_in_lb;
			cin.ignore();
			cout << "Fecha ingreso";
			cin >> fecha_ingreso;
			string insertar = "insert into empleados(nombres,apellidos,direccion,telefono, dpi,genero ,fecha_nacimiento, idpuesto, fecha_inicio_labores, fechaingreso) values('" + nombre + "','" + apellido+ "','" + direccion + "',"+ t + ",'" + dpi + "','" + genero + "', '"+ fecha_nacimiento+ "',"+ idpuesto+ ",'"+fecha_in_lb+ "','" + fecha_ingreso + "')";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
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

	void leer_empleado() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			cout << "---------------------------------- Datos de Productos --------------------------------" << endl;
			string consulta = "select * from empleados";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "idEmpleado |" << "Nombre |" << "Apellido |" << "Direccion |" << "Telefono |" << "Dpi |    " << "Genero    | "<<" Fecha Nacimiento    |"<< "Idpuesto     |"<< " Fecha de Labores   |  " << "Fecha Ingreso  |"<< endl;
				cout << ("----------------------------------------------------------------------------------------------------------------");
				cout << ("\n");
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " |" << fila[1] << "     |" << fila[2] << "   |" << fila[3] << "        |" << fila[4] << "        |" << fila[5] << "       |" << fila[7] << "       |" << fila[8] << "       |" << fila[9] << "       |" << fila[10] << "       |" << fila[11] << endl;
				}

			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void modificar_empleado() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string IdEmpleado, nombre, apellido, direccion, telefono, dpi, genero,fecha_nacimiento, idpuesto,fecha_in_lb, fecha_ingreso;
			char s;
			cout << "------------------------------------------------" << endl;
			cout << "Ingrese el id del Empleado que desea modificar: ";
			cin >> IdEmpleado;
			string consulta = "select * from empleados where idEmpleado=" + IdEmpleado + "";
			const char* i = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {

				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					cout << "IdEmpleado: " << fila[0] << endl;
					cout << ("Nombre: ") << fila[1] << endl;
					cout << ("Apellido: ") << fila[2] << endl;
					cout << ("Direccion: ") << fila[3] << endl;
					cout << ("Telefono: ") << fila[4] << endl;
					cout << ("Dpi: ") << fila[5] << endl;
					cout << ("Genero: ") << fila[6] << endl;
					cout << ("Fecha nacimiento: ") << fila[7] << endl;
					cout << ("Id Puesto: ") << fila[8] << endl;
					cout << ("Fecha de labor: ") << fila[9] << endl;
					cout << ("Fecha de Ingreso: ") << fila[10] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						system("cls");
						cout << "Ingrese el nuevo nombre del empleado"<<endl;
						cin >> nombre;
						cout << "Ingrese el nuevo apellido del empleado"<<endl;
						cin >> apellido;
						cout << "Ingrese la nueva direccion"<<endl;
						cin >> direccion;
						cout << "Ingrese el nuevo telefono"<<endl;
						cin >> telefono;
						cout << "Ingrese el nuevo dpi"<<endl;
						cin >> dpi;
						cout << "Ingrese el nuevo genero"<<endl;
						cin >> genero;
						cout << "Ingrese nueva fecha de nacimiento" << endl;
						cin >> fecha_nacimiento;
						cout << " Ingrese nuevo id puesto: " << endl;
						cin >> idpuesto;
						cout << "Ingrese nueva fecha de labor" << endl;
						cin >> fecha_in_lb;
						string modificar = "update empleados set nombres = '" + nombre + "', apellidos= '" + apellido + "',direccion = '" + direccion + "',telefono = " + telefono + ",dpi = '" + dpi + "', genero = '" + genero + "', fecha_nacimiento = '"+ fecha_nacimiento +"', idpuesto = '"+ idpuesto +"', fecha_inicio_labores = '"+ fecha_in_lb + "', fechaingreso = '"+ fecha_ingreso +"' where idEmpleado =" + IdEmpleado+ "";
						const char* m = modificar.c_str();
						q_estado = mysql_query(cn.getConectar(), i);
					}
					else {
						cout << ("Modificacion exitosa") << endl;
					}
				}
			}
			else {
				cout << "Error al modificar\n"<<endl;
			}
		}
		else {
			cout << "Error en la conexion\n"<<endl;
		}
		cn.cerrar_conexion();
	}

	void eliminar_empleado() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string Idempleado;
			cout << "------------------------------------------------" << endl;
			cout << "Ingrese el id del registro que desea eliminar\n";
			cin >> Idempleado;
			string eliminar = "delete from empleados where idEmpleado = (" + Idempleado + ")";
			const char* i = eliminar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Eliminacion Exitosa ..." << endl;
			}
			else {
				cout << " xxx Error al eliminar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}


};


class PuestoE :
	public Puesto {

public:
	PuestoE() {}
	PuestoE(string pue) : Puesto(pue) {};
	void setPuesto(string pue) { puesto = pue; }

	string getPuesto() { return puesto; }

	void crear_puesto() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		if (cn.getConectar()) {
			string puesto;
			int telefono;
			cin.ignore();
			cout << "Ingrese puesto:" << endl;
			getline(cin, puesto);

			string insertar = "insert into puestos(puesto) values('" + puesto+ "')";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
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

	void leer_puesto() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			cout << "---------------------------------- Datos de Productos --------------------------------" << endl;
			string consulta = "select * from puestos";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "idPuesto |" << "Puesto|" <<endl;
				cout << ("----------------------------------------------------------------------------------------------------------------");
				cout << ("\n");
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " |" << fila[1]  << endl;
				}

			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}


	void modificar_puesto() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string IdPuesto, Puesto;
			char s;
			cout << "------------------------------------------------" << endl;
			cout << "Ingrese el id del Empleado que desea modificar: ";
			cin >> IdPuesto;
			string consulta = "select * from puestos where idPuesto=" + IdPuesto+ "";
			const char* i = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {

				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					cout << "IdEmpleado: " << fila[0] << endl;
					cout << ("Puesto: ") << fila[1] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						system("cls");
						cout << "Ingrese el nuevo puesto del empleado" << endl;
						cin >> puesto;
						string modificar = "update puestos set puesto= '" + puesto+ "'where idPuesto =" + IdPuesto + "";
						const char* m = modificar.c_str();
						q_estado = mysql_query(cn.getConectar(), i);
					}
					else {
						cout << ("Modificacion exitosa") << endl;
					}
				}
			}
			else {
				cout << "Error al modificar\n" << endl;
			}
		}
		else {
			cout << "Error en la conexion\n" << endl;
		}
		cn.cerrar_conexion();
	}

	void eliminar_puesto() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string IdPuesto;
			cout << "------------------------------------------------" << endl;
			cout << "Ingrese el id del registro que desea eliminar\n";
			cin >> IdPuesto;
			string eliminar = "delete from puestos where idPuesto= (" + IdPuesto+ ")";
			const char* i = eliminar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Eliminacion Exitosa ..." << endl;
			}
			else {
				cout << " xxx Error al eliminar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}


};
