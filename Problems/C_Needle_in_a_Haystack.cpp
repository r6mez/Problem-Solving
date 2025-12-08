/*
  But there's something kind of fantastic about that.
*/
// C. Needle in a Haystack
// URL: https://codeforces.com/contest/2175/problem/C
// Time: 12/7/2025, 3:55:19 PM
#include <bits/stdc++.h>
using namespace std;
#define int         long long
#define vi          vector<int>
#define pii         pair<int, int>
#define all(v)      v.begin(), v.end()
#define finish(s)   { cout << s << "\n"; return; }
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007, INF = 2e18;

void solve() {
    string s, t; cin >> s >> t;
    map<char, int> mt;
    
    for(char c : t) mt[c]++;
    
    for(char c : s){
        if(mt[c]){
            mt[c]--;
        } else 
            finish("Impossible"); 
    }
    
    t = "";
    for(auto [c, f] : mt){
        t += string(f, c);
    }

    // cout << "----\n" << s << "\n" << t << "\n" << "----\n";

    string answer = "";
    int j = 0, i = 0;
    while(i < t.size()){
        if(j < s.size())
            if(t[i] < s[j]) answer += t[i++];
            else answer += s[j++];
        else 
            answer += t[i++];
    }

    while(j < s.size())
        answer += s[j++];
        
    
    cout << answer << "\n";
}

/*

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}