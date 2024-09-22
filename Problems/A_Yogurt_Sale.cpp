#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vi vector<int>

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--){
        int n, a, b; cin >> n >> a >> b;
        int priceWithoutProm = n*a;
        int priceWithProm = (n%2)*a + ((n-(n%2))/2)*b;
        // cout << priceWithoutProm << " " << priceWithProm << "\n";
        cout << min(priceWithoutProm, priceWithProm) << "\n";
    }
    return 0;
}
