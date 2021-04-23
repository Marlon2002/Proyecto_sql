#pragma once
#include <iostream>
using namespace std;
class Persona {
protected: string nombre, apellido, direccion, dpi, genero,fecha_nacimiento, idpuesto,fecha_in_lb, fecha_ingreso = "now()";
		 int telefono = 0;

protected:
	Persona() {
	}
	Persona(string nom, string ape, string dir, int tel, string d_pi, string gen, string f_n, string id_p, string f_in_lb, string fe_in) {
		nombre = nom;
		apellido = ape;
		direccion = dir;
		fecha_nacimiento = f_n;
		fecha_in_lb = f_in_lb;
		fecha_ingreso = fe_in;
		telefono = tel;
		dpi = d_pi;
		genero = gen;
		idpuesto = id_p;

	}

	
	
};

class Puesto {
protected: string puesto;

protected: Puesto() {}
	Puesto(string pue) {
		puesto = pue;
	
}
};

