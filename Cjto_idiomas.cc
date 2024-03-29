/** @file Cjto_idiomas.cc
    @brief Código de la clase Cjto_idiomas 
*/

#include "Cjto_idiomas.hh"

Cjto_idiomas::Cjto_idiomas() {}

Cjto_idiomas::~Cjto_idiomas() {}

bool Cjto_idiomas::existe_idioma(string id) const 
{
    map<string, Idioma>::const_iterator it = conj.find(id);
    return it != conj.end(); 
}

void Cjto_idiomas::anadir_idioma(Idioma& I) 
{
    string id = I.consultar_nombre();
    conj.insert(make_pair(id, I));
}

map<string, Idioma>::iterator Cjto_idiomas::consultar_idioma(string id) 
{
    map<string, Idioma>::iterator it = conj.find(id);
	return it;
}

void Cjto_idiomas::leer_conjunto() 
{
    int n;
    cin >> n;     
    for (int i = 0; i < n; ++i) {
	    Idioma I;
	    I.leer_idioma();
        anadir_idioma(I);
    }
}