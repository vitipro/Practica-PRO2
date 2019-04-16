#include "Idioma.hh"
#include <map>

class Cjt_idiomes {

private:

  map<string, Idioma> c;      // clau string es el nom de l'Idioma

public:

  // constructores
  
  Cjt_idiomes();           // generica
  
  // consultores
  
  bool existeix_idioma(Idioma I) const;
  
  // modificadores
  
  void afegir_idioma(const Idioma& I);
  
  void modificar_idioma(const Idioma& I);
  
  void modificar_idioma_iessim(const Idioma& I);
  
  // entrada/sortida
  
  void llegir_conjunt();
  
  ~Cjt_idiomes();
  
}
