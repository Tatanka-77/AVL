#include "Nodo.h"

int Nodo::getDato() const {
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

Nodo* Nodo::getPadre() {
    return this->padre;
}

Nodo *Nodo::getFiglioSinistro() {
    return this->figlioSinistro;
}

Nodo *Nodo::getFiglioDestro() {
    return this->figlioDestro;
}

int Nodo::getBilanciamento() const {
    return this->altezzaSx - this->altezzaDx;
}

void Nodo::setDato(int valore) {
    this->dato = valore;
}

void Nodo::setFiglioSinistro(Nodo* nuovoFiglioSinistro) {
    this->figlioSinistro = nuovoFiglioSinistro;
}

void Nodo::setFiglioDestro(Nodo* nuovoFiglioDestro) {
    this->figlioDestro = nuovoFiglioDestro;
}

void Nodo::setPadre(Nodo* nuovoPadre ) {
    this->padre = nuovoPadre;
}

void Nodo::incrementaAltezzaSx() {
    this->altezzaSx++;
}

void Nodo::incrementaAltezzaDx() {
    this->altezzaDx++;
}

void Nodo::decrementaAltezzaSx() {
    this->altezzaSx--;
}

void Nodo::decrementaAltezzaDx() {
    this->altezzaDx--;
}