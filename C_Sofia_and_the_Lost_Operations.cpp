// ﷽
// problem: C. Sofia and the Lost Operations
// URL: https://codeforces.com/contest/1980/problem/C  
// Start: 6/3/2024, 6:05:11 PM
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
using namespace std;
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>
#define all(v)  v.begin(), v.end()

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for(const auto& i : v) os << i << ' ';
    return os;
}
 
template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for(auto& i : v) is >> i;
    return is;
}

void solve(){
    int n; cin >> n;
    map<int,int> freqA, freqB, freqD;
    vi a(n), b(n); 
    for (int i = 0; i < n; i++){
        cin >> a[i]; 
        freqA[a[i]]++;
    }
    for (int i = 0; i < n; i++){
        cin >> b[i]; 
        freqB[b[i]]++;
    }
    

    int m; cin >> m;
    vi d(m);
    int sum = 0;
    for (int i = 0; i < m; ++i) {
        cin >> d[i];
        freqD[d[i]]++;
        if(freqB[d[i]] == 0) sum++;
        else if(freqB[d[i]] > 0 && sum > 0) sum = 0; 
    }
    bool pos = true;
    map<int, int> required;

    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            required[b[i]]++;
        }
    }
    
    for (auto [value, count] : required) {
        if (freqD[value] < count) {
            pos = false;
            break;
        }
    }

    if (pos && sum == 0) cout << "YES\n";
    else cout << "NO\n";
}

/*
NOTES:
4
3 1 7 8
2 2 7 10
5
10 3 2 2 1

1
1
1
5
1 3 4 5 1

not valid d -> (number in d and not in b)
if a not valid element in d has no valid element after it (YES)
else (NO)
*/

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t = 1; 
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}