/** 
	@mainpage Codificación y decodificación 
	
	Se ha construido un programa poniendo en práctica diseño modular, cuya función es codificar y decodificar textos escritos usando diferentes idiomas.
	
	Este contiene un menú con diferentes opciones para también obtener información de los diferentes idiomas y sus codificaciones.
*/
	
/** @file main.cc
	@brief Programa principal
	
*/

#include "Cjto_idiomas.hh"

#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#endif

int main() {
	Cjto_idiomas c;
	c.leer_conjunto();
	string opcion;
	while (opcion != "fin") {
		string id;
		/*if (opcion == "añadir/modificar") {
			Idioma I;
			I.leer_idioma();
			id = I.consultar_nombre();
			if (c.existe_idioma(id)) c.modificar_idioma(I);
			else c.anadir_idioma(I);
		}
		if (opcion == "codifica") {
			string texto;
			cin >> id >> texto;
			c.codifica_idioma(id, texto);        // codifica_idioma ya dirá si el idioma existe o si es codificable
		}
		if (opcion == "decodifica") {
			string texto;
			cin >> id >> texto;
			c.decodifica_idioma(id, texto);     // decodifica_idioma ya dirá si el idioma existe o si es decodificable
		}*/
		if (opcion == "tabla_frec") {
			cin >> id;
			cout << "Tabla de frecuencias de " << id << ":" << endl;
			if (c.existe_idioma(id)) c.consultar_idioma(id).escribir_tabla_frec();
			else {
				cout << "El idioma no existe" << endl;
				cout << endl;
			}
		}
		if (opcion == "treecode") {
			cin >> id;
			if (c.existe_idioma(id)) c.consultar_idioma(id).consultar_treecode();
			else cout << "El idioma no existe" << endl;
		}
		if (opcion == "codigos") {
			string s;
			cin >> id >> s;
			if (s == "todos") {
				cout << "Codigos de " << id << ":" << endl;
				if (c.existe_idioma(id)) c.consultar_idioma(id).consultar_codigos();
				else cout << "El idioma no existe" << endl;
			}
			else {
				cout << "Codigo de " << s << " en " << id << ":" << endl;
				if (c.existe_idioma(id)) c.consultar_idioma(id).consultar_codigo_especifico(s);        // si el idioma existe pero el caracter no, consultar_codigo_especifico() avisará 
				else cout << "El idioma no existe o el caracter no esta en el idioma" << endl;
			}
		}
		cin >> opcion;
	}
}
