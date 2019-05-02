#include "Treecode.hh"
#include "Nodo.hh"
#include "BinTree.hh"
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

Treecode::Treecode() {}

Treecode::~Treecode() {}

Nodo Treecode::suma_nodos(const Nodo& n1, const Nodo& n2) { //privada
    string c;
    if (n1.consultar_caracter() < n2.consultar_caracter()) c = n1.consultar_caracter() + n2.consultar_caracter();
    else c = n2.consultar_caracter() + n1.consultar_caracter();
    int f = n1.consultar_frec() + n2.consultar_frec();
    Nodo suma(c, f);
    return suma;
}
 
list<Nodo> Treecode::preorden(const BinTree<Nodo>& T) {
	list<Nodo> L;
	if (not T.empty()) {
		L.insert(L.begin(), T.value());
		L.splice(L.end(), preorden(T.left()));
		L.splice(L.end(), preorden(T.right()));
	}
	return L;
}

void Treecode::inorden(const BinTree<Nodo>& T) {
	if (not T.empty()) {
		inorden(T.left());
		T.value().escribir();
		inorden(T.right());
	}
}

bool operator<(const Nodo& n1, const Nodo& n2) {  //privada
	if (n1.consultar_frec() == n2.consultar_frec()) return (n1.consultar_caracter()) < (n2.consultar_caracter());
	else return (n1.consultar_frec()) < (n2.consultar_frec());
}

bool operator==(const Nodo& n1, const Nodo& n2) {  //privada
	if ((n1.consultar_caracter() == n2.consultar_caracter()) and (n1.consultar_frec() == n2.consultar_frec())) return true;
	else return false;
}

void Treecode::anadir_elemento(list<BinTree<Nodo>>& l, BinTree<Nodo>& T) {  // privada
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
		list<BinTree<Nodo>>::iterator it = subarboles.begin();
		string suma_c1 = (*it).value().consultar_caracter();
		int suma_f1 = (*it).value().consultar_frec();
		BinTree<Nodo> left = *it;
		it = subarboles.erase(it);
        string suma_c2 = (*it).value().consultar_caracter();
        int suma_f2 = (*it).value().consultar_frec();
        Nodo n1(suma_c1, suma_f1);  
        Nodo n2(suma_c2, suma_f2); 
        Nodo suma = suma_nodos(n1, n2);
		BinTree<Nodo> right = *it;
		it = subarboles.erase(it);
		BinTree<Nodo> a(suma, left, right);
		anadir_elemento(subarboles, a);
		arbol = a; 
	}
}

void Treecode::escribir_treecode() {
	cout << "recorrido en preorden:" << endl;
	list<Nodo> L = preorden(arbol);
	for (list<Nodo>::const_iterator it = L.begin(); it != L.end(); ++it) (*it).escribir();
	cout << "recorrido en inorden:" << endl;
	inorden(arbol);
}
