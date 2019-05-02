/** @file Treecode.hh
    @brief Especificación de la clase Treecode
*/

#ifndef _TREECODE_HH_
#define _TREECODE_HH_

#include "Nodo.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;
#endif

/** @class Treecode
    @brief Representa un treecode de un idioma 
    
	Se trata de un árbol binario con nodos de tipo Nodo
*/

class Treecode {
	
private:

	BinTree<Nodo> arbol;
	
	/** @brief Suma dos nodos 
		\pre <em>cierto</em>
        \post el resultado es un Nodo con caracter = concatenación (en orden lexicográfico) de caracteres de n1 y n2 y frec = frec n1 + frec n2
    */
	Nodo suma_nodos(const Nodo& n1, const Nodo& n2);
	
	/** @brief Recorre en preorden un árbol 
		\pre <em>cierto</em>
        \post retorna una lista con el recorrido en preorden de T
    */
	list<Nodo> preorden(const BinTree<Nodo>& T);
	
	/** @brief Recorre en inorden un árbol 
		\pre <em>cierto</em>
        \post retorna el recorrido en inorden de T
    */
	void inorden(const BinTree<Nodo>& T);
    
	/** @brief Inserta un Nodo a una lista
        \pre l está ordenada crecientemente
        \post n queda insertado en su posición 
    */
    void anadir_elemento(list<BinTree<Nodo>>& l, BinTree<Nodo>& T);
    
public:

	// creadoras
	
	/** @brief Creadora por defecto de un treecode
        \pre <em>cierto</em> 
        \post el resultado es un BinTree vacío  
    */
    Treecode();

	// modificadoras

//	/** @brief Actualiza el treecode de un idioma
//        \pre T es un treecode no vacío 
//        \post el treecode T queda actualizado  
//    */
//    void actualizar_treecode();  
	
	// consultoras
	
	/** @brief Consulta el código un Nodo
		\pre <em>cierto</em> 
		\post el resultado es el código del Nodo n
	*/
	string codifica_camino(const Nodo& n, string& c); 
	
	// entrada/salida

	/** @brief Operación de construcción del treecode de un idioma
        \pre tabla contiene Nodos en orden ascendente
        \post arbol del parámetro implícito pasa a ser un árbol que contiene los Nodos correspondientes
    */
    void crear_treecode(vector<Nodo> tabla); 

	/** @brief Operación de escritura del treecode de un idioma
        \pre <em>cierto</em> 
        \post se escribe en el canal de salida estándard los recorridos en pre e inordren de T
    */
    void escribir_treecode();  
	
	~Treecode();
	
};
#endif		
