#include "Idioma.hh"
#include <map>

class Cjto_idiomas {

private:

    map<string, Idioma> c;      // clau string es el nom de l'Idioma

public:

    // constructores
  
    Cjto_idiomas();          
  
    // consultores
  
    bool existe_idioma(string id) const;
    /* Pre: cert */
    /* Post: retorna true si id = nom de Idioma, per tant, hi es al conjunt */
  
    Idioma consultar_idioma(string id) const;
    /* Pre: id = nom de Idioma existent al conjunt */
    /* Post: el resultat és el Idioma consultat */
  
    // modificadores
  
    void anadir_idioma(const Idioma& I);
    /* Pre: Idioma no hi és al conjunt */
    /* Post: el conjunt conté a Idioma */
  
    void modificar_idioma(const Idioma& I);
    /* Pre: Idioma hi és al conjunt */
    /* Post: Idioma ha estat modificat */
  
    // entrada/sortida
  
    void leer_conjunt();
    /* Pre: al canal estàndard d'entrada hi ha una sèrie de idiomes */
    /* Post: els idiomes s'han afegit al conjunt */
    
    void codifica_idioma(string id, string& texto);
    
    void decodifica_idioma(string id, string& texto);
  
    ~Cjto_idiomas();
    
}
