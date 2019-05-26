/** @file Treecode.cc
    @brief Código de la clase Treecode 
*/

#include "Treecode.hh"

Treecode::Treecode() {}

Treecode::~Treecode() {}
 
void Treecode::preorden(const BinTree<pair<string, int>>& T)  
{
	if (not T.empty()) {
		cout << T.value().first << " " << T.value().second << endl;
		preorden(T.left());
		preorden(T.right());
	}
}

void Treecode::inorden(const BinTree<pair<string, int>>& T) 
{
	if (not T.empty()) {
		inorden(T.left());
		cout << T.value().first << " " << T.value().second << endl;
		inorden(T.right());
	}
}

void Treecode::anadir_elemento(list<BinTree<pair<string, int>>>& L, BinTree<pair<string, int>>& T) 
{  
	bool insertado = false;
	list<BinTree<pair<string, int>>>::iterator it = L.begin();
	
	// Inv: it es un iterador que va recorriendo la lista L, buscando la posicion donde debe ser insertado T
	// L.begin() <= it <= L.end()
	// se puede asegurar que el bucle acaba ya que T siempre es insertable en L, poniendo insertado a true
	// en el peor de los casos T sera insertado al final de la lista
	
	while (not insertado) {
		if (it == L.end()) {
			L.insert(L.end(), T);
			insertado = true;
		}
		else if (T.value().second < (*it).value().second) {
			L.insert(it, T);
			insertado = true;
		}
		else if (T.value().second == (*it).value().second) {
            if (T.value() < (*it).value()) {
                L.insert(it, T);
                insertado = true;
            }
            else ++it;
        }
		else ++it;
	}
	
	// Post: T queda insertado en L, y L sigue ordenada por frecuencias, y si hay empate, por caracter
}

void Treecode::codifica_arbol(const BinTree<pair<string, int>>& T, string c) 
{  
	if (not T.left().empty()) codifica_arbol(T.left(), c + "0"); 
	if (not T.right().empty()) codifica_arbol(T.right(), c + "1");
	if (T.left().empty() and T.right().empty()) diccionario[T.value().first] = c;             // si se encuentra una hoja se guarda el codigo correspondiente en su clave
}

void Treecode::consultar_codigos() const 
{
	map<string, string>::const_iterator it = diccionario.begin();
    while (it != diccionario.end()) {
        cout << it->first << " " << it->second << endl;
        ++it;
    }
    cout << endl;
}

void Treecode::consultar_codigo_especifico(string c) const 
{
	map<string, string>::const_iterator it = diccionario.find(c);
    if (it == diccionario.end()) cout << "El idioma no existe o el caracter no esta en el idioma" << endl;
    else cout << it->first << " " << it->second << endl;
	cout << endl;
}

void Treecode::crear_treecode(map<string, int>& tabla) 
{
	list<BinTree<pair<string, int>>> subarboles;
	map<string, int>::const_iterator it = tabla.begin();
	while (it != tabla.end()) {
		BinTree<pair<string, int>> aux(*it);                                   
		anadir_elemento(subarboles, aux);                                               	  // se crea una lista de arboles con nodos los elementos de la tabla de frecuencias
		++it;
	}
	string suma_c;
	int suma_f;
	list<BinTree<pair<string, int>>>::iterator it2;
	BinTree<pair<string, int>> izq;
	BinTree<pair<string, int>> der;
	string codigo;                                                                           
	
	// Inv: subarboles.size() va disminuyendo en 1 en cada iteracion
	// suma_c y suma_f son sumas de los nodos de los dos primeros arboles de la lista en cada iteracion
	// sea n = subarboles.size() inicial, 1 <= subarboles.size() <= n 
	
	// se puede asegurar que el bucle termina porque en cada iteracion se borran 2 elementos para crear uno nuevo
	// por tanto, si hay n elementos inicialmente, en n - 1 iteraciones solo quedara un elemento en la lista
	
	while (subarboles.size() > 1) {
		it2 = subarboles.begin();
		suma_c = (*it2).value().first;                                                        // se almacenan los datos del subarbol de la primera posicion
		suma_f = (*it2).value().second;
		izq = *it2;                                                                           // se coge el primer elemento de la lista y lo guarda 
		it2 = subarboles.erase(it2);                                                     	  // borra elemento
		if (suma_c < (*it2).value().first) suma_c += (*it2).value().first;               	  // se suman los nodos del elemento borrado y el siguiente para crear el nodo del nuevo arbol
		else suma_c = (*it2).value().first + suma_c;                                     	  // respetando lexicograficamente
		suma_f += (*it2).value().second;
		der = *it2;                                                                           // se coge el siguiente elemento y lo guarda
		it2 = subarboles.erase(it2);                                                          // lo borra tambien
		BinTree<pair<string, int>> suma(make_pair(suma_c, suma_f), izq, der);                 // crea el nuevo arbol suma a partir de los dos arboles anteriores
		anadir_elemento(subarboles, suma);                                                    // y se vueve a insertar en la lista
	}
	
	// Post: en la lista subarboles solo queda un unico elemento, el treecode ya construido
	
	arbol = subarboles.front();                                                               
	codifica_arbol(arbol, codigo);                                                            
}

void Treecode::escribir_treecode() const 
{
	cout << "recorrido en preorden:" << endl;
	preorden(arbol);
	cout << "recorrido en inorden:" << endl;
	inorden(arbol);
	cout << endl;
}

void Treecode::codifica(string texto) 
{
	bool codificable = true;
	string codif, busq;
	int pos = 0;
	map<string, string>::const_iterator it;
	
	// Inv: codif es el string codificado de la parte tratada de texto, y pos (posicion en texto) va augmentando dependiendo del substring busq de texto tratado
	// 0 <= pos < texto.size()
	// se puede asegurar que el bucle termina ya que la distancia entre pos y texto.size() - 1 va disminuyendo a cada iteracion
	// ademas, en caso de no ser codificable se sale del bucle automaticamente debido a la segunda condicion
	
	while (pos < texto.size() and codificable) {
		
		// se comprueba si el substring busq ocupa 1 o 2 posiciones, es decir, si es especial o no
		// si es "negativo" quiere decir que para representarlo se necesitan 2 bytes, 2 posiciones		
		
		busq = (texto[pos] < 0) ? texto.substr(pos, 2) : string(1, texto[pos]);      																			 
		it = diccionario.find(busq);
		if (it == diccionario.end()) {
            cout << "El texto no pertenece al idioma; primer caracter que falla: " << busq << endl << endl; 
			codificable = false;
        }  
		else codif += it->second;
		
		// de nuevo hacemos la comprobacion para ver si tenemos que augmentar pos en 1 o 2
		
		pos += (texto[pos] < 0) ? 2 : 1;                
    }
	
	// Post: si codificable = true, codif = codificacion de texto en el idioma
	
	if (codificable) cout << codif << endl << endl;
}

void Treecode::dec_inmersion(const BinTree<pair<string, int>>& T, string& texto, string& txt_dec, bool& decodificable, int& pos, int& ult_pos) 
{
	string busq;
	busq = texto[pos];
	if (pos == texto.length() and T.value() != arbol.value() and not T.left().empty() and not T.right().empty()) decodificable = false;
	else {
		if (not T.left().empty() and not T.right().empty()){
			++pos;
			if (busq == "0" and decodificable) dec_inmersion(T.left(), texto, txt_dec, decodificable, pos, ult_pos);
			if (busq == "1" and decodificable) dec_inmersion(T.right(), texto, txt_dec, decodificable, pos, ult_pos);
		}
		else {
			txt_dec += T.value().first;
			ult_pos = pos;
			dec_inmersion(arbol, texto, txt_dec, decodificable, pos, ult_pos);
		}
	}
}

void Treecode::decodifica(string texto) 
{
	int pos, ult_pos;
	pos = ult_pos = 0;
	bool decodificable = true;
	string txt_dec;
	dec_inmersion(arbol, texto, txt_dec, decodificable, pos, ult_pos);
	if (decodificable) cout << txt_dec << endl << endl;
	else cout << "El texto no procede de una codificacion del idioma; ultima posicion del codigo correspondiente al ultimo caracter que se podria decodificar: " << ult_pos << endl << endl;
}