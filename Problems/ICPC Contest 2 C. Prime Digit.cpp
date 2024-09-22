#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);

    long long number;
    cin >> number;

    int primeDigits = 0;
    while(number != 0){
        int digit = number % 10;
        number = number / 10;
        switch (digit)
        {
            case 2:
            case 3:
            case 5:
            case 7:
                primeDigits++;
                break;
        }
    }
    
    cout << primeDigits;
    return 0;
}