// Ramez Medhat
// problem: C. Make it Alternating
// URL: https://codeforces.com/problemset/problem/1879/C  
// Start: 7/10/2024, 7:44:48 PM
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <ranges>
using namespace std;
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>
#define all(v)  v.begin(), v.end()
#define search(vec, item) find(all(vec), item) != vec.end()
vector<vi> repGraph(int n, int m);
void dfs(int parent, vector<vi> &graph, vector<bool> &visited);
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (const auto& i : v) os << i << ' ';
    return os;
}
template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& i : v) is >> i;
    return is;
}

const int MOD = 998'244'353;

void upd(int &a, int b) {
    a = (a * 1LL * b) % MOD;
}

int t;
string s;

int main() {
	cin >> t;
	for (int tc = 0; tc < t; ++tc) {
	    cin >> s;
	    int res = 1;
	    int k = s.size();
	    int n = s.size();
	    for (int l = 0; l < n; ) {
	        int r = l + 1;
	        while(r < n && s[l] == s[r])
	            ++r;
            upd(res, r - l);
            --k;
            l = r;
	    }
	    
	    for (int i = 1; i <= k; ++i)
	        upd(res, i);
        cout << k << ' ' << res << endl;
	}
}