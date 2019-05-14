#include "Idioma.hh"

Idioma::Idioma() {}

Idioma::~Idioma() {}

bool ordena(const Nodo& n1, const Nodo& n2) {
	return n1.consultar_caracter() < n2.consultar_caracter();
}

void Idioma::modificar_tabla(vector<Nodo> tabla) {
	for (int i = 0; i < tabla.size(); ++i) tabla_frec.push_back(tabla[i]);
	sort(tabla_frec.begin(), tabla_frec.end(), ordena);
	int i = 0;
	vector<Nodo>::iterator it = tabla_frec.begin();
	while (i < tabla_frec.size() - 1) {
		if (tabla_frec[i].consultar_caracter() == tabla_frec[i + 1].consultar_caracter()) {
			int suma = tabla_frec[i].consultar_frec() + tabla_frec[i + 1].consultar_frec();
			tabla_frec[i].modif_frec_nodo(suma);
			tabla_frec.erase(it + i + 1);
			++i;
		}
		else ++i;
	}
	treecode.crear_treecode(tabla_frec);
}

vector<Nodo> Idioma::consultar_tabla() const {
	return tabla_frec;
}

string Idioma::consultar_nombre() const {
    return nombre;
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