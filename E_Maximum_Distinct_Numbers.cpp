#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vi vector<int>

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll sum = 1;
    ll counter = 1;
    while (sum + counter+1 <= n){
        counter++;
        sum = sum + counter;
    }
    cout << counter;
    return 0;
}
