/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all it remained were fields of dreamless solitude.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll   long long
#define vi   vector<int>
#define vll  vector<ll>
#define pll  pair<ll, ll>
#define all(v)  v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
int MOD = 1000000007;

void Ramez() {
    string s; cin >> s;
    ll pos; cin >> pos;

    // this normalizez the value to the last string added 
    // and calculates the total removed from this string
    ll removed = 0, size = s.size(), currentSize = size, newSize = size;
    while (newSize < pos) {
        currentSize--;
        newSize += currentSize;
        removed++;
    }

    pos -= (newSize - currentSize);


    // remove these letters from the string which makes it lexo smallest
    
    stack<char> st;
    for (int i = 0; i < size; i++) {
        bool pushed = false;
        while (!st.empty() && removed) {
            if (s[i] < st.top()) {
                st.pop();
                removed--;
            } else {
                st.push(s[i]);
                pushed = true;
                break;
            }
        }
        if(!pushed) st.push(s[i]);
    }

    string newS = "";
    while(!st.empty()){
        newS += st.top();
        st.pop();
    }

    reverse(all(newS));

    cout << newS[pos-1];
}

/*
NOTES:
cab
cababa
removed = 2
pos = 1
a


abcd
abcdabcaba
removed = 2
pos = 2
ab


x
x
removed = 0
pos = 1
x

ssu
ssusss
removed = 2
pos = 2
ss
*/

int main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}

