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
    
    // operadores y mierdas son funciones privadas
    
public:

	// creadoras
	
	/** @brief Creadora por defecto de un treecode
        \pre <em>cierto</em> 
        \post el resultado es un set vacío  
    */
    Treecode();

	// modificadoras

//	/** @brief Actualiza el treecode de un idioma
//        \pre T es un treecode no vacío 
//        \post el treecode T queda actualizado  
//    */
//    void actualizar_treecode();  

	/** @brief Inserta un Nodo a una lista
        \pre l está ordenada crecientemente
        \post n queda insertado en su posición 
    */
    void anadir_elemento(list<BinTree<Nodo>>& l, BinTree<Nodo>& T);
	
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
    void escribir_treecode(const BinTree<Nodo>& a);  
	
	~Treecode();
	
};
#endif	
