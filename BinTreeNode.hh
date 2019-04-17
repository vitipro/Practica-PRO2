#include "Node.hh"
#include "BinTree.hh" 
#include <iostream>
using namespace std;

void llegir_crear_treecode(BinTree<Node>& T);
/* Pre: es llegeix una taula de frequencies */
/* Post: T és un arbre que conté els Nodes corresponents */

void actualitzar_treecode(BinTree<Node>& T);
/* Pre: T és un BinTree no buit */
/* Post: T actualitza el seus Nodes */

void escriure_treecode(BinTree<Node>& T);        
/* Pre: cert */
/* Post: s'escriu al canal de sortida estàndard els recorreguts en pre i inordre de T */
