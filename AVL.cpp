#include "AVL.h"

AVL::AVL() {
this->radice = nullptr;
}

AVL::~AVL() {
}

void AVL::rotazioneSinistra(Nodo *) {

}

void AVL::rotazioneDestra(Nodo *) {

}



void AVL::rotazioneSinistraDestra(Nodo *) {

}

void AVL::rotazioneDestraSinistra(Nodo *) {

}

void AVL::bilancia(Nodo *) {

}

void AVL::aggiornaAltezzaInserimento(Nodo *) {

}

void AVL::inserisci(int valore) {
    Nodo* nodo = new Nodo(valore);
    if (this->radice != nullptr) {
        auto nodoCorrente = this->radice;
        Nodo* nodoPadre;
        bool figlioSX;
        while (nodoCorrente != nullptr) {
            nodoPadre = nodoCorrente;
            if (valore <= nodoCorrente->getDato()) {
                nodoCorrente = nodoCorrente->getFiglioSinistro();
                figlioSX = true;
            }
            else {
                nodoCorrente = nodoCorrente->getFiglioDestro();
                figlioSX = false;
            }
        }
        nodo->setPadre(nodoPadre);
        if (figlioSX) nodoPadre->setFiglioSinistro(nodo);
        else nodoPadre->setFiglioDestro(nodo);
        aggiornaAltezzaInserimento(nodo);
        this->bilancia(nodo);
    }
    else this->radice = nodo;
}

Nodo *AVL::cerca(int valore) {
    Nodo* nodoCorrente = this->radice;
    while (nodoCorrente != nullptr && nodoCorrente->getDato() != valore)
        nodoCorrente =  (valore < nodoCorrente->getDato())?nodoCorrente->getFiglioSinistro():nodoCorrente->getFiglioDestro();
    return nodoCorrente;
}

void AVL::cancella(int valore) {
    Nodo* nodoTarget = this->cerca(valore);
    if (nodoTarget == nullptr) return;
    else {
        if (nodoTarget->getFiglioSinistro() == nullptr && nodoTarget->getFiglioDestro() == nullptr) {
            aggiornaAltezzaEliminazione(nodoTarget->getPadre());

        }
    }
}

void AVL::aggiornaAltezzaEliminazione(Nodo *) {

}


