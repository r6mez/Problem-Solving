#include <iostream> 
#include <vector>
#include <sstream>
using namespace std;

void countYears(){
    int limak,bob;
    cin >> limak >> bob;

    int years = 0;

    while(limak <= bob){
        limak = limak * 3;
        bob = bob * 2;

        years++;
    }

    cout << years;
}


int main(){
    countYears();
    return 0;
}