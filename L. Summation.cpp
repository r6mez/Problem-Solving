#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vi vector<int>

void printSum(int n, ll sum = 0){
    if(n == 0) {
        cout << sum;
        return;
    }
    ll num; cin >> num;
    sum += num;
    printSum(n-1, sum);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    printSum(n);
    return 0;
}
