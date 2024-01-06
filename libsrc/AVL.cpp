#include "AVL.h"

AVL::AVL() {
    this->radice = nullptr;
}

AVL::~AVL() {
    //todo
}

void AVL::rotazioneSinistra(Nodo*) {
    //todo
}

void AVL::rotazioneDestra(Nodo*) {
    //todo
}

void AVL::rotazioneSinistraDestra(Nodo*) {
    //todo
}

void AVL::rotazioneDestraSinistra(Nodo*) {
    //todo
}

void AVL::bilancia(Nodo*) {
    //todo
}

void AVL::inserisci(int valore) {
    Nodo* nodo = new Nodo(valore);
    if (this->radice == nullptr) { //se l'albero è vuoto
        this->radice = nodo; //il nuovo nodo diventa radice
        return;
    }
    Nodo* nodoCorrente = this->cerca(valore);
    if ( nodoCorrente->getDato() == valore) return; //termino se il valore è gia presente (duplicati non permessi)
    if (valore < nodoCorrente->getDato()) { //controllo se nodo dev'essere figlio sinistro o destro del nodoCorrente...
        nodoCorrente->setFiglioSinistro(nodo); //aggiorno il rispettivo link del padre
        nodoCorrente->incrementaAltezzaSx(); //e ne incremento l'altezza del sottoalbero
    }
    else {
        nodoCorrente->setFiglioDestro(nodo);
        nodoCorrente->incrementaAltezzaDx();
    }
    nodo->setPadre(nodoCorrente); //aggiorno il link del figlio
    this->aumentaAltezza(nodoCorrente);
    this->bilancia(nodo->getPadre()); //verifico ed eventualmente ripristino il bilanciamento dell'albero
}

void AVL::aumentaAltezza(Nodo *nodoCorrente) {
    while (nodoCorrente->getPadre() != nullptr) { //risalendo fino alla radice
        if (nodoCorrente->getDato() < nodoCorrente->getPadre()->getDato())
            nodoCorrente->getPadre()->incrementaAltezzaSx(); //aggiorno le altezze dei sottoalberi
        else
            nodoCorrente->getPadre()->incrementaAltezzaDx();
        nodoCorrente=nodoCorrente->getPadre();
    }
}


/*Funzione per la ricerca nell'albero AVL.
INPUT: valore da ricercare.
OUTPUT: puntatore al nodo avente chiave il valore ricercato oppure il puntatore al nodo dove la ricerca termina in caso
        di insuccesso. La verifica dei due casi è a carico dell'utilizzatore. In caso di ricerca in un AVL vuoto
        restituisce nullptr. */
Nodo* AVL::cerca(int valore) {
    Nodo* nodoCorrente = this->radice;
    Nodo* nodoPrecedente = nodoCorrente;
    while (nodoCorrente != nullptr && nodoCorrente->getDato() != valore) {
        nodoPrecedente = nodoCorrente;
        nodoCorrente =  (valore < nodoCorrente->getDato())?nodoCorrente->getFiglioSinistro():nodoCorrente->getFiglioDestro();
    }
    return (nodoCorrente != nullptr)?nodoCorrente:nodoPrecedente;
}



void AVL::cancella(int valore) {
    Nodo* nodoTarget = this->cerca(valore);
    if (nodoTarget == nullptr || nodoTarget->getDato() != valore) return; //termina se il valore non è presente nell'albero
    else {
        if (nodoTarget->getFiglioSinistro() == nullptr && nodoTarget->getFiglioDestro() == nullptr) { //se il nodo è una foglia...
            if (nodoTarget != this->radice) {
                Nodo *nodoCorrente = nodoTarget;
                this->diminuisciAltezza(nodoCorrente);
                if (nodoTarget->getDato() <
                    nodoTarget->getPadre()->getDato()) //Verifica se il target è figlio sx o dx del padre...
                    nodoTarget->getPadre()->setFiglioSinistro(nullptr); //...e aggiorna i link corrispondenti.
                else nodoTarget->getPadre()->setFiglioDestro(nullptr);
            }
            else this->radice= nullptr;
            delete nodoTarget; //elimina il nodo cercato
            return;
        }
        if (nodoTarget->getFiglioSinistro() == nullptr || nodoTarget->getFiglioDestro() == nullptr) { //se il nodo ha un solo figlio
            if (nodoTarget->getFiglioSinistro() == nullptr) {
                if (nodoTarget->getPadre() != nullptr) {
                    nodoTarget->getPadre()->setFiglioDestro(nodoTarget->getFiglioDestro()); //se è quello destro:
                    nodoTarget->getFiglioDestro()->setPadre(nodoTarget->getPadre());
                }
                else {
                    this->radice=nodoTarget->getFiglioDestro();
                    this->radice->setPadre(nullptr);
                }
            }
            else {
                if (nodoTarget->getPadre() != nullptr) {
                    nodoTarget->getPadre()->setFiglioSinistro(nodoTarget->getFiglioSinistro()); //se è quello sinistro
                    nodoTarget->getFiglioSinistro()->setPadre(nodoTarget->getPadre());
                } else {
                    this->radice=nodoTarget->getFiglioSinistro();
                    this->radice->setPadre(nullptr);
                }
            }
            this->diminuisciAltezza(nodoTarget);
            delete nodoTarget;
            return;
        }
        Nodo* nodoCorrente = nodoTarget->getFiglioSinistro(); //se il nodo ha due figli prendiamo il massimo del sottoalbero sx:
        while (nodoCorrente->getFiglioDestro() != nullptr) nodoCorrente = nodoCorrente->getFiglioDestro();
        if (nodoCorrente->getDato() < nodoCorrente->getPadre()->getDato()) nodoCorrente->getPadre()->setFiglioSinistro(nullptr);
        else nodoCorrente->getPadre()->setFiglioDestro(nullptr); //rimuoviamo il link orfano dal padre
        this->diminuisciAltezza(nodoCorrente);
        nodoTarget->setDato(nodoCorrente->getDato()); //scambiamo il dato del nodo corrente con quello che vogliamo eliminare
        delete nodoCorrente;
    }
}

void AVL::diminuisciAltezza(Nodo* nodoCorrente) {
    while (nodoCorrente->getPadre() != nullptr) {
        if (nodoCorrente->getDato() < nodoCorrente->getPadre()->getDato())
            nodoCorrente->getPadre()->decrementaAltezzaSx();
        else
            nodoCorrente->getPadre()->decrementaAltezzaDx();
        nodoCorrente=nodoCorrente->getPadre();
    }
}


