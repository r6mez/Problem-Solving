#include <iostream> 
#include <vector>
#include <sstream>
using namespace std;

void wrongSubtraction(){
    int number, numberOfSubtractions;
    cin >> number >> numberOfSubtractions;

    for (int i = 0; i < numberOfSubtractions; i++)
    {
        if(number % 10 != 0){
            number--;
        } else {
            number = number / 10;
        }
    }
    
    cout << number;
}


int main(){
    wrongSubtraction();
    return 0;
}