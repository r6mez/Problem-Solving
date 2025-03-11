#include <iostream> 
using namespace std;


void countElphantSteps(){
    int distance;
    cin >> distance;

    int steps = 0;
    int remainder = 0;
    int stepDistance = 5;

    while (distance > 0){
        if(distance >= stepDistance) remainder = distance % stepDistance;
        else {
            stepDistance--;
            continue;
        }
        distance = distance - remainder;
        steps = steps + (distance / stepDistance);
        distance = remainder;
        stepDistance--;
    }

    cout << steps;
}

int main(){
    countElphantSteps();
    return 0;
}