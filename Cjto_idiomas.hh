/** @file Cjto_idiomas.hh
    @brief Especificaci�n de la clase Cjto_idiomas 
*/

#ifndef _CONJ_IDIOMAS_HH_
#define _CONJ_IDIOMAS_HH_

#include "Idioma.hh"

#ifndef NO_DIAGRAM
#include <map>
#endif

/** @class Cjto_idiomas
    @brief Representa un conjunto de idiomas.
    
    Se trata de una colecci�n de idiomas con los cuales se quiere codificar y decodificar textos.
*/

class Cjto_idiomas {

private:

	/** @brief Diccionario de idiomas 
	
		La llave string es el nombre del idioma
	*/
    map<string, Idioma> c;      

public:

    // constructoras
    
    /** @brief Creadora por defecto de un conjunto.
     
        Cuando se declara se ejecuta autom�ticamente.
        \pre <em>cierto</em> 
        \post El resultado es un conjunto de idiomas vac�o.
    */
    Cjto_idiomas(); 
  
    // modificadoras
  
    /** @brief A�ade un idioma al conjunto.
        \pre I no est� en el conjunto.
        \post El conjunto pasa a contener a I.
    */
    void anadir_idioma(Idioma& I);
    
    // consultoras
  
    /** @brief Consulta si cierto idioma est� en el conjunto mediante un identificador id (nombre) del idioma a buscar.
        \pre <em>cierto</em>
        \post Retorna true si id = nombre de un idioma existente en el conjunto.
    */
    bool existe_idioma(string id) const;
 
    /** @brief Consulta un idioma del conjunto.
        \pre id = nombre de idioma existente en el conjunto.
        \post El resultado es un iterador que apunta al idioma consultado.
    */
    map<string, Idioma>::iterator consultar_idioma(string id);
  
    // entrada/salida
  
    /** @brief Operaci�n de lectura del conjunto.
        \pre En el canal est�ndard de entrada hay un entero n, n�mero de elementos del conjunto, y una serie de idiomas.
        \post Los idiomas le�dos quedan a�adidos al conjunto.
    */
    void leer_conjunto();
  
    ~Cjto_idiomas();
    
};
#endif
