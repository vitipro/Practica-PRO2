#include "Idioma.hh"
#include <vector>

class Cjt_idiomes {

private:

  vector<Idioma> v_idiom;
  int n_idiom;

public:

  // constructores
  
  Cjt_idiomes();           // generica
  
  // modificadores
  
  void afegir_idioma(const Idioma& I);
  
  void modificar_idioma(const Idioma& I);
  
  void modificar_idioma_iessim(const Idioma& I, int i);
  
  // consultores
  
  bool existeix_idioma(Idioma I) const;
  
  ~Cjt_idiomes();
  
}
