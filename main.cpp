#include <iostream>
#include "AVL.h"

using namespace std;

int main() {
    AVL* test = new AVL();
    test->inserisci(2);
    test->inserisci(3);
    test->inserisci(1);
    cout << test->cerca(2)->getDato() << endl;
    cout << test->cerca(4)->getDato() << endl;
    test->cancella(2);
    test->cancella(1);
    test->cancella(3);
    delete test;
    return 0;

}