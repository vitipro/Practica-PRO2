/** @file Treecode.hh
    @brief Especificación de la clase Treecode
*/

#ifndef _TREECODE_HH_
#define _TREECODE_HH_

#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#include "BinTree.hh"
#include <list>
#include <map>
#include <string>
#endif

/** @class Treecode
    @brief Representa un treecode de un idioma.
    
	Se trata de un árbol binario codificado de pares <string, int>.
*/

class Treecode {
	
private:

	/** @brief Árbol binario */
	BinTree<pair<string, int>> arbol;
	/** @brief Diccionario para consultar códigos

		La llave representa el caracter a consultar, y el mapped value representa el código
	*/
	map<string, string> diccionario;                   
	
	/** @brief Recorre en preorden un árbol binario.
		\pre <em>cierto</em>
        \post Retorna el recorrido en preorden de T.
    */
	void preorden(const BinTree<pair<string, int>>& T) const;
	
	/** @brief Recorre en inorden un árbol binario.
		\pre <em>cierto</em>
        \post Retorna el recorrido en inorden de T.
    */
	void inorden(const BinTree<pair<string, int>>& T) const;
	
	/** @brief Inserta un árbol binario a una lista.
        \pre l está ordenada crecientemente por frecuencia de su raíz y en caso de empate, por orden lexicográfico del caracter de la raíz.
        \post T queda insertado en su posición. 
    */
    void anadir_elemento(list<BinTree<pair<string, int>>>& l, BinTree<pair<string, int>>& T);    // PROBAR TAMBIÉN CON SETS!!!!!
	
	/** @brief Codifica los caminos del árbol a.
		\pre <em>cierto</em>
		\post El resultado es el árbol a codificado.
	*/
	void codifica_arbol(const BinTree<pair<string, int>>& a, string c);
	
	/** @brief Función de inmersión para decodificar un texto en un idioma.
        \pre 0 <= pos <= texto.length()
        \post El resultado es la decodificación de texto si éste se puede decodificar. De otra manera, se avisará que no se puede y escribirá la última posición decodificable. 
    */
	void dec_inmersion(const BinTree<pair<string, int>>& a, string& texto, string& txt_dec, bool& decodificable, int& pos, int& ult_pos);
    
public:

	// creadoras
	
	/** @brief Creadora por defecto de un treecode.
        \pre <em>cierto</em> 
        \post El resultado es un BinTree arbol y diccionario vacíos.  
    */
    Treecode();

	// modificadoras 
	
	// consultoras 
	
	/** @brief Consulta los códigos del treecode de un idioma.
        \pre <em>cierto</em> 
        \post El resultado es el conjunto de códigos de diccionario del parámetro implícito. 
    */
	void consultar_codigos() const;
	
	/** @brief Consulta el código de un caracter del treecode de un idioma.
        \pre <em>cierto</em> 
        \post El resultado es el código del caracter de una hoja, si existe. Si no, se avisará. 
    */
	void consultar_codigo_especifico(string c) const;	

	// entrada/salida
	
	/** @brief Codifica un texto en un idioma.
        \pre En el canal de entrada estándard se encuentra un string texto a codificar.
        \post Se escribe en el canal de salida estándard la codificación del texto en el idioma, si se puede.
    */
	void codifica(string texto);
	
	/** @brief Decodifica un texto en un idioma.
        \pre En el canal de entrada estándard se encuentra un string texto a decodificar.
        \post Se escribe en el canal de salida estándard el texto decodificado, si se puede.
    */
	void decodifica(string texto);

	/** @brief Operación de construcción del treecode de un idioma.
        \pre tabla está ordenada ascendentemente por frecuencias.
        \post arbol del parámetro implícito pasa a ser un árbol binario codificado que contiene los nodos <string, int> correspondientes.
    */
    void crear_treecode(map<string, int>& tabla); 

	/** @brief Operación de escritura del treecode de un idioma.
        \pre <em>cierto</em> 
        \post Se escriben en el canal de salida estándard los recorridos en pre e inordren de T.
    */
    void escribir_treecode() const;  
	
	~Treecode();
	
};
#endif	