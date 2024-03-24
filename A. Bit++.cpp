#include <iostream> 
#include <vector>
#include <sstream>
using namespace std;

int x = 0;

void beautifulMatrix(){
   string operation;
   cin >> operation;

   if(operation == "++X" || operation == "X++") x++;
   else x--;
}

void casesLoop(){
    int numberOfCases;
    cin >> numberOfCases;
    
    for (int i = 0; i < numberOfCases; i++) beautifulMatrix();

    cout << x;   
}


int main(){
    casesLoop();
    return 0;
}