#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Horse.h"

using namespace std;

//constructor
Horse::Horse(string horseName = "empty", string rider = "empty"){
    this->horseName = horseName;
    this->rider = rider;
    
    //random number from 1-100
    // int x;
    // unsigned int seed = time(0);
    // srand(seed);

    // x = rand() % 30 + 1;
    // maxRunningDistPerSecond = x;
    unsigned int seed = time(0);
    srand(seed);

    sendToGate();
}

Horse::~Horse(){

}

//to get the names
string Horse::getName() {
    return this->horseName + ", riden by " + this->rider;
};

int Horse::getDistanceTravelled() {
    return distanceTravelled;
}

//sending to starting point
void Horse::sendToGate(){
    int x;
    x = rand() % 30 + 1;
    maxRunningDistPerSecond = x;
    distanceTravelled = 0;
}

void Horse::runASecond(){
    distanceTravelled += maxRunningDistPerSecond;
}

//displaying race path
void Horse::displayHorse(int goalLength){ 

    cout<< "|";
    for (int i = 0; i < goalLength; i++)
    {   
        if( i < distanceTravelled){
            cout << "-";
        } else if (i == distanceTravelled && distanceTravelled < goalLength){
            cout << ">";
        } else if(i < goalLength) cout <<" ";

        if(i + 1 == goalLength && distanceTravelled >= goalLength){
            cout<< "|>";
        } else if ((i+1) == goalLength){
            cout << "|";   
        }
    }

    cout<< " " << horseName << " ridden by " << rider << endl;
}

//to add race wins
void Horse::races(){
    win_num++;
}

int Horse::getWinNum(){
    return win_num;
}
