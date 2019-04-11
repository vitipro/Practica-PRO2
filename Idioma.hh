#include "Node.hh"
#include <BinTree>
#include <vector>
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
  
  Idioma(string nom, vector<Node> taula_freq); 
  /* Pre: cert */
  /* Post: el resultat es un idioma amb identificador nom i taula taula_freq */
  
  BinTree crear_treecode(BinTree<Node>& T, vector<Node> taula_freq);      // BinTree o void ¿?  -MIRAR-
  /* Pre: T es un BinTree buit */
  /* Post: el resultat es un BinTree amb nodes amb els elements de taula_freq */
  
  // modificadores
  
  void actualitzar_treecode(BinTree<Node>& T, vector<Node> taula_freq);
  /* Pre: T es un BinTree no buit */
  /* Post: T actualitza el seus nodes amb el vector<Node> taula_freq */
  
  // consultores
  
  vector<Node> consultar_taula_freq();
  /* Pre: cert */
  /* Post: el resultat es la taula_freq del parametre implicit */
  
  void consultar_codi();
  /* Pre: cert */
  /* Post: el resultat es el conjunt de codis de Idioma */
  
  // entrada/sortida
  
  void llegir_idioma();
  /* Pre: a la entrada es troba un string nom d'Idioma i un seguit de Nodes (vector) */
  /* Post: el parametre implicit passa a tenir nom = nom i taula_freq = vector<Nodes> */
  
  void escriure_idioma();
  /* Pre: cert */
  /* Post: s'escriuen els atributs del parametre implicit */
  
  ~Idioma();
}
  
