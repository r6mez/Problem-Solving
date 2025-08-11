#include <bits/stdc++.h>
using namespace std;
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;


void solve() {
    string s;cin>>s;
    int res=(s.size()-1)*10;
    for(int i=1;i<10;i++){
        string tmp="";
        for(int j=0;j<s.size();j++){
            tmp+=(i+'0');
        }
        if(stoll(s)>=stoll(tmp))res++;
        else break;
    }   
    cout<<res;
}

/*

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
   // cin >> t;
    while (t--) solve();
    return 0;
}