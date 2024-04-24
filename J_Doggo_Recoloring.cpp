// ﷽
// problem: J. Doggo Recoloring
// URL: https://codeforces.com/group/isP4JMZTix/contest/380288/problem/J  
// Start: 4/24/2024, 6:16:57 PM
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
    int n; cin >> n;
    string s; cin >> s;
    int freq[200] = {0};
    for (int i = 0; i < n; i++)
    {
        freq[s[i]]++;
    }

    bool isPos = false;
    for (int i = 'a'; i <= 'z'; i++)
    {
        if(freq[i] >= 2) {
            isPos = true;
            break;
        }
    }

    cout << ((isPos || n == 1)? "Yes" : "No");
    return 0;
}
