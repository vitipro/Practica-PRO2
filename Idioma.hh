/** @file Idioma.hh
    @brief Especificaci�n de la clase Idioma
*/

#ifndef _IDIOMA_HH_
#define _IDIOMA_HH_

#include "Nodo.hh"           
#include "Treecode.hh"

#ifndef NO_DIAGRAM
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#endif

/** @class Idioma
    @brief Representa un idioma 
    
    Cada idioma contiene unos c�digos para cada uno de sus caracteres, usando una tabla de frecuencias. Con estos c�digos se quiere codificar y decodificar textos escritos
*/

class Idioma {

private:

    string nombre;                              // identificador
    vector<Nodo> tabla_frec;                    // tabla de frecuencias
    Treecode treecode;                          // treecode del idioma
  
public:

    // constructoras
  
    /** @brief Creadora por defecto de un idioma
     
        Cuando se declara se ejecuta autom�ticamente
        \pre <em>cierto</em> 
        \post el resultado es un Idioma sin nombre ni tabla_frec
    */
    Idioma();             
  
 //   /** @brief Creadora de un idioma con nombre
 //       \pre <em>cierto</em> 
 //       \post el resultado es un idioma con nombre = id 
 //   */
 //   Idioma(string id); 

    // modificadoras
    
    /** @brief Modifica la tabla de frecuencias de un idioma
        \pre <em>cierto</em> 
        \post se a�aden a tabla_frec del par�metro impl�cito las frecuencias de la nueva tabla
    */
    void modificar_tabla(vector<Nodo> tabla);
	
    // consultoras
	
	/** @brief Consulta el nombre de un idioma
        \pre <em>cierto</em> 
        \post el resultado es el nombre del par�metro impl�cito
    */
    string consultar_nombre() const;
  
	/** @brief Consulta la tabla de frecuencias de un idioma
        \pre <em>cierto</em> 
        \post el resultado es tabla_frec del par�metro impl�cito
    */
    vector<Nodo> consultar_tabla() const;
  
    /** @brief Consulta los c�digos de un idioma
        \pre <em>cierto</em> 
        \post el resultado es el conjunto de c�digos del par�metro impl�cito
    */
    void consultar_codigos() const;
  
    /** @brief Consulta el c�digo de un caracter de un idioma
        \pre el caracter c puede no estar en el diccionario d del par�metro impl�cito 
        \post el resultado es el c�digo del caracter concreto si este existe, si no, se avisar� 
    */
    void consultar_codigo_especifico(string c) const;
	
	/** @brief Consulta el treecode de un idioma
        \pre <em>cierto</em> 
        \post el resultado es el treecode del par�metro impl�cito
    */
	void consultar_treecode() const;
  
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
	
	/** @brief Operaci�n de escritura de tabla_frec
        \pre <em>cierto</em>
        \post se escribe en el canal de salida est�ndard tabla_frec
    */
	void escribir_tabla_frec();
    
    /** @brief Operaci�n de lectura de un idioma
        \pre en la entrada se encuentra un string y una seguido de Nodos (vector)
        \post el par�metro impl�cito pasa a tener nombre y tabla_frec 
    */
    void leer_idioma();
  
    ~Idioma();
    
};
#endif
