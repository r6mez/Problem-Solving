// ﷽
// problem: C. Sultan Loves Subsequences
// URL: https://codeforces.com/group/EhYxAu9AgP/contest/515802/problem/C  
// Start: 4/11/2024, 7:10:26 PM

/* NOT SOLVED */

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

bool isSubstring(const string &s, const string &p) {
    if (p.empty() || s.size() < p.size()) {
        return false;
    }

    for (size_t i = 0; i <= s.size() - p.size(); ++i) {
        if (s.substr(i, p.size()) == p) {
            cout << s.substr(i, p.size()) << " ";
            return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    int q; cin >> q;
    string p = "";
    while(q--){
        string op; char c;
        cin >> op;
        if(op == "push"){
            cin >> c;
            p.push_back(c);
        } else {
            p.pop_back();
        }
        if(isSubstring(s, p)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
/*
abcaaaaa
1
deleted 
added   a

if it is less than 0 and 
*/