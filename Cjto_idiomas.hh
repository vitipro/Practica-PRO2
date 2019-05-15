/** @file Cjto_idiomas.hh
    @brief Especificación de la clase Cjto_idiomas 
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
    
    Se trata de una colección de idiomas con los cuales se quiere codificar y decodificar textos
*/

class Cjto_idiomas {

private:

    map<string, Idioma> c;      // key string es el nombre del Idioma

public:

    // constructoras
    
    /** @brief Creadora por defecto de un conjunto
     
        Cuando se declara se ejecuta automáticamente
        \pre <em>cierto</em> 
        \post el resultado es un conjunto de idiomas vacío
    */
    Cjto_idiomas(); 
  
    // modificadoras
  
    /** @brief Añade un idioma al conjunto
        \pre I no está en el conjunto
        \post el conjunto pasa a contener a I
    */
    void anadir_idioma(Idioma& I);
    
    // consultoras
  
    /** @brief Consulta si cierto idioma está en el conjunto
     
        Mediante el identificador (nombre) del idioma, retornará true si el idioma a buscar está en el conjunto
        \pre <em>cierto</em>
        \post retorna true si id = nombre de I, por tanto, está en el conjunto
    */
    bool existe_idioma(string id) const;
 
    /** @brief Consulta un idioma del conjunto
        \pre id = nombre de idioma existente en el conjunto
        \post el resultado es un iterador que apunta al idioma consultado
    */
    map<string, Idioma>::iterator consultar_idioma(string id);
  
    // entrada/salida
  
    /** @brief Operación de lectura del conjunto
        \pre en el canal estándard de entrada hay un entero n, número de elementos del conjunto, y una série de idiomas
        \post los idiomas se han añadido al conjunto
    */
    void leer_conjunto();
  
    ~Cjto_idiomas();
    
};
#endif
