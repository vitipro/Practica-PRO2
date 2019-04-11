#include "Node.hh"
#include <BinTree>
#include <vector>

class Idioma {

private:

  string nom;                 // identificador
  vector<Node> taula_freq;    // taula de frequencies
  BinTree treecode;
  
public:

  //constructores
  Idioma();                                            
  BinTree crear_treecode(BinTree<Node>& T);
  
  //modificadores
  void actualitzar_treecode(BinTree<Node>& T);
  
  //consultores
  vector<Node> consultar_taula_freq();
  string consultar_codi();
  
  //entrada/sortida
  void llegir_idioma();
  void escriure_idioma();
  
  ~Idioma();
}
  
