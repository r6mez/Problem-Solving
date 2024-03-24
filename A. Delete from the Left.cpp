#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vi vector<int>



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s,t;
    cin >> s >> t;
    string smaller, bigger;
    if(s.size() >= t.size()){
        smaller = t; bigger = s;
    } else {
        bigger = t; smaller = s;
    }
    int moves = 0;
    for (int i = 0; i < bigger.size(); ++i) {
        if(bigger[0] != smaller[0]) {
            bigger.erase(0);
        }
    }
    return 0;
}
