#include <iostream> 
using namespace std;


void calcPercentageOfOJ(){
    double numberOfDrinks;
    cin >> numberOfDrinks;
    double total = 0;

    for (int i = 0; i < numberOfDrinks; i++)
    {
        int x;
        cin >> x;
        total += x;
    }
    

    double percentage = (float) ((total / (numberOfDrinks * 100)) * 100);

    cout << percentage; 
}


int main(){
    calcPercentageOfOJ();
    return 0;
}