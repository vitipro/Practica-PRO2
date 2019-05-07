#include "Cjto_idiomas.hh"
#include "Idioma.hh"
#include <map>
#include <iostream>
using namespace std;

Cjto_idiomas::Cjto_idiomas() {}

Cjto_idiomas::~Cjto_idiomas() {}

bool Cjto_idiomas::existe_idioma(string id) const {
    map<string, Idioma>::const_iterator it = c.find(id);
    if (it == c.end()) return false;
    else return true;
}

void Cjto_idiomas::anadir_idioma(Idioma& I) {
    string id = I.consultar_nombre();
	c.insert(make_pair(id, I));
}

//void Cjto_idiomas::modificar_idioma(Idioma& I) const {
//	string id = I.consultar_nombre();
	//map<string, Idioma>::const_iterator it = c.find(id);
	//Idioma i = it->second;
	//it->second = I;
//}

map<string, Idioma>::iterator Cjto_idiomas::consultar_idioma(string id) {
    map<string, Idioma>::iterator it = c.find(id);
	return it;
}

void Cjto_idiomas::leer_conjunto() {
    int n;
    Idioma I;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        I.leer_idioma();
        anadir_idioma(I);
    }
}

//void Cjto_idiomas::codifica_idioma(string id, string& texto) {

//}

//void Cjto_idiomas::decodifica_idioma(string id, string& texto) {

//}
