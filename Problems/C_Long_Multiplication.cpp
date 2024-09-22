// ﷽
// problem: C. Long Multiplication
// URL: https://codeforces.com/contest/1954/problem/C  
// Start: 4/12/2024, 5:59:55 PM
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
    while(t--){
        string s1, s2;
        cin >> s1 >> s2;
        if (s1 < s2) {
            swap(s1, s2);
        }
        string st1 = s1, st2 = s2;
        for (size_t i = s1.size() - 1; i > 0; i--) {
            swap(st1[i], st2[i]);
            if (st1 < s1 && st2 > s2 && st1 > st2) {
                swap(s1[i], s2[i]);
            } else {
                swap(st1[i], st2[i]);
            }
        }
        cout << s1 << "\n" << s2 << "\n";
    }
    return 0;
}
