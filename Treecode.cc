#include "Treecode.hh"

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

int Treecode::altura_treecode(const BinTree<Nodo>& a) {
	if (a.empty()) return 0;
	else return 1 + max(altura_treecode(a.left()), altura_treecode(a.right()));
}

void Treecode::invertir_diccionario() {
	map<string, string> aux;
	map<string, string>::iterator it = diccionario.begin();
    while (it != diccionario.end()) {
        aux.insert(make_pair(it->second, it->first));
        ++it;
    }
	diccionario = aux;
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

void Treecode::codifica_arbol(const BinTree<Nodo>& a, string c) {  
	if (not a.left().empty()) codifica_arbol(a.left(), c + "0"); 
	if (not a.right().empty()) codifica_arbol(a.right(), c + "1"); 
	if (a.left().empty() and a.right().empty()) {
		string k = a.value().consultar_caracter();
		diccionario[k] = c;
	}
}

void Treecode::consultar_codigos() const {
	map<string, string>::const_iterator it = diccionario.begin();
    while (it != diccionario.end()) {
        cout << it->first << " " << it->second << endl;
        ++it;
    }
    cout << endl;
}

void Treecode::consultar_codigo_especifico(string c) const {
	map<string, string>::const_iterator it = diccionario.find(c);
    if (it == diccionario.end()) cout << "El idioma no existe o el caracter no esta en el idioma" << endl;
    else cout << it->first << " " << it->second << endl;
	cout << endl;
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
	string c;
	codifica_arbol(arbol, c);
}

void Treecode::escribir_treecode() const {
	cout << "recorrido en preorden:" << endl;
	preorden(arbol);
	cout << "recorrido en inorden:" << endl;
	inorden(arbol);
	cout << endl;
}

void Treecode::codifica(string texto) {
	bool codificable = true;
	string codif;
	int i = 0;
	while (i < texto.size() and codificable == true) {
		string busq = (texto[i] < 0) ? texto.substr(i, 2) : string(1, texto[i]);
		map<string, string>::const_iterator it = diccionario.find(busq);
		if (it == diccionario.end()) {
            cout << "El texto no pertenece al idioma; primer caracter que falla: " << busq << endl << endl; 
			codificable = false;
        }  
		else codif += it->second;
		i += (texto[i] < 0) ? 2 : 1;
    }
	if (codificable) cout << codif << endl << endl;
}

void Treecode::decodifica(string texto) {
	invertir_diccionario();
	bool decodificable = true;
	string txt_dec;
	int pos = 0, len = 1;
	while (pos != texto.size() and decodificable == true) {
		map<string, string>::iterator it = diccionario.find(texto.substr(pos, len));
		if (it != diccionario.end()) {
			txt_dec += diccionario.at(texto.substr(pos, len));
			pos += len;
			len = 1;
		}
		else if (len > altura_treecode(arbol)) decodificable = false;
		else ++len;
	}
	if (decodificable) cout << txt_dec << endl << endl;
	else cout << "El texto no procede de una codificacion del idioma; ultima posicion del codigo correspondiente al ultimo caracter que se podria decodificar: " << pos << endl << endl;
	invertir_diccionario();
}