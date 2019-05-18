/** @file Idioma.cc
    @brief Código de la clase Idioma 
*/

#include "Idioma.hh"

Idioma::Idioma() {}

Idioma::~Idioma() {}

string Idioma::consultar_nombre() const 
{
    return nombre;
}

void Idioma::escribir_tabla_frec() 
{
	map<string, int>::const_iterator it = tabla_frec.begin();
	while (it != tabla_frec.end()) {
		cout << it->first << " " << it->second << endl;
		++it;
	}
    cout << endl;
}

void Idioma::consultar_codigos() const
{
	treecode.consultar_codigos();
}

void Idioma::consultar_codigo_especifico(string c) const 
{
    treecode.consultar_codigo_especifico(c);
}

void Idioma::consultar_treecode() const 
{
	treecode.escribir_treecode();
}

void Idioma::leer_tabla_frec() 
{
	int n, f;    // n >= 2
	string c;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> c >> f;
		tabla_frec.insert(make_pair(c, f));
	}
}

void Idioma::modificar_tabla() 
{
	map<string, int> nueva_tabla;                                                            // nueva_tabla es la tabla que se introduce a la hora de añadir o modificar un idioma
	int n, f;     
	string c;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> c >> f;
		nueva_tabla.insert(make_pair(c, f));
	}
	map<string, int>::const_iterator it = nueva_tabla.begin();
	map<string, int>::const_iterator it2;
	while (it != nueva_tabla.end()) {
		it2 = tabla_frec.find(it->first);
		if (it2 != tabla_frec.end()) tabla_frec[it2->first] = it2->second + it->second;       // si el caracter de nueva_tabla ya existia en tabla_frec, se suman sus frecuencias
		else tabla_frec.insert(make_pair(it->first, it->second));                             // si no, se crea una nueva entrada 
		++it;
	}
	treecode.crear_treecode(tabla_frec);
}

void Idioma::leer_idioma() 
{
    cin >> nombre;
    leer_tabla_frec();
    treecode.crear_treecode(tabla_frec);
}

void Idioma::crea_nuevo_idioma(string id) 
{
	nombre = id;
	leer_tabla_frec();
    treecode.crear_treecode(tabla_frec);
}

void Idioma::codifica(string texto) 
{
	treecode.codifica(texto);
}

void Idioma::decodifica(string texto) 
{
	treecode.decodifica(texto);
}