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
	
	/** @brief Recorre en preorden un árbol binario
		\pre <em>cierto</em>
        \post retorna el recorrido en preorden de T
    */
	void preorden(const BinTree<Nodo>& T) const;
	
	/** @brief Recorre en inorden un árbol binario
		\pre <em>cierto</em>
        \post retorna el recorrido en inorden de T
    */
	void inorden(const BinTree<Nodo>& T) const;
    
	/** @brief Inserta un árbol binario a una lista
        \pre l está ordenada crecientemente por frecuencia de su raíz y en caso de empate, por orden lexicográfico del caracter de la raíz
        \post T queda insertado en su posición 
    */
    void anadir_elemento(list<BinTree<Nodo>>& l, BinTree<Nodo>& T);
	
	/** @brief Codifica el camino hasta un Nodo
		\pre c = caracter de un Nodo existente en el árbol del parámetro implícito 
		\post el resultado es el camino del Nodo con caracter = c
	*/
	string codifica_camino(const BinTree<Nodo>& a, string c) const;
    
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
	
	/** @brief Consulta el código de un Nodo
		\pre n es un Nodo existente en el árbol del parámetro implícito 
		\post el resultado es el código de Nodo 
	*/
	string codigo_nodo(const Nodo& n); 
	
	// entrada/salida

	/** @brief Operación de construcción del treecode de un idioma
        \pre tabla contiene Nodos en orden ascendente
        \post arbol del parámetro implícito pasa a ser un árbol que contiene los Nodos correspondientes
    */
    void crear_treecode(vector<Nodo>& tabla); 

	/** @brief Operación de escritura del treecode de un idioma
        \pre <em>cierto</em> 
        \post se escribe en el canal de salida estándard los recorridos en pre e inordren de T
    */
    void escribir_treecode() const;  
	
	~Treecode();
	
};
#endif		
