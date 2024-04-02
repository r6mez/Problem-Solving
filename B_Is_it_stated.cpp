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
        string s;
        cin >> s;
        if(s.find("it") == string::npos){
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}
