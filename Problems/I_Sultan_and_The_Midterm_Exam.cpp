// ﷽
// problem: I. Sultan and The Midterm Exam
// URL: https://codeforces.com/group/EhYxAu9AgP/contest/515802/problem/I  
// Start: 4/11/2024, 8:20:07 PM
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
    map<char, int> freq;
    freq['a'] = 0;
    freq['b'] = 0;
    freq['c'] = 0;
    freq['d'] = 0;
    freq['e'] = 0;

    for(char c : s) {
        freq[c]++;
    }
    
    int max_freq = 0;
    int min_freq = INT_MAX;
    for(auto &p : freq) {
        max_freq = max(max_freq, p.second);
        min_freq = min(min_freq, p.second);
    }
    
    cout << min_freq << ' ' << max_freq << endl;
    return 0;
}