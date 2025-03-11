#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vi vector<int>

void printMax(int n, ll Max = LONG_LONG_MIN){
    if(n == 0) {
        cout << Max;
        return;
    }
    ll num; cin >> num;
    Max = max(Max, num);
    printMax(n-1, Max);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    printMax(n);
    return 0;
}
