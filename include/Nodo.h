#pragma once
#include <iostream>

using namespace std;


class Nodo {
    int dato;
    Nodo* padre;
    Nodo* figlioSinistro;
    Nodo* figlioDestro;
    int altezzaSx;
    int altezzaDx;

public:
    explicit Nodo(int);
    int getDato() const;
    Nodo* getPadre();
    Nodo* getFiglioSinistro();
    Nodo* getFiglioDestro();
    int getBilanciamento() const;
    void setDato(int);
    void setFiglioSinistro(Nodo*);
    void setFiglioDestro(Nodo*);
    void setPadre(Nodo*);
};




