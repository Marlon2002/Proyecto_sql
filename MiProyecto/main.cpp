#pragma once
#include <iostream>
#include"Empleado.h"

void empl_crud();
void puesto_crud();

int main() {
	system("cls");
	cout << "MENU DE TABLAS SIGUIENTES:" << endl;
	cout << "1. TABLA EMPLEADOS" << endl;
	cout << "2. TABLA PUESTOS\n" << endl;
	cout << "Escoga una opcion" << endl;
	int op;
	cin >> op;
	do {
		switch (op){
		case 1:
			empl_crud();
			break;
		case 2:
			puesto_crud();
			break;
		}

	} while (op != 3);
}





void empl_crud() {
	system("cls");
	cout << "Ingrese una opcion de las que se le presentan: " << endl;
	cout << "1. Crear" << endl;
	cout << "2. Leer" << endl;
	cout << "3. Modificar" << endl;
	cout << "4. Eliminar" << endl;
	cout << "5. Regresar a lista de tabla" << endl;
	string nombre, apellido, direccion, dpi, genero, fecha_nacimiento, idpuesto, fecha_in_lb, fecha_ingreso;
	int telefono = 0;
	Empleado e = Empleado(nombre, apellido, direccion, telefono, dpi, genero, fecha_nacimiento, idpuesto, fecha_in_lb, fecha_ingreso);
	int op;
	cin >> op;
	do {
		switch (op){
		case 1:
			system("cls");
			e.crear_empleado();
			system("pause");
			main();
			break;
		case 2:
			system("cls");
			e.leer_empleado();
			system("pause");
			main();
			break;
		case 3: 
			system("cls");
			e.modificar_empleado();
			system("pause");
			main();
			break;
		case 4:
			system("cls");
			e.eliminar_empleado();
			system("pause");
			main();
			break;

		}
	} while (op != 5);

}



void puesto_crud() {
	cout << "Ingrese una opcion de las que se le presentan: " << endl;
	cout << "1. Crear" << endl;
	cout << "2. Leer" << endl;
	cout << "3. Modificar" << endl;
	cout << "4. Eliminar" << endl;
	cout << "5. Regresar a lista de tabla" << endl;
	string puesto;
	PuestoE p = PuestoE(puesto);
	int op;
	cin >> op;
	do {
		switch (op) {
		case 1:
			system("cls");
			p.crear_puesto();
			main();
			break;
		case 2:
			system("cls");
			p.leer_puesto();
			system("pause");
			main();
			break;
		case 3:
			system("cls");
			p.modificar_puesto();
			system("pause");
			main();
			break;
		case 4:
			system("cls");
			p.eliminar_puesto();
			system("pause");
			main();
			break;

		}
	} while (op != 5);

}