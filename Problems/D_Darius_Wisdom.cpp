/*
    I thought I could bring an end to the world's suffering,
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// D. Darius' Wisdom
// URL: https://codeforces.com/problemset/problem/2034/D
// Time: 4/10/2025, 2:57:53 PM
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

// This solution uses three sets to track indices with values 0, 1, and 2.
// The allowed operations are:
//   - If there is a 1 that comes before a 0 (i.e. min index in pos1 < max index in pos0),
//     then transfer one inscription from that column with 1 to the column with 0. 
//     In effect, that swaps the two values (1 becomes 0 and 0 becomes 1).
//   - Else, if there is a 2 that comes before a 1 (i.e. min index in pos2 < max index in pos1),
//     then transfer one inscription from that column with 2 to the column with 1.
// If neither inversion exists, the array is already sorted in non-decreasing order.
 
void Ramez() {
    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    
    // Ordered sets for indices where a[i]==0, 1, 2.
    set<int> pos0, pos1, pos2;
    for (int i = 0; i < n; i++){
        if(a[i] == 0)
            pos0.insert(i);
        else if(a[i] == 1)
            pos1.insert(i);
        else // a[i]==2
            pos2.insert(i);
    }
    
    // We'll store the moves as pairs (u, v)
    // where the move means: transfer one inscription from column u to column v.
    // (Indices are output in 1–indexed form.)
    vector<pii> ops;
    ops.reserve(n);
    
    // We'll repeat while an inversion exists.
    // Inversions: a valid inversion is either:
    // (i) a 1 that occurs before a 0, i.e., *pos1.begin() < *pos0.rbegin()
    // or (ii) a 2 that occurs before a 1, i.e., *pos2.begin() < *pos1.rbegin()
    while ( true ) {
        bool moved = false;
        // Check for a (1,0) inversion.
        if (!pos1.empty() && !pos0.empty() && (*pos1.begin() < *pos0.rbegin())) {
            int idx1 = *pos1.begin();   // earliest index that contains a 1
            int idx0 = *pos0.rbegin();    // latest index that contains a 0
            
            // Allowed move: since a[idx1]==1 and a[idx0]==0 and 1 - 0 = 1,
            // we transfer one inscription from the column with 1 to the column with 0.
            // That causes a[idx1] to become 0 and a[idx0] to become 1.
            ops.push_back({idx1+1, idx0+1});
            a[idx1] = 0;
            a[idx0] = 1;
 
            // Update the sets:
            pos1.erase(idx1);
            pos0.erase(idx0);
            pos0.insert(idx1);
            pos1.insert(idx0);
            moved = true;
        }
        // Else, check for a (2,1) inversion.
        else if (!pos2.empty() && !pos1.empty() && (*pos2.begin() < *pos1.rbegin())) {
            int idx2 = *pos2.begin();   // earliest index that contains a 2
            int idx1 = *pos1.rbegin();    // latest index that contains a 1
 
            // Allowed move: since a[idx2]==2 and a[idx1]==1 (and 2-1=1),
            // we transfer one inscription from the column with 2 to the column with 1.
            // That causes a[idx2] to become 1 and a[idx1] to become 2.
            ops.push_back({idx2+1, idx1+1});
            a[idx2] = 1;
            a[idx1] = 2;
 
            // Update the sets accordingly:
            pos2.erase(idx2);
            pos1.erase(idx1);
            pos1.insert(idx2);
            pos2.insert(idx1);
            moved = true;
        }
 
        if (!moved)
            break;
 
        // (No explicit move count check is needed because the problem guarantees a solution
        // in at most n moves, and our updates run in O(log n) each.)
    }
    
    // Output the sequence of moves.
    cout << ops.size() << "\n";
    for(auto [u, v] : ops)
        cout << u << " " << v << "\n";
}

/*
0 0 1 1 2 2


NOTES:
0 2 0 1
-     -
0 2 0 1
  -   -

0 1 0 2
  -   -

0 1 0 2
  - -

0 1 0 2

2 2 1 2 0 0

2 2 0 2 0 1
1 2 0 2 0 2
0 2 0 2 1 2
0 1 0 2 2 2
0 0 1 2 2 2

2 2 1 2 0 0
1 2 2 2 0 0
0 2 2 2 0 1
0 1 2 2 0 2
0 0 2 2 1 2
0 0 1 2 2 2

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}