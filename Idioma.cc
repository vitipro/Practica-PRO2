#include "Idioma.hh"

Idioma::Idioma() {}

Idioma::~Idioma() {}

void Idioma::modificar_tabla(vector<Nodo> tabla) {
		
}

vector<Nodo> Idioma::consultar_tabla() const {
	return tabla_frec;
}

string Idioma::consultar_nombre() const {
    return nombre;
}

bool ordena(const Nodo& n1, const Nodo& n2) {
	return n1.consultar_caracter() < n2.consultar_caracter();
}

void Idioma::escribir_tabla_frec() {
	sort(tabla_frec.begin(), tabla_frec.end(), ordena);
    for (int i = 0; i < tabla_frec.size(); ++i) tabla_frec[i].escribir();
    cout << endl;
}

void Idioma::consultar_codigos() const {
	treecode.consultar_codigos();
}

void Idioma::consultar_codigo_especifico(string c) const {
    treecode.consultar_codigo_especifico(c);
}

void Idioma::consultar_treecode() const {
	treecode.escribir_treecode();
}

void Idioma::leer_idioma() {
    Nodo n;
    vector<Nodo> v;
    int a;
    cin >> nombre;
    cin >> a;
    for (int i = 0; i < a; ++i) {
        n.leer();
        v.push_back(n);
    }
    tabla_frec = v;
    treecode.crear_treecode(v);
}

void Idioma::codifica(string texto) {
	treecode.codifica(texto);
}

void Idioma::decodifica(string texto) {
	treecode.decodifica(texto);
}
    