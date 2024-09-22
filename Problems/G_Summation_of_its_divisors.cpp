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
    ll sum = 0;
    for (ll i = 1; i <= sqrt(n); i++)
    {
        if(n%i==0){
            sum += i;
            if(n/i != i) sum += n/i;
        }
    }
    cout << sum;
    return 0;
}

// 1 3 9