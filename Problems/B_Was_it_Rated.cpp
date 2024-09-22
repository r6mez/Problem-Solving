#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vi vector<int>

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n; cin >> n;
    if(n == 15 || n == 20 || n == 21) cout << "NO"; 
    else cout << "YES";
    return 0;
}
