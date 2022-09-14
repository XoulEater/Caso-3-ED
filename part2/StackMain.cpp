#include <iostream>
#include "QueueP.h"

using namespace std;

int main() {
    QueueP<string>* colaNombres = new QueueP<string>();

    colaNombres->enqueue(new string("el primer mensaje que meto"));
    colaNombres->enqueue(new string("el segundo mensaje que meto"));
    colaNombres->enqueue(new string("el tercero mensaje que meto"));

    cout << *colaNombres->front()<< endl;

    while (!colaNombres->isEmpty()) {
        cout << *colaNombres->dequeue() << endl;
    }


    if (colaNombres->isEmpty())
    {
        cout << "Esta vacia" << endl;
    }

}
