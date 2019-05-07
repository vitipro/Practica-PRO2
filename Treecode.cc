#include "Treecode.hh"
#include "Nodo.hh"
#include "BinTree.hh"
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

Treecode::Treecode() {}

Treecode::~Treecode() {}
 
void Treecode::preorden(const BinTree<Nodo>& T) const {
	if (not T.empty()) {
		T.value().escribir();
		preorden(T.left());
		preorden(T.right());
	}
}

void Treecode::inorden(const BinTree<Nodo>& T) const {
	if (not T.empty()) {
		inorden(T.left());
		T.value().escribir();
		inorden(T.right());
	}
}

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
	while (not insertado) {
		if (it == l.end()) {
			l.insert(l.end(), T);
			insertado = true;
		}
		else if (T.value().consultar_frec() < (*it).value().consultar_frec()) {
			l.insert(it, T);
			insertado = true;
		}
		else if (T.value().consultar_frec() == (*it).value().consultar_frec()) {
            if (T.value() < (*it).value()) {
                l.insert(it, T);
                insertado = true;
            }
            else ++it;
        }
		else ++it;
	}
}

//void Treecode::actualizar_treecode() {const BinTree<Nodo>& a
	
//}

string Treecode::codifica_camino(const BinTree<Nodo>& a, string c) const {  // privada
	if (a.value().consultar_caracter() == c) return "";
	if (not a.left().empty() and a.left().value().consultar_caracter().find(c) != string::npos) 
		return "0" + codifica_camino(a.left(), c);
	return "1" + codifica_camino(a.right(), c);
}

string Treecode::codigo_nodo(const Nodo& n) {
	string c = n.consultar_caracter();
	string codigo = codifica_camino(arbol, c);
	return codigo;
}

void Treecode::crear_treecode(vector<Nodo>& tabla) {
	list<BinTree<Nodo>> subarboles;
	sort(tabla.begin(), tabla.end());
	for (int i = 0; i < tabla.size(); ++i) {
		BinTree<Nodo> aux(tabla[i]);
		subarboles.insert(subarboles.end(), aux);
	}
	while (subarboles.size() > 1) {
		list<BinTree<Nodo>>::iterator it = subarboles.begin();
		string suma_c1 = (*it).value().consultar_caracter();
		int suma_f1 = (*it).value().consultar_frec();
		BinTree<Nodo> left = *it;
		it = subarboles.erase(it);
        string suma_c2 = (*it).value().consultar_caracter();
        int suma_f2 = (*it).value().consultar_frec();
		string c;
		int f = suma_f1 + suma_f2;
		if (suma_c1 < suma_c2) c = suma_c1 + suma_c2;
		else c = suma_c2 + suma_c1;
        Nodo suma(c, f);
		BinTree<Nodo> right = *it;
		it = subarboles.erase(it);
		BinTree<Nodo> a(suma, left, right);
		anadir_elemento(subarboles, a);
	}
	arbol = subarboles.front();
}

void Treecode::escribir_treecode() const {
	cout << "recorrido en preorden:" << endl;
	preorden(arbol);
	cout << "recorrido en inorden:" << endl;
	inorden(arbol);
}
