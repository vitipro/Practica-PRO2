#include "Idioma.hh"
#include "Nodo.hh"           
#include "Treecode.hh"
#include <map>
#include <iostream>
using namespace std;

Idioma::Idioma() {}

Idioma::~Idioma() {}

//Idioma::Idioma(string id, vector<Nodo> v) {
//    this->nombre = id;
//    this->tabla_frec = v;
//}

//void Idioma::modificar_tabla(vector<Nodo>& tabla) {
	
//}

string Idioma::consultar_nombre() const {
    return nombre;
}

bool ordena(const Nodo& n1, const Nodo& n2) {
	return n1.consultar_caracter() < n2.consultar_caracter();
}

void Idioma::escribir_tabla_frec() {
	sort(tabla_frec.begin(), tabla_frec.end(), ordena);
    for (int i = 0; i < tabla_frec.size(); ++i) tabla_frec[i].escribir();
    cout << endl;
}

void Idioma::asignar_codigos() {
	for (int i = 0; i < tabla_frec.size(); ++i) {
		Nodo n = tabla_frec[i];
		string codigo = treecode.codigo_nodo(n);
		diccionario.insert(make_pair(n.consultar_caracter(), codigo));
	}
}

void Idioma::consultar_codigos() const {
    map<string, string>::const_iterator it = diccionario.begin();
    while (it != diccionario.end()) {
        cout << it->first << " " << it->second << endl;
        ++it;
    }
    cout << endl;
}

void Idioma::consultar_codigo_especifico(string c) const {
    map<string, string>::const_iterator it = diccionario.find(c);
    if (it == diccionario.end()) cout << "El idioma no existe o el caracter no esta en el idioma" << endl;
    else cout << it->first << " " << it->second << endl;
    cout << endl;
}

void Idioma::consultar_treecode() const {
	treecode.escribir_treecode();
}

void Idioma::leer_idioma() {
    Nodo n;
    vector<Nodo> v;
    int a;
    cin >> nombre;
    cin >> a;
    for (int i = 0; i < a; ++i) {
        n.leer();
        v.push_back(n);
    }
    tabla_frec = v;
    treecode.crear_treecode(v);
	asignar_codigos();
}
