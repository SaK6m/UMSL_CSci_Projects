#include <iostream>
#include <string>

using namespace std;

int main(){
    int num = 51;
    int count = 50; 
    cout<< "|";
    for (size_t i = 1; i <= count; i++)
    {   
        if( i < num){
            cout << "-";
        } else if (i == num && num < count){
            cout << ">";
        } else if(i < count) cout <<" ";

        if(i == count && num >= count){
            cout<< "|>";
        } else if (i == count){
            cout << "|";
            
        }

    }
    
    
}