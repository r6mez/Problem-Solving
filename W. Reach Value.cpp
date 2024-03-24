#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vi vector<int>

ll n;

bool check(ll result = 1){
    if(result >= n){
        return (n == result);
    }
    return (check(result * 10) || check(result * 20));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--){
        cin >> n;
        cout << (check()? "YES\n" : "NO\n");
    }
    return 0;
}
