/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// B. Variety is Discouraged
// URL: https://codeforces.com/contest/2064/problem/B
// Time: 2/16/2025, 4:42:41 PM
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
int MOD = 1000000007;

void Ramez() {
    int n; cin >> n;
    vi a(n); cin >> a;
    map<int, int> f;

    if(n == 1) {
        cout << "1 1\n";
        return;
    }

    int dups = 0;
    for (int i = 0; i < n; i++){
        f[a[i]]++;
        if(f[a[i]] == 2) dups++;
    }
    
    if(f.size() == 1 || dups == f.size()) {
        cout << "0\n";
        return;
    }

    int maxl = 0, maxr = 0, maxLen = 0;

    int l = 0, r = 0, len = 0;

    for (int i = 0; i < n; i++){
        if(f[a[i]] > 1) {
            if(maxLen < len){
                maxl = l;
                maxr = r;
                maxLen = len;
            }
            len = 0;
        }
        else {
            if(len == 0){
                l = i; 
            }
            r = i;
            len++;
        }
    }

    if(maxLen < len){
        maxl = l;
        maxr = r;
        maxLen = len;
    }

    cout << maxl+1 << " " << maxr+1 << "\n";
}

/*
NOTES:
if all elements are eq or duplicates
deletion of any element will decrease the score
answer is 0 
--------------

score = n - distinct a[i]

can we increse it ?????
removing dups -> n-- , distinct not affected, score decrease 
removing distinct -> n--, distinct--, score constant, size decrease

in any case we can't increse the score
so we will try not to decrease it.

what is the longest subsegment that can be removed
without changing the score 

what if 1 2 3 4 4 4
score 6 - 4 = 2
remove 1, 2, 3
score 3 - 1 = 2

what if 1 2 2 3 4 5 5 
score = 7 - 5 = 2
remove  3, 4 score 5 - 3 = 2 (best)
remove 1 score 6 - 4 = 2

what if 1 2 2 3 4 5 6 7 7
score = 9 - 7 = 2
remove 3, 4 , 5 ,6 score = 5 - 3 = 2

so we remove max segment of distinct numbers of length
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}

