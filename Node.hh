#include <iostream>
#include <BinTree>
using namespace std;

class Node {

private:
  
  string caracter;
  int freq;
  
public:

  //constructores
  Node();                     //generica
  Node(string c, int f);      //concreta
  
  //modificadores
  void modif_node(BinTree<Node> T, Node n);
  
  //consultores
  string consultar_caracter();
  int consultar_freq();
  
  //entrada/sortida
  void llegir();
  void escriure();
  
  ~Node();

}
  
