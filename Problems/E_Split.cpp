/*
    One day, I'm gonna grow wings
*/
// E. Split
// URL: https://codeforces.com/problemset/problem/2148/E
// Time: 11/5/2025, 9:37:37 PM
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
    int n, k; cin >> n >> k;
    vi a(n); cin >> a;
    map<int, int> freq;
    for(int x : a) freq[x]++;

    for(auto &[x, f] : freq) {
        if(f % k == 0){
            f /= k;
        } else finish(0);
    }

    // now freq contains this maximum subarray content
    // we need to make another freq to count the subarrays

    map<int, int> currFreq;
    int l = 0, r = 0;
    currFreq[a[l]]++;
    int count = 1;

    while(l < n - 1 && r < n - 1){
        if(currFreq[a[r + 1]] < freq[a[r + 1]]){
            r++;
            currFreq[a[r]]++;
            count += r - l + 1;
        } else {
            currFreq[a[l]]--;
            l++;    
        }
    }

    cout << count << "\n";
}

/*
freq of each number can be dividied by k
the devision will give us the contents of each mutliset
a subset a[l..r] can't contain more than this content

do a two pointers l, r
each new vaild element adds a (r - l + 1)  

3 3 3 3

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}