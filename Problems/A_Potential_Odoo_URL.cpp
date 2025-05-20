/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// A. Potential Odoo URL
// URL: https://codeforces.com/group/1i1EfhEv7s/contest/611029/problem/0
// Time: 5/20/2025, 8:31:20 PM
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

void Ramez() {
    string s; cin >> s;
    string subdomain = "";

    for (int i = 0; i < s.size(); i++){
        if (s[i] == '.'){
            break;
        }
        subdomain += s[i];
    }

    if(subdomain.size() < 4 || subdomain.size() > 30){
        cout << "No" << endl;
        return;
    }

    if(s.substr(subdomain.size()) != ".odoo.com"){
        cout << "No" << endl;
        return;
    }

    if(subdomain[0] == '-' || subdomain[subdomain.size() - 1] == '-'){
        cout << "No" << endl;
        return;
    }

    int dotsCount = 0;
    for (int i = 0; i < subdomain.size(); i++){
        if(islower(subdomain[i]) || isdigit(subdomain[i]) || subdomain[i] == '-'){
            continue;
        } 
        else{
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}