#include <iostream>
#include <string>
#include <ctime>

using namespace std;



class Flight {

    private: 
        time_t flightTime;
        string aerolinea;
        int flightID;
        int passengers;  

    public: 
        Flight(int pHour, int pMinutes) {
            flightTime = time(NULL);
            tm * currentTime = localtime(&flightTime);
            currentTime->tm_hour = pHour;
            currentTime->tm_min = pMinutes;
            flightTime = mktime(currentTime);
        }

        char* flightTimeString() {
            char* result = ctime(&flightTime);
            return result;
        }

        int getIntTimeValue() {
            int result = 0;        
            tm * midnight = localtime(&flightTime);
            midnight->tm_hour = 0;
            midnight->tm_min = 0;
            midnight->tm_sec = 0; 
            result = difftime(flightTime, mktime(midnight)) / 600;
            return result;
        }
};