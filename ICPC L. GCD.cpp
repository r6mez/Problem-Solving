#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int n,x;
    cin >> n >> x;
    
    int minNumberOfTwo;
    if(n<x) minNumberOfTwo = n;
    else minNumberOfTwo = x;

    int gcd = 0;
    for (int i = 1; i <= minNumberOfTwo; i++)
    {
        if(n%i==0 && x%i==0) gcd = i;
    }

    cout << gcd;
    return 0;
}