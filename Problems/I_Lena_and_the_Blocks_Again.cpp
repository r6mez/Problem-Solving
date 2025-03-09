/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// I. Lena and the Blocks, Again
// URL: https://codeforces.com/group/3nQaj5GMG5/contest/376466/problem/I
// Time: 3/9/2025, 4:12:27 PM
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
    int n; cin >> n;
    vi towers(n); cin >> towers;
    
    int max = *max_element(all(towers)), min = *min_element(all(towers));
 
    vector<int> indeces;
    
    for (int i = 0; i < n; i++){
        if(towers[i] == max || towers[i] == min) indeces.push_back(i);
    }

    int changed = false, minLength = INT_MAX;
    for (int i = 0; i < indeces.size()-1; i++){
        int diff = (indeces[i+1] - indeces[i]);
        if(minLength > diff && towers[indeces[i+1]] != towers[indeces[i]]){
            minLength = diff;
            changed = true;
        } 
    }
    cout << (changed? minLength : 0) << endl;
}

/*
NOTES:
Changed to avoid this test case
5
1 1 1 1 1
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}