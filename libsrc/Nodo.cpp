#include "Nodo.h"

inline int Nodo::getDato() const {
    return this->dato;
}

Nodo::Nodo(int dato) {
    this->dato = dato;
    this->padre = nullptr;
    this->figlioSinistro = nullptr;
    this->figlioDestro = nullptr;
    this->altezzaSx= 0;
    this->altezzaDx= 0;
}

inline Nodo* Nodo::getPadre() {
    return this->padre;
}

inline Nodo *Nodo::getFiglioSinistro() {
    return this->figlioSinistro;
}

inline Nodo *Nodo::getFiglioDestro() {
    return this->figlioDestro;
}

inline int Nodo::getBilanciamento() const {
    return this->altezzaSx - this->altezzaDx;
}

inline void Nodo::setDato(int valore) {
    this->dato = valore;
}

inline void Nodo::setFiglioSinistro(Nodo* nuovoFiglioSinistro) {
    this->figlioSinistro = nuovoFiglioSinistro;
}

inline void Nodo::setFiglioDestro(Nodo* nuovoFiglioDestro) {
    this->figlioSinistro = nuovoFiglioDestro;
}

inline void Nodo::setPadre(Nodo* nuovoPadre ) {
    this->figlioSinistro = nuovoPadre;
}

inline void Nodo::incrementaAltezzaSx() {
    this->altezzaSx++;
}

inline void Nodo::incrementaAltezzaDx() {
    this->altezzaDx++;
}

inline void Nodo::decrementaAltezzaSx() {
    this->altezzaSx--;
}

inline void Nodo::decrementaAltezzaDx() {
    this->altezzaDx--;
}