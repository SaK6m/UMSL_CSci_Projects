#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Horse{
    private:
        string horseName, rider;
        int distanceTravelled =  0;
        int win_num, maxRunningDistPerSecond;

    public:
        void setHorseName(string);
        void setdistance(int);
        void setmaxdistance(int);

        string getHorseName();
        int getDistance() const;

};

void Horse::setHorseName(string h){
    horseName = h;
}

string Horse::getHorseName(){
    return horseName;
}

void Horse::setmaxdistance(int d){
    maxRunningDistPerSecond = d;
}

int Horse::getDistance() const {
    return maxRunningDistPerSecond;
}

int main(){
    int num = 3;
    Horse name;
    string hName;
    cout<< "Name of your horse is: " ;
    cin >> hName;

    name.setHorseName(hName);

    //random number from 1-100
    int x;
            unsigned int seed = time(0);
            srand(seed);
 
            x = rand() % 100 + 1;

    name.setmaxdistance(x);

    cout<< "Your horse " <<name.getHorseName() <<" has travelled " << name.getDistance(); 
    
}