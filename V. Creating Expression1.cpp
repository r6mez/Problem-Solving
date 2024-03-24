#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll sizee, goal;
ll a[21];

bool isPossible(ll i = 0, ll sum = 0){
    if (i == sizee) return sum == goal;
    return (isPossible(i + 1, sum + a[i]) ||
        isPossible(i + 1, sum - a[i]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> sizee >> goal;
    for (int i = 0; i < sizee; ++i) {
        cin >> a[i];
    }
    cout << (isPossible(1,a[0])? "YES" : "NO");
    return 0;
}
