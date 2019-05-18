/** @file Idioma.hh
    @brief Especificaci�n de la clase Idioma
*/

#ifndef _IDIOMA_HH_
#define _IDIOMA_HH_
 
#include "Treecode.hh"

/** @class Idioma
    @brief Representa un idioma. 
    
    Cada idioma contiene unos c�digos para cada uno de sus caracteres, usando una tabla de frecuencias. Con estos c�digos se quiere codificar y decodificar textos escritos.
*/

class Idioma {

private:

	/** @brief Identificador del idioma */
    string nombre;                              
	/** @brief Tabla de frecuencias del idioma 
	
		La llave string representa el caracter del idioma, y el int su frecuencia en el mismo
	*/
    map<string, int> tabla_frec;                
	/** @brief Treecode del idioma */
    Treecode treecode;                         
  
public:

    // constructoras
  
    /** @brief Creadora por defecto de un idioma.
     
        Cuando se declara se ejecuta autom�ticamente.
        \pre <em>cierto</em> 
        \post El resultado es un Idioma sin nombre, y con tabla_frec y treecode vac�os.
    */
    Idioma();        

	/** @brief Creadora de un idioma a trav�s de su nombre.
		\pre <em>cierto</em> 
		\post El resultado es un idioma con nombre = id.
    */
    void crea_nuevo_idioma(string id);

    // modificadoras
    
    /** @brief Modifica la tabla de frecuencias de un idioma.
        \pre <em>cierto</em> 
        \post Se a�aden a tabla_frec del par�metro impl�cito las frecuencias de una nueva tabla si el caracter no existe, y si existe simplemente se suman sus frecuencias
    */
    void modificar_tabla();
	
    // consultoras
	
	/** @brief Consulta el nombre de un idioma.
        \pre <em>cierto</em> 
        \post El resultado es el nombre del par�metro impl�cito.
    */
    string consultar_nombre() const;
  
    /** @brief Consulta los c�digos de un idioma.
        \pre <em>cierto</em> 
        \post El resultado es el conjunto de c�digos del par�metro impl�cito.
    */
    void consultar_codigos() const;
  
    /** @brief Consulta el c�digo de un caracter de un idioma.
        \pre <em>cierto</em>
        \post El resultado es el c�digo del caracter c si �ste existe. Si no, se avisar�. 
    */
    void consultar_codigo_especifico(string c) const;
	
	/** @brief Consulta el treecode de un idioma.
        \pre <em>cierto</em> 
        \post El resultado es el treecode del par�metro impl�cito, escrito en pre e inorden.
    */
	void consultar_treecode() const;
  
    // entrada/salida
	
	/** @brief Codifica un texto en un idioma.
        \pre En la entrada se encuentra un string texto a codificar.
        \post Se escribe en el canal de salida est�ndard la codificaci�n del texto en el idioma si se puede. 
		
		Si no, se avisar� que no se puede indicando el primer caracter que falla.
    */
	void codifica(string texto);
	
	/** @brief Decodifica un texto en un idioma.
        \pre En el canal est�ndard de entrada se encuentra un string texto a decodificar.
        \post Se escribe en el canal de salida est�ndard el texto decodificado si se puede.

		Si no, se avisar� que no se puede indicando la �ltima posici�n decodificable del texto.
    */
	void decodifica(string texto);
	
	/** @brief Operaci�n de lectura de tabla_frec del par�metro impl�cito.
        \pre <em>cierto</em>
        \post Se leen en el canal de entrada est�ndard el tama�o y los datos de tabla_frec.
    */
	void leer_tabla_frec();
	
	/** @brief Operaci�n de escritura de tabla_frec del par�metro impl�cito.
        \pre <em>cierto</em>
        \post Se escribe en el canal de salida est�ndard tabla_frec.
    */
	void escribir_tabla_frec();
    
    /** @brief Operaci�n de lectura de un idioma.
        \pre En el canal est�ndard de entrada se encuentra un string nombre seguido de un entero n >= 2 y n pares <string, int>.
        \post El par�metro impl�cito pasa a tener nombre (primer string en el canal) y una tabla_frec conformada por n pares <string, int>, a partir de la cual se construye treecode. 
    */
    void leer_idioma();
  
    ~Idioma();
    
};
#endif
