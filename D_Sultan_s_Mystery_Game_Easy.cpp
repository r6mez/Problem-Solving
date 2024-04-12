// ﷽
// problem: D. Sultan's Mystery Game (Easy)
// URL: https://codeforces.com/group/EhYxAu9AgP/contest/515802/problem/D  
// Start: 4/11/2024, 7:49:02 PM
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define loop (n) for (int i = 0; i < (n); i++)
#define endl '\n'

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int sum = 0, start = 0, minDis = INT_MAX;
    for (int end = 0; end < n; end++) {
        sum += h[end];
        while (sum >= x) {
            minDis = min(minDis, end - start + 1);
            sum -= h[start++];
        }
    }

    if (minDis == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << minDis << endl;
    }
    return 0;
}
