#pragma once
#include "Nodo.h"

class AVL {
    Nodo *radice;

private:
    void rotazioneSinistra(Nodo*);
    void rotazioneDestra(Nodo*);
    void rotazioneSinistraDestra(Nodo*);
    void rotazioneDestraSinistra(Nodo*);
    void bilancia(Nodo*);
    void aggiornaAltezzaInserimento(Nodo*);
    void aggiornaAltezzaEliminazione(Nodo*);


public:
    AVL();
    ~AVL();
    void inserisci (int);
    Nodo* cerca (int);
    void cancella(int);

};




