#include <iostream>
#include <cmath>
using namespace std;

string isPrime(long long n){
    if(n == 1) return "NO";
    for (int i = 2; i <= sqrt(n); i++)
    {
        if(n%i == 0) return "NO";  
    }
    return "YES";
    
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long n; 
        cin >> n;
        cout << isPrime(n) << "\n";
    }
    return 0;
}