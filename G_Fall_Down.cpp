// Ramez Medhat
// problem: G. Fall Down
// URL: https://codeforces.com/problemset/problem/1669/G  
// Start: 6/20/2024, 8:25:46 PM
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
#include <numeric>
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
    int n, m; cin >> n >> m;
    vector<string> mat;
    for (int i = 0; i < n; i++){
        string line; cin >> line;
        mat.push_back(line);
    }

    vector<vector<pair<char, int>>> newMatDetails(m);
    for (int j = 0; j < m; j++)
    {
        newMatDetails[j].push_back(make_pair('.', 0));
        for (int i = 0; i < n; i++)
        {   
            auto lastElement = newMatDetails[j].back().first;
            auto BeforeLastElement = ----(newMatDetails[j].end());
            if (mat[i][j] == '.'){
                if (lastElement == '.') newMatDetails[j].back().second++;
                else if (lastElement == 'o') newMatDetails[j].push_back(make_pair('.', 1));
                else if (lastElement == '*' && BeforeLastElement->first == '.') BeforeLastElement->second++;
            } else if (mat[i][j] == '*'){
                if (lastElement == '*') newMatDetails[j].back().second++;
                else if (lastElement == '.' || lastElement == 'o'){
                    newMatDetails[j].push_back(make_pair('.', 0));
                    newMatDetails[j].push_back(make_pair('*', 1));
                } 
            } else if (mat[i][j] == 'o'){
                if (lastElement == 'o') newMatDetails[j].back().second++;
                else if (lastElement == '*' || lastElement == '.')
                    newMatDetails[j].push_back(make_pair('o', 1));
            } 
        }
    }
    

    vector<string> newMat(m);
    for (int j = 0; j < m; j++){
        for (int i = 0; i < newMatDetails[j].size(); i++)
        {
            for (int t = 0; t < newMatDetails[j][i].second; t++)
            {
                newMat[j].push_back(newMatDetails[j][i].first);
            } 
        }               
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << newMat[j][i];
        } cout << "\n";
    }
    cout << "\n";
}

/*
NOTES:

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

/***
 * ┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
 * │Esc│   │ F1│ F2│ F3│ F4│ │ F5│ F6│ F7│ F8│ │ F9│F10│F11│F12│ │P/S│S L│P/B│  ┌┐    ┌┐    ┌┐
 * └───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘  └┘    └┘    └┘
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐ ┌───┬───┬───┬───┐
 * │~ `│! 1│@ 2│# 3│$ 4│% 5│^ 6│& 7│* 8│( 9│) 0│_ -│+ =│ BacSp │ │Ins│Hom│PUp│ │N L│ / │ * │ - │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
 * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │{ [│} ]│ | \ │ │Del│End│PDn│ │ 7 │ 8 │ 9 │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘ ├───┼───┼───┤ + │
 * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │: ;│" '│ Enter  │               │ 4 │ 5 │ 6 │   │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐     ├───┼───┼───┼───┤
 * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │< ,│> .│? /│  Shift   │     │ ↑ │     │ 1 │ 2 │ 3 │   │
 * ├─────┬──┴─┬─┴──┬┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐ ├───┴───┼───┤ E││
 * │ Ctrl│    │Alt │         Ramez         │ Alt│    │    │Ctrl│ │ ← │ ↓ │ → │ │   0   │ . │←─┘│
 * └─────┴────┴────┴───────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘ └───────┴───┴───┘
 */
