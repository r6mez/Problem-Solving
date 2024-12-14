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
    int n, k, m; cin >> n >> k >> m;
    string s; cin >> s;
    string edge = "";
    vector<bool> found(k, false);
    int counter = 0;
    for(char c : s){
        if(edge .size() == n){
            break;
        }

        counter += (!found[c - 'a']);
        found[c-'a'] = true;

        if(counter == k){
            for (int i = 0; i < k; i++){
                found[i] = false;
            }
            
            counter = 0;
            edge += c;
        }
    }

    if(edge.size() == n){
        cout << "YES\n";
    } else {
        cout << "NO\n";
        for (int i = 0; i < k; i++){
            if(!found[i]){
                while(edge.size() < n){
                    edge += ('a' + i);
                }
            }
        }
        cout << edge << "\n";
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

