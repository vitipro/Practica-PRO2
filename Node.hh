#include <iostream>
#include <BinTree>
using namespace std;

class Node {

private:
  
  string caracter;        
  int freq;               
  
public:

  // constructores
  
  Node();                     // generica
  /* Pre: cert */
  /* Post: el resultat es un Node sense caracter i sense freq */
  
  Node(string c, int f);      // concreta
  /* Pre: cert */
  /* Post: el resultat es un Node amb caracter = c i freq = f */
  
  // modificadores
  
  void modif_node(BinTree<Node> T, Node n);      // ¿?
  
  // consultores
  
  string consultar_caracter();
  /* Pre: cert */
  /* Post: el resultat es l'atribut caracter del parametre implicit */
  
  int consultar_freq();
  /* Pre: cert */
  /* Post: el resultat es l'atribut freq del parametre implicit */
  
  //entrada/sortida
  
  void llegir();
  /* Pre: a la entrada es troba un string i un enter */
  /* Post: l'string passa a ser l'atribut caracter i l'enter l'atribut freq del parametre implicit */
  
  void escriure();
  /* Pre: cert */
  /* Post: s'escriuen l'atribut caracter i l'atribut freq del parametre implicit */
  
  ~Node();

}
  
