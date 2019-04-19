#include "Idioma.hh"
#include <map>

class Cjt_idiomes {

private:

    map<string, Idioma> c;      // clau string es el nom de l'Idioma

public:

    // constructores
  
    Cjt_idiomes();          
  
    // consultores
  
    bool existeix_idioma(string id) const;
    /* Pre: cert */
    /* Post: retorna true si id = nom de Idioma, per tant, hi es al conjunt */
  
    Idioma consultar_idioma(string id) const;
    /* Pre: id = nom de Idioma existent al conjunt */
    /* Post: el resultat és el Idioma consultat */
  
    // modificadores
  
    void afegir_idioma(const Idioma& I);
    /* Pre: Idioma no hi és al conjunt */
    /* Post: el conjunt conté a Idioma */
  
    void modificar_idioma(const Idioma& I);
    /* Pre: Idioma hi és al conjunt */
    /* Post: Idioma ha estat modificat */
  
    // entrada/sortida
  
    void llegir_conjunt();
    /* Pre: al canal estàndard d'entrada hi ha una sèrie de idiomes */
    /* Post: els idiomes s'han afegit al conjunt */
  
    ~Cjt_idiomes();
    
}
