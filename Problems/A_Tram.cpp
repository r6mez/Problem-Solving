#include <iostream> 
#include <vector>
#include <sstream>
using namespace std;

void stop(int &numberOfPassagers){
    int output,input;
    cin >> output >> input;

    numberOfPassagers -= output;
    numberOfPassagers += input;
}

void calcMinPassengers(){
    int numberOfStops;
    cin >> numberOfStops;

    int numberOfPassangers = 0;
    int maxNumberOfPassengers = 0;
    for (int i = 0; i < numberOfStops; i++)
    {
        stop(numberOfPassangers);
        if (numberOfPassangers > maxNumberOfPassengers) maxNumberOfPassengers = numberOfPassangers; 
    }

    cout << maxNumberOfPassengers;
}


int main(){
    calcMinPassengers();
    return 0;
}