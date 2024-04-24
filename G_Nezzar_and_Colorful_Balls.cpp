// ﷽
// problem: G. Nezzar and Colorful Balls
// URL: https://codeforces.com/group/isP4JMZTix/contest/380288/problem/G  
// Start: 4/24/2024, 4:44:34 PM
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
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int a[n], freq[n+1] = {0};
        
        int maxFreq = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            freq[a[i]]++;
            maxFreq = max(maxFreq, freq[a[i]]);
        }

        cout << maxFreq << "\n";
    }
    return 0;
}
