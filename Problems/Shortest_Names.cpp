/*
    But when every equation was solved all that remained
    were fields of dreamless solitude.
*/
// Shortest Names
// URL: https://vjudge.net/problem/UVA-12506
// Time: 5/6/2025, 10:19:17 PM
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

struct node {
    vector<node*> childs;
    int cnt;
    int is_end;
    node() : childs(26, nullptr), cnt(0), is_end(0) {};
};

struct trie {
    node* root;
    trie() { root = new node(); }

    void insert(string& s) {
        node* cur_node = root;
        for (auto& c : s) {
            int ind = c - 'a';

            if (cur_node->childs[ind] == nullptr) {
                cur_node->childs[ind] = new node();
            }
            cur_node = cur_node->childs[ind];
            cur_node->cnt++;
        }
        cur_node->is_end = 1;
    }

    int query(string& s) {
        int count = 0;
        node* cur_node = root;
        for (auto& c : s) {
            int ind = c - 'a';

            if(cur_node->cnt == 1) return count;
            count++;
            cur_node = cur_node->childs[ind];
        }

        return count;
    }
};

void Ramez() {
    int n; cin >> n;

    vector<string> s(n); cin >> s;

    trie t;

    for (int i = 0; i < n; i++){
        t.insert(s[i]);
    }
    
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += t.query(s[i]);
    }
    
    cout << sum << "\n";
}

/*
NOTES:

*/

int32_t main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}