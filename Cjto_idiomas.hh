/** @file Cjto_idiomas.hh
    @brief Especificaci�n de la clase Cjto_idiomas 
*/

#ifndef _CONJ_IDIOMAS_HH_
#define _CONJ_IDIOMAS_HH_

#include "Idioma.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <iterator>
#endif

/** @class Cjto_idiomas
    @brief Representa un conjunto de idiomas
    
    Se trata de una colecci�n de idiomas con los cuales se quiere codificar y decodificar textos
*/

class Cjto_idiomas {

private:

    map<string, Idioma> c;      // key string es el nombre del Idioma

public:

    // constructoras
    
    /** @brief Creadora por defecto de un conjunto
     
        Cuando se declara se ejecuta autom�ticamente
        \pre <em>cierto</em> 
        \post el resultado es un conjunto de idiomas vac�o
    */
    Cjto_idiomas(); 
  
    // modificadoras
  
    /** @brief A�ade un idioma al conjunto
        \pre I no est� en el conjunto
        \post el conjunto pasa a contener a I
    */
    void anadir_idioma(Idioma& I);
    
    // consultoras
  
    /** @brief Consulta si cierto idioma est� en el conjunto
     
        Mediante el identificador (nombre) del idioma, retornar� true si el idioma a buscar est� en el conjunto
        \pre <em>cierto</em>
        \post retorna true si id = nombre de I, por tanto, est� en el conjunto
    */
    bool existe_idioma(string id) const;
 
    /** @brief Consulta un idioma del conjunto
        \pre id = nombre de idioma existente en el conjunto
        \post el resultado es un iterador que apunta al idioma consultado
    */
    map<string, Idioma>::iterator consultar_idioma(string id);
  
    // entrada/salida
  
    /** @brief Operaci�n de lectura del conjunto
        \pre en el canal est�ndard de entrada hay un entero n, n�mero de elementos del conjunto, y una s�rie de idiomas
        \post los idiomas se han a�adido al conjunto
    */
    void leer_conjunto();
  
    ~Cjto_idiomas();
    
};
#endif
