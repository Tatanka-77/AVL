#include <iostream>
#include<cstdlib>
#include "AVL.h"

using namespace std;

int main() {
    AVL* test = new AVL();
    srand((unsigned) time(nullptr));
    for (int i=0; i < 6; i++) test->inserisci(rand()%100);
    delete test;
    return 0;

}