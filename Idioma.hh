/** @file Idioma.hh
    @brief Especificación de la clase Idioma
*/

#ifndef _IDIOMA_HH_
#define _IDIOMA_HH_

#include "Nodo.hh"           
#include "Treecode.hh"

#ifndef NO_DIAGRAM
#include <vector>
#include <map>
#include <algorithm>
#endif

/** @class Idioma
    @brief Representa un idioma 
    
    Cada idioma contiene unos códigos para cada uno de sus caracteres, usando una tabla de frecuencias. Con estos códigos se quiere codificar y decodificar textos escritos
*/

class Idioma {

private:

    string nombre;                              // identificador
    vector<Nodo> tabla_frec;                    // tabla de frecuencias
    Treecode treecode;                          // treecode del idioma
    map<string, string> d;                      // diccionario para consultar códigos, key: caracter a consultar, mapped value: código
  
public:

    // constructoras
  
    /** @brief Creadora por defecto de un idioma
     
        Cuando se declara se ejecuta automáticamente
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
        \post se añaden a tabla_frec del parámetro implícito las frecuencias de la nueva tabla
    */
    void modificar_tabla(vector<Nodo>& tabla);
	
	/** @brief Asigna los códigos de caracter a un idioma
        \pre <em>cierto</em> 
        \post se añaden a d del parámetro implícito los códigos de sus caracteres
    */
	void asignar_codigos();
	
    // consultoras
	
	/** @brief Consulta el nombre de un idioma
        \pre <em>cierto</em> 
        \post el resultado es el nombre del parámetro implícito
    */
    string consultar_nombre();
  
    /** @brief Consulta la tabla de frecuencias de un idioma
        \pre <em>cierto</em> 
        \post el resultado es la tabla_frec del parámetro implícito
    */
    vector<Nodo> consultar_tabla_frec();
  
    /** @brief Consulta los códigos de un idioma
        \pre <em>cierto</em> 
        \post el resultado es el conjunto de códigos del parámetro implícito
    */
    void consultar_codigos();
  
    /** @brief Consulta el código de un caracter de un idioma
        \pre el caracter c puede no estar en el diccionario d del parámetro implícito 
        \post el resultado es el código del caracter concreto si este existe, si no, se avisará 
    */
    void consultar_codigo_especifico(string c);
	
	/** @brief Consulta el treecode de un idioma
        \pre <em>cierto</em> 
        \post el resultado es el treecode del paràmetro implícito
    */
	void consultar_treecode();
  
    // entrada/salida
	
	/** @brief Operación de escritura de tabla_frec
        \pre <em>cierto</em>
        \post se escribe en el canal de salida estándard tabla_frec
    */
	void escribir_tabla_frec();
    
    /** @brief Operación de lectura de un idioma
        \pre en la entrada se encuentra un string y una seguido de Nodos (vector)
        \post el parámetro implícito pasa a tener nombre y tabla_frec 
    */
    void leer_idioma();
  
    ~Idioma();
    
};
#endif

