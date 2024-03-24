#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vi vector<int>

ll printSumOfLastM(int n, int m){
    if(n == 0) return 0;
    ll num; cin >> num;
    ll sum = num + printSumOfLastM(n-1, m);
    if(m == n) cout << sum;
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; cin >> n >> m;
    printSumOfLastM(n,m);
    return 0;
}