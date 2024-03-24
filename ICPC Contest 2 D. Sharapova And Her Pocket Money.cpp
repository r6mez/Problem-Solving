#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    long long numberOfDays, money;
    cin >> numberOfDays >> money;
    while(numberOfDays--){
        char operation;
        long long newMoney;
        cin >> operation >> newMoney;
        if (operation == '+'){
            money += newMoney;
        } else {
            if(money >= newMoney) money -= newMoney;
        }
    }

    cout << money;
    return 0;
}