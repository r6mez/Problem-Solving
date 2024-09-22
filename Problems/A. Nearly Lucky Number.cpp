#include <iostream> 
#include <vector>
#include <sstream>
using namespace std;

void checkNearlyLuckyNumber(){
    string number;
    cin >> number;

    int luckyNumbers = 0;
    for (int i = 0; i < number.length(); i++)
    {
        if(number[i] == '4' || number[i] == '7'){
            luckyNumbers++;
        }
    }

    if(luckyNumbers == 4 || luckyNumbers == 7) cout << "YES";
    else cout << "NO";
}

int main(){
    checkNearlyLuckyNumber();
    return 0;
}