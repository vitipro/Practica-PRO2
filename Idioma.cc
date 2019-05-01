#include "Idioma.hh"
#include "Nodo.hh"           
#include "Treecode.hh"
#include <vector>
#include <map>
#include <algorithm>
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

string Idioma::consultar_nombre() {
    return nombre;
}

vector<Nodo> Idioma::consultar_tabla_frec() {
    return tabla_frec;
}

bool ordena(const Nodo& n1, const Nodo& n2) {
	return n1.consultar_caracter() < n2.consultar_caracter();
}

void Idioma::escribir_tabla_frec() {
    int n = tabla_frec.size();
	sort(tabla_frec.begin(), tabla_frec.end(), ordena);
    for (int i = 0; i < n; ++i) tabla_frec[i].escribir();
    cout << endl;
}
/*
void Idioma::asignar_codigos() {
	int n = tabla_frec.size();
	for (int i = 0; i < n; ++i) {
		Nodo n = tabla_frec[i];
		string c = n.consultar_caracter();
		string codigo;
		treecode.codifica_camino(n, codigo);
		d.insert(make_pair(c, codigo));
	}
}
*/
void Idioma::consultar_codigos() {
    map<string, string>::const_iterator it = d.begin();
    while (it != d.end()) {
        cout << it->first << " " << it->second << endl;
        ++it;
    }
    cout << endl;
}

void Idioma::consultar_codigo_especifico(string c) {
    map<string, string>::const_iterator it = d.find(c);
    if (it == d.end()) cout << "El idioma no existe o el caracter no esta en el idioma" << endl;
    else cout << it->first << " " << it->second << endl;
    cout << endl;
}

void Idioma::consultar_treecode() {
    cout << "Treecode de " << nombre << ":" << endl;
	BinTree<Nodo> a;
	treecode.escribir_treecode(a);
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
    treecode.crear_treecode(tabla_frec);
}
