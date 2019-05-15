#include "Treecode.hh"

Treecode::Treecode() {}

Treecode::~Treecode() {}
 
void Treecode::preorden(const BinTree<pair<string, int>>& T) const {
	if (not T.empty()) {
		cout << T.value().first << " " << T.value().second << endl;
		preorden(T.left());
		preorden(T.right());
	}
}

void Treecode::inorden(const BinTree<pair<string, int>>& T) const {
	if (not T.empty()) {
		inorden(T.left());
		cout << T.value().first << " " << T.value().second << endl;
		inorden(T.right());
	}
}

int Treecode::altura_treecode(const BinTree<pair<string, int>>& a) {
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

void Treecode::anadir_elemento(list<BinTree<pair<string, int>>>& l, BinTree<pair<string, int>>& T) {  
	bool insertado = false;
	list<BinTree<pair<string, int>>>::iterator it = l.begin();
	while (not insertado) {
		if (it == l.end()) {
			l.insert(l.end(), T);
			insertado = true;
		}
		else if (T.value().second < (*it).value().second) {
			l.insert(it, T);
			insertado = true;
		}
		else if (T.value().second == (*it).value().second) {
            if (T.value() < (*it).value()) {
                l.insert(it, T);
                insertado = true;
            }
            else ++it;
        }
		else ++it;
	}
}

void Treecode::codifica_arbol(const BinTree<pair<string, int>>& a, string c) {  
	if (not a.left().empty()) codifica_arbol(a.left(), c + "0"); 
	if (not a.right().empty()) codifica_arbol(a.right(), c + "1"); 
	if (a.left().empty() and a.right().empty()) {
		diccionario[a.value().first] = c;
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

void Treecode::crear_treecode(map<string, int>& tabla) {
	list<BinTree<pair<string, int>>> subarboles;
	map<string, int>::const_iterator it = tabla.begin();
	while (it != tabla.end()) {
		BinTree<pair<string, int>> aux(*it);                                   
		anadir_elemento(subarboles, aux);                                               // creamos una lista de árboles con nodo elementos de la tabla de frecuencias
		++it;
	}
	while (subarboles.size() > 1) {
		string suma_c;
		int suma_f;
		list<BinTree<pair<string, int>>>::iterator it = subarboles.begin();
		suma_c = (*it).value().first;
		suma_f = (*it).value().second;
		BinTree<pair<string, int>> left = *it;                                          // cogemos el primer elemento de la lista y o guardamos
		it = subarboles.erase(it);                                                      // borramos elemento
		if (suma_c < (*it).value().first) suma_c += (*it).value().first;                // sumamos los nodos del elemento borrado y el siguiente para crear el nodo del nuevo árbol
		else suma_c = (*it).value().first + suma_c;                                     // respetando lexicográficamente
		suma_f += (*it).value().second;
		BinTree<pair<string, int>> right = *it;                                         // cogemos el siguiente elemento y lo guardamos
		it = subarboles.erase(it);                                                      // lo borramos también
		BinTree<pair<string, int>> a(make_pair(suma_c, suma_f), left, right);           // creamos el nuevo árbol suma 
		anadir_elemento(subarboles, a);                                                 // y lo volvemos a insertar en la lista
	}
	arbol = subarboles.front();
	string codigo;
	codifica_arbol(arbol, codigo);
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