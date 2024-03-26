#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vi vector<int>

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    ll n; cin >> n;
    ll x = n; 
    vll freq(n+1,0);
    ll factor = 2;

    while (x != 1)
    {
        if(x%factor == 0){
            freq[factor]++;
            x = x/factor;
        } else {
            factor++;
        }
    }
    

    bool isFirstPrint = true;
    for (ll i = 0; i <= n; i++)
    {
        
        if(freq[i] > 0){
            if(!isFirstPrint) cout << "*"; 
            cout << "(" << i << "^" << freq[i] <<")";
            isFirstPrint = false;
        }
    }  
    return 0;
}
