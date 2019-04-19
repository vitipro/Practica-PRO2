#include "Node.hh"
#include <map>

class Idioma {

private:

    string nom;                                 // identificador
    vector<Node> taula_freq;                    // taula de frequencies
    BinTree treecode;
    map<string caracter, string codi>           // diccionari per consultar codis
  
public:

    // constructores
  
    Idioma();             // generica
    /* Pre: cert */
    /* Post: el resultat es un Idioma sense nom ni taula_freq */
  
    Idioma(string nom); 
    /* Pre: cert */
    /* Post: el resultat es un idioma amb identificador nom i sense taula_freq */
  
    // modificadores
  
    void modificar_taula(vector<Node> taula);
    /* Pre: cert */
    /* Post: s'afegeixen a taula_freq del parametre implicit les frequencies de la nova taula */
  
    // consultores
  
    void consultar_taula_freq();
    /* Pre: cert */
    /* Post: el resultat es la taula_freq del parametre implícit */
  
    void consultar_codis();
    /* Pre: cert */
    /* Post: el resultat es el conjunt de codis de Idioma */
  
    void consultar_codi_especific(string caracter);
    /* Pre: cert */
    /* Post: el resultat es el codi de string concret */
  
    // entrada/sortida
  
    void llegir_idioma();
    /* Pre: a la entrada es troba un string nom d'Idioma i un seguit de Nodes (vector) */
    /* Post: el parametre implícit passa a tenir nom = nom i taula_freq = vector<Nodes> */
  
    void escriure_idioma();
    /* Pre: cert */
    /* Post: s'escriuen els atributs del parametre implícit */
  
    ~Idioma();
}
  
