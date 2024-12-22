/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained was fields of dreamless solitude.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll   long long
#define vi   vector<int>
#define vll  vector<ll>
#define pll  pair<ll, ll>
#define all(v)  v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v){ for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v){ for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
int MOD = 1000000007;

void Ramez() {
    int n; cin >> n;
    vi a(n); cin >> a;
    int zeroz = 0;
    for (int i = 0; i < n; i++){
        if(a[i] == 0) zeroz++;
    }
    

    if(zeroz == n){
        cout << "0\n";
    } else {
        vi nodup;
        nodup.push_back(a[0]);

        for (int i = 1; i < n; i++){
            if(a[i] != a[i-1]){
                nodup.push_back(a[i]);
            }
        }

        // cout << nodup << "\n";

        int zerozInMiddle = 0;

        for (int i = 1; i < nodup.size()-1; i++)
        {
            if(nodup[i] == 0 && nodup[i-1] != 0 && nodup[i+1] != 0){
                zerozInMiddle++;
            }
        }

        if(zerozInMiddle){
            cout << "2\n";
        } else {
            cout << "1\n";
        }
    }
}

/*
NOTES:

*/

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}

