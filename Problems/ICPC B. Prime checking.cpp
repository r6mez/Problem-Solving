#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    long long n;
    cin >> n; 
    bool isPrime = true;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if(n%i == 0) isPrime = false;
    }   
    cout << (isPrime&&n!=1? "YES" : "NO");
    return 0;
}