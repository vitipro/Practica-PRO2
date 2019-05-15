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
		if (opcion == "anadir/modificar") { 
			cin >> id;
			if (c.existe_idioma(id)) {
				map<string, Idioma>::iterator it = c.consultar_idioma(id);
				(it->second).modificar_tabla();
				cout << "Modificado " << id << endl << endl;
			}
			else {
				Idioma I;
				I.crea_idioma(id);
				c.anadir_idioma(I);
				cout << "Anadido " << id << endl << endl;
			}
		}
		if (opcion == "codifica") {
			string texto;
			cin >> id >> texto;
			cout << "Codifica en " << id << " el texto:" << endl;
			cout << texto << endl;
			if (c.existe_idioma(id)) {
				map<string, Idioma>::iterator it = c.consultar_idioma(id);
				(it->second).codifica(texto);
			}
			else cout << "El idioma no existe" << endl << endl;        
		}
		if (opcion == "decodifica") {
			string texto;
			cin >> id >> texto;
			cout << "Decodifica en " << id << " el texto:" << endl;
			cout << texto << endl;
			if (c.existe_idioma(id)) {
				map<string, Idioma>::iterator it = c.consultar_idioma(id);
				(it->second).decodifica(texto);
			}
			else cout << "El idioma no existe" << endl << endl;         
		}
		if (opcion == "tabla_frec") {
			cin >> id;
			cout << "Tabla de frecuencias de " << id << ":" << endl;
			if (c.existe_idioma(id)) {
				map<string, Idioma>::iterator it = c.consultar_idioma(id);
				(it->second).escribir_tabla_frec();
			}
			else cout << "El idioma no existe" << endl << endl;
		}
		if (opcion == "treecode") {
			cin >> id;
			cout << "Treecode de " << id << ":" << endl;
			if (c.existe_idioma(id)) {
				map<string, Idioma>::iterator it = c.consultar_idioma(id);
				(it->second).consultar_treecode();
			}
			else cout << "El idioma no existe" << endl << endl;
		}
		if (opcion == "codigos") {
			string s;
			cin >> id >> s;
			if (s == "todos") {
				cout << "Codigos de " << id << ":" << endl;
				if (c.existe_idioma(id)) {
					map<string, Idioma>::iterator it = c.consultar_idioma(id);
					(it->second).consultar_codigos();
				}
				else cout << "El idioma no existe" << endl << endl;
			}
			else {
				cout << "Codigo de " << s << " en " << id << ":" << endl;
				if (c.existe_idioma(id)) {
					map<string, Idioma>::iterator it = c.consultar_idioma(id);    
					(it->second).consultar_codigo_especifico(s);                                      
				}
				else cout << "El idioma no existe o el caracter no esta en el idioma" << endl << endl;
			}
		}
		cin >> opcion;
	}
}