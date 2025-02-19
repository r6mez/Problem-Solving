/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// A. Snacktower
// URL: https://codeforces.com/contest/767/problem/A
// Time: 2/17/2025, 2:50:55 PM
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

    set<int> available;
    map<int, bool> printed;

    for (int i = 0; i < n; i++){
        available.insert(a[i]);

        if(a[i] == n || (available.count(a[i] + 1) && printed[a[i] + 1])) {
            cout << a[i] << " ";
            printed[a[i]] = true;

            int x = 1; // to search for smaller candies
        
            while(available.count(a[i] - x) == 1){
                cout << a[i] - x << " ";
                printed[a[i] - x] = true;
                x += 1;
            }
        }

        cout << "\n";
    }
}

/*
NOTES:
We simply need to keep track of what we have

so when we get a[i] we check two things
1. is a[i] + 1 available and did we print it? if so we print a[i]
2. if (1) happens -> we ask do we have candies that a[i] - 1, a[i] - 2 etc ?? ... we print them all until a[i] - x isn't available.

we will use a set to do this quick search.
and we will use a map to check if a number is printed or not

set and map allows us to search and access elements of in O(logN)
*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) Ramez();
    return 0;
}

