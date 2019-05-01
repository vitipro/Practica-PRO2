#include "Treecode.hh"
#include "Nodo.hh"
#include "BinTree.hh"
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

Treecode::Treecode() {}

Treecode::~Treecode() {}

bool operator<(const Nodo& n1, const Nodo& n2) {
	if (n1.consultar_frec() == n2.consultar_frec()) return (n1.consultar_caracter()) < (n2.consultar_caracter());
	else return (n1.consultar_frec()) < (n2.consultar_frec());
}

bool operator==(const Nodo& n1, const Nodo& n2) {
	if ((n1.consultar_caracter() == n2.consultar_caracter()) and (n1.consultar_frec() == n2.consultar_frec())) return true;
	else return false;
}

void Treecode::anadir_elemento(list<BinTree<Nodo>>& l, BinTree<Nodo>& T) {
	bool insertado = false;
	list<BinTree<Nodo>>::iterator it = l.begin();
	while (it != l.end() or not insertado) {
		if (it == l.end()) {
			l.insert(l.end(), T);
			insertado = true;
		}
		else if (T.value().consultar_frec() <= (*it).value().consultar_frec()) {
			l.insert(it, T);
			insertado = true;
		}
		else ++it;
	}
}

//void Treecode::actualizar_treecode() {
	
//}
/*
string Treecode::codifica_camino(const Nodo& n, string& c) {
	if (arbol.value() == n) return c;
	else return codifica_camino(arbol.left(), n, c + "0") or codifica_camino(arbol.right(), n, c + "1");
}
*/
void Treecode::crear_treecode(vector<Nodo> tabla) {
	int n = tabla.size();
	sort(tabla.begin(), tabla.end());
	list<Nodo> hojas;
	for (int i = 0; i < n; ++i) hojas.insert(hojas.end(), tabla[i]);
	list<BinTree<Nodo>> subarboles;
	while (not hojas.empty()) {
		BinTree<Nodo> aux(hojas.front());
		hojas.pop_front();
		subarboles.insert(subarboles.end(), aux);
	}
	while (subarboles.size() > 1) {
		cout << "Bucle inicio" << endl;
		list<BinTree<Nodo>>::iterator it = subarboles.begin();
		string suma_c = (*it).value().consultar_caracter();
		int suma_f = (*it).value().consultar_frec();
		BinTree<Nodo> left = *it;
		it = subarboles.erase(it);
		suma_c += (*it).value().consultar_caracter();
		suma_f += (*it).value().consultar_frec();
		sort(suma_c.begin(), suma_c.end());
		Nodo suma(suma_c, suma_f);
		suma.escribir();
		BinTree<Nodo> right = *it;
		it = subarboles.erase(it);
		cout << "Harbol hacido" << endl;
		BinTree<Nodo> a(suma, left, right);
		cout << "Insercionamos" << endl;
		anadir_elemento(subarboles, a);
		arbol = a;
		cout << "Bucle final" << endl;
	}
	subarboles.clear();
}

void Treecode::escribir_treecode(const BinTree<Nodo>& a) {
	arbol = a;
	cout << "recorrido en preorden:" << endl;
	cout << "recorrido en inorden:" << endl;
	if (not arbol.empty()) {
		Treecode::escribir_treecode(arbol.right());
		arbol.value().escribir();
		Treecode::escribir_treecode(arbol.left());
	}
}
