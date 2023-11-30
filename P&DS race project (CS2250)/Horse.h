#include <string>
#ifndef HORSE_H
#define HORSE_H

using namespace std;

class Horse{
    private:
        string horseName, rider;
        int distanceTravelled;
        int win_num = 0;
        int maxRunningDistPerSecond;

    public:
        Horse(string, string);
        ~Horse();
        void runASecond();
        void races();
        void sendToGate();
        void displayHorse(int);
        int getDistanceTravelled();
        
        string getName();
        int getWinNum();
};

#endif