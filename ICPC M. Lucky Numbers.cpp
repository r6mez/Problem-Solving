#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);

    int n1, n2;
    cin >> n1 >> n2;

    int theresPrimeNumbers = false;

    for (int i = n1; i <= n2 ; i++)
    {
        string number = to_string(i);
        bool isPrime = true;
        for (int j = 0; j < number.length(); j++)
        {
            if(number[j] != '4' && number[j] != '7') isPrime = false;
        };
        if(isPrime) {
            cout << number << " ";
            theresPrimeNumbers = true;
        }
    }

    if(!theresPrimeNumbers) cout << -1;
    
    return 0;
}