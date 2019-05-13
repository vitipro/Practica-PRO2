/** @file Nodo.hh
    @brief Especificación de la clase Nodo
*/

#ifndef _NODO_HH_
#define _NODO_HH_

#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#endif

/** @class Nodo
    @brief Representa un nodo del treecode de un idioma 
*/

class Nodo {

private:
  
    string caracter;        
    int frec; 
	
public:

    // constructoras
  
    /** @brief Creadora por defecto de un nodo

        Cuando se declara se ejecuta automáticamente
        \pre <em>cierto</em> 
        \post el resultado es un Nodo sin caracter ni frec
    */
    Nodo();                     
  
    /** @brief Creadora de un nodo con caracter y frecuencia
        \pre <em>cierto</em> 
        \post el resultado es un Nodo con caracter = c i frec = f
    */
    Nodo(string c, int f);      
  
    // modificadoras
  
    // consultoras
    
    /** @brief Consultora del caracter de un nodo
        \pre <em>cierto</em> 
        \post el resultado es el atributo caracter del parámetro implícito
    */
    string consultar_caracter() const;
    
    /** @brief Consultora de la frecuencia de un nodo 
        \pre <em>cierto</em> 
        \post el resultado es el atributo frec del parámetro implícito
    */
    int consultar_frec() const;
  
    // entrada/salida
    
    /** @brief Operación de lectura de un nodo 
        \pre en la entrada se encuentra un string y un entero
        \post el string pasa a ser el atributo caracter y el entero el atributo frec del parámetro implícito
    */
    void leer();
  
    /** @brief Operación de escritura de un nodo
        \pre <em>cierto</em>  
        \post se escriben los atributos caracter y frec del parámetro implícito
    */
    void escribir() const;               
  
    ~Nodo();

};
#endif
  
