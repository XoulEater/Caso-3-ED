#include "Flight.h"
#include "List.h"

List<Flight>* Vuelos = new List<Flight>();

// debe llenar una lista de pCantidad vuelos aleatorios cuya hora y minutos de partida esten entre pStartHour y pEndHour
// tomando en cuenta las restricciones de los minutos de salida segun el ejercicio 3 del caso #3
void fillFlights(int pCantidad, int pStartHour, int pEndHour) {
    int minutes;
    int hour;
    int order;
    for (int i = 0; i < pCantidad; i++)
    {
        int hour = rand() % (pEndHour-pStartHour) + pStartHour;
        int minutes = rand() % 18;

        Flight* vuelo = new Flight(hour, minutes);

        order = 0;
        if (!Vuelos->isEmpty()) {
            
            for (int j = 0; j < Vuelos->getSize(); j++)
            {
                if (Vuelos->find(j)->getIntTimeValue() > vuelo->getIntTimeValue()) {
                    break;
                } else {
                    order++;
                } 
            }
        }
        
        Vuelos->insert(order ,vuelo);
    }
    

} 

void orderFlights(int Pistas) {
    // Pendiente
} 



int main() {

    fillFlights(19, 1, 23);

    for (int i = 0; i < Vuelos->getSize(); i++)
        cout << Vuelos->find(i)->flightTimeString() << "y el entero es: " << Vuelos->find(i)->getIntTimeValue() << endl;

}