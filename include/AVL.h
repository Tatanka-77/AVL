#pragma once
#include "Nodo.h"

class AVL {
    Nodo *radice;

private:
    void rotazioneSinistra(Nodo*);
    void rotazioneDestra(Nodo*);

    void bilancia(Nodo*);
    void diminuisciAltezza(Nodo*);
    void aumentaAltezza(Nodo*);

public:
    AVL();
    ~AVL();
    void inserisci(int);
    Nodo* cerca(int);
    void cancella(int);

};




