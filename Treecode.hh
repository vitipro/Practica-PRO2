/** @file Treecode.hh
    @brief Especificaci�n de la clase Treecode
*/

#ifndef _TREECODE_HH_
#define _TREECODE_HH_

#include "Nodo.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <vector>
#include <list>
#include <algorithm>
#include <map>
#include <string>
#endif

/** @class Treecode
    @brief Representa un treecode de un idioma 
    
	Se trata de un �rbol binario con nodos de tipo Nodo
*/

class Treecode {
	
private:

	BinTree<Nodo> arbol;
	map<string, string> diccionario;                   // diccionario para consultar c�digos, key: caracter a consultar, mapped value: c�digo
	
	/** @brief Recorre en preorden un �rbol binario
		\pre <em>cierto</em>
        \post retorna el recorrido en preorden de T
    */
	void preorden(const BinTree<Nodo>& T) const;
	
	/** @brief Recorre en inorden un �rbol binario
		\pre <em>cierto</em>
        \post retorna el recorrido en inorden de T
    */
	void inorden(const BinTree<Nodo>& T) const;
    
	/** @brief Inserta un �rbol binario a una lista
        \pre l est� ordenada crecientemente por frecuencia de su ra�z y en caso de empate, por orden lexicogr�fico del caracter de la ra�z
        \post T queda insertado en su posici�n 
    */
    void anadir_elemento(list<BinTree<Nodo>>& l, BinTree<Nodo>& T);
	
	/** @brief Codifica los caminos de a
		\pre <em>cierto</em>
		\post el resultado es el �rbol a codificado
	*/
	void codifica_arbol(const BinTree<Nodo>& a, string c);
	
	/** @brief Consulta si un texto es decodificable en un idioma
		\pre <em>cierto</em>
		\post el resultado es true si el string texto es decodificable usando el diccionario del par�metro impl�cito
	*/
	bool decodificable(string texto, int i, int j, int& cont);
	
	/** @brief Invierte un diccionario
		\pre <em>cierto</em>
		\post el resultado es el diccionario del par�metro impl�cito invertido, es decir, los datos de la key pasan a ser los mapped values y viceversa
	*/
	void invertir_diccionario();
	
	/** @brief Consulta la altura de un �rbol 
		\pre <em>cierto</em>
		\post el resultado es la altura de a
	*/
	int altura_treecode(const BinTree<Nodo>& a);
    
public:

	// creadoras
	
	/** @brief Creadora por defecto de un treecode
        \pre <em>cierto</em> 
        \post el resultado es un BinTree vac�o  
    */
    Treecode();

	// modificadoras 
	
	// consultoras 
	
	/** @brief Consulta los c�digos del treecode de un idioma
        \pre <em>cierto</em> 
        \post el resultado es el conjunto de c�digos del par�metro impl�cito 
    */
	void consultar_codigos() const;
	
	/** @brief Consulta el c�digo de un caracter del treecode de un idioma
        \pre <em>cierto</em> 
        \post el resultado es el c�digo del caracter de una hoja, si existe 
    */
	void consultar_codigo_especifico(string c) const;	

	// entrada/salida
	
	/** @brief Codifica un texto en un idioma
        \pre en la entrada se encuentra un string texto a codificar
        \post se escribe en el canal de salida la codificaci�n del texto en el idioma si se puede
    */
	void codifica(string texto);
	
	/** @brief Decodifica un texto en un idioma
        \pre en la entrada se encuentra un string texto a decodificar
        \post se escribe en el canal de salida el texto decodificado si se puede
    */
	void decodifica(string texto);

	/** @brief Operaci�n de construcci�n del treecode de un idioma
        \pre tabla contiene Nodos en orden ascendente
        \post arbol del par�metro impl�cito pasa a ser un �rbol que contiene los Nodos correspondientes
    */
    void crear_treecode(vector<Nodo>& tabla); 

	/** @brief Operaci�n de escritura del treecode de un idioma
        \pre <em>cierto</em> 
        \post se escribe en el canal de salida est�ndard los recorridos en pre e inordren de T
    */
    void escribir_treecode() const;  
	
	~Treecode();
	
};
#endif	