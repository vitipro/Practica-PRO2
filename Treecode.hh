/** @file Treecode.hh
    @brief Especificaci�n de la clase Treecode
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
    
	Se trata de un �rbol binario codificado de pares <string, int>.
*/

class Treecode {
	
private:

	/** @brief �rbol binario */
	BinTree<pair<string, int>> arbol;
	/** @brief Diccionario para consultar c�digos

		La llave representa el caracter a consultar, y el mapped value representa el c�digo
	*/
	map<string, string> diccionario;                   
	
	/** @brief Recorre en preorden un �rbol binario.
		\pre <em>cierto</em>
        \post Retorna el recorrido en preorden de T.
    */
	void preorden(const BinTree<pair<string, int>>& T) const;
	
	/** @brief Recorre en inorden un �rbol binario.
		\pre <em>cierto</em>
        \post Retorna el recorrido en inorden de T.
    */
	void inorden(const BinTree<pair<string, int>>& T) const;
	
	/** @brief Inserta un �rbol binario a una lista.
        \pre l est� ordenada crecientemente por frecuencia de su ra�z y en caso de empate, por orden lexicogr�fico del caracter de la ra�z.
        \post T queda insertado en su posici�n. 
    */
    void anadir_elemento(list<BinTree<pair<string, int>>>& l, BinTree<pair<string, int>>& T);    // PROBAR TAMBI�N CON SETS!!!!!
	
	/** @brief Codifica los caminos del �rbol a.
		\pre <em>cierto</em>
		\post El resultado es el �rbol a codificado.
	*/
	void codifica_arbol(const BinTree<pair<string, int>>& a, string c);
	
	/** @brief Funci�n de inmersi�n para decodificar un texto en un idioma.
        \pre 0 <= pos <= texto.length()
        \post El resultado es la decodificaci�n de texto si �ste se puede decodificar. De otra manera, se avisar� que no se puede y escribir� la �ltima posici�n decodificable. 
    */
	void dec_inmersion(const BinTree<pair<string, int>>& a, string& texto, string& txt_dec, bool& decodificable, int& pos, int& ult_pos);
    
public:

	// creadoras
	
	/** @brief Creadora por defecto de un treecode.
        \pre <em>cierto</em> 
        \post El resultado es un BinTree arbol y diccionario vac�os.  
    */
    Treecode();

	// modificadoras 
	
	// consultoras 
	
	/** @brief Consulta los c�digos del treecode de un idioma.
        \pre <em>cierto</em> 
        \post El resultado es el conjunto de c�digos de diccionario del par�metro impl�cito. 
    */
	void consultar_codigos() const;
	
	/** @brief Consulta el c�digo de un caracter del treecode de un idioma.
        \pre <em>cierto</em> 
        \post El resultado es el c�digo del caracter de una hoja, si existe. Si no, se avisar�. 
    */
	void consultar_codigo_especifico(string c) const;	

	// entrada/salida
	
	/** @brief Codifica un texto en un idioma.
        \pre En el canal de entrada est�ndard se encuentra un string texto a codificar.
        \post Se escribe en el canal de salida est�ndard la codificaci�n del texto en el idioma, si se puede.
    */
	void codifica(string texto);
	
	/** @brief Decodifica un texto en un idioma.
        \pre En el canal de entrada est�ndard se encuentra un string texto a decodificar.
        \post Se escribe en el canal de salida est�ndard el texto decodificado, si se puede.
    */
	void decodifica(string texto);

	/** @brief Operaci�n de construcci�n del treecode de un idioma.
        \pre tabla est� ordenada ascendentemente por frecuencias.
        \post arbol del par�metro impl�cito pasa a ser un �rbol binario codificado que contiene los nodos <string, int> correspondientes.
    */
    void crear_treecode(map<string, int>& tabla); 

	/** @brief Operaci�n de escritura del treecode de un idioma.
        \pre <em>cierto</em> 
        \post Se escriben en el canal de salida est�ndard los recorridos en pre e inordren de T.
    */
    void escribir_treecode() const;  
	
	~Treecode();
	
};
#endif	