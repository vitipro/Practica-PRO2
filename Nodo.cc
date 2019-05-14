#include "Nodo.hh"

Nodo::Nodo() {
    caracter = "";
    frec = 0;
}

Nodo::~Nodo() {}

Nodo::Nodo(string c, int f) {
    caracter = c;
    frec = f;
}

void Nodo::modif_frec_nodo(int f) {
	frec = f;
}

string Nodo::consultar_caracter() const {
    return caracter;
}

int Nodo::consultar_frec() const {
    return frec;
}

void Nodo::leer() {
    cin >> caracter >> frec;
}

void Nodo::escribir() const {
    cout << caracter << " " << frec << endl;
}