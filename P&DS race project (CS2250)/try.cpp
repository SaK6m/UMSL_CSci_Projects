#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Horse.h"

using namespace std;

/*************************************************************************************
 * For my program I am allowing distance of race be max of 50 and the max speed is 30
 * **********************************************************************************/

int main(){
    int count = 1;
    char x;
    int length;
    int num;
    Horse * name[num];

    cout << "How many Horses would you want to race? ";
    cin >> num;

    //validating positive integer
    while (num < 0) {
        cout<< "The number should be positive integer greater than 0 :";
        cin >> num;
    };

    cin.ignore();

    for (int i = 0; i < num; i++)
    {   string x, y;
        cout<< "What's the horse name: ";
        getline(cin,x);

        cout << "Now the rider's name: "; 
        getline(cin,y);

        name[i] =new Horse(x , y); //dynamic array of rider and horse name
    }
    cout << "-------------------------------------------" <<endl;

    cout <<"What is the length of the race? ";
    
    cin >> length;
    //I chose lenght between 10 to 50 because of my screen
    while (length < 10 || length > 50) {
        cout<< "Please select in range from 10 to 50: ";
        cin >> length;
    };

    cout << "-------- LETS BEGIN THE RACE!! ----------" << endl;

    cout<< endl;

    do{ 
        //do{
        cout <<"********************************" << endl;
        cout << "Shall we start (y/n)? ";
        cin.ignore();

        if(cin.get() == 'y' ){
            //starting points
            for (int i = 0; i < num; i++)
                {
                    cout << name[i]->getDistanceTravelled()<< endl;
                    name[i]->displayHorse(length);
                }

        do{
            cout << "Round " << count << " start (y/n)? ";
            cin.ignore();
            cin.get(x);

            if(x == 'y'){
                for (int i = 0; i < num; i++)
                    {
                        name[i]->runASecond();
                        name[i]->displayHorse(length);
                        
                        //if someone wins 
                        if(name[i]->getDistanceTravelled() >= length){
                                name[i]->races();
                                cout << "Starting rom gate again" << endl;

                            for (size_t i = 0; i < num; i++)
                            {   
                                name[i]->sendToGate(); //sending to starting pont
                                name[i]->displayHorse(length);  
                            }                      
                        }
                    }
            }else {
                cout<<endl <<"----------------- THE RESULTS -----------------" <<endl;
            };

            count++;

        } while (x == 'y');

        } else {cout << "-------------------Thank You!! GOOD BYE!!------------------ " <<endl;};

        //displaying the result with winning number
        for (int i = 0; i < num; i++){
            cout << name[i]->getName() << " has number of wins = " << name[i]->getWinNum() << endl;
        }

        cout << "Do you wish to continue(y/n)?: ";
        cin.ignore();
    } while (cin.get() == 'y' );

    cout<< endl << "-------------------------Thank you for playing with us!----------------------------";

    return 0;
}