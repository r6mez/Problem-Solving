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
    while(t--){
        int a,b,c; cin >> a >> b >> c;
        if(a < b && b < c){
            cout << "STAIR\n";
        } else if (a < b && b > c) {
            cout << "PEAK\n";
        } else {
            cout << "NONE\n";
        }
    }
    return 0;
}
