#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int n;
    cin >> n; 
    bool isPrime = true;
    for (int i = 2; i < n; i++)
    {
        if (n%i==0) isPrime = false;
    }

    isPrime? cout << "YES" : cout << "NO";
    return 0;
}