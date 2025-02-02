/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
// J. smallest subsequence
// URL: https://codeforces.com/group/E23MsQv91X/contest/323789/problem/J
// Time: 1/27/2025, 12:42:10 PM
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi   vector<int>
#define pii  pair<int, int>
#define all(v)  v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
int  dx[] = { -1,   1,   0,   0 }; int  dy[] = { 0,   0,  -1,   1 }; char dir[] = { 'U', 'D', 'L', 'R' };
int MOD = 1000000007;


void Ramez() {
    string s; cin >> s;

    map<char, int> freq;
    for (int i = 0; i < s.size(); i++){
        freq[s[i]]++;
    }
    

    stack<char> x; x.push(s[0]); freq[s[0]]--;

    for (int i = 1; i < s.size(); i++){
        cout << freq[x.top()] << " " << s[i] << "\n";
        if(freq[x.top()] && x.top() >= s[i]){
            x.pop();
        } 
        x.push(s[i]);
        freq[s[i]]--;
    }
    
    string newS = "";

    while(!x.empty()){
        newS.push_back(x.top());
        x.pop();
    }

    reverse(all(newS));
    
    cout << newS << "\n";
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

