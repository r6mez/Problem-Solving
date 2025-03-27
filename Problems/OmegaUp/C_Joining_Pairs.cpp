/*
I tought I could bring an end to the world suffering,
But when every equation was solved
all that remained were fields of dreamless solitude.
*/
// C. Joining Pairs
// URL: https://omegaup.com/arena/gsoc2025/practice/#problems/ICPCMX2021-Joining-Pairs
// Time: 3/3/2025, 11:03:54 PM
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

struct pt {
    double flag;
    int i;
};

void Ramez() {
    int w, h; cin >> w >> h;
    int n; cin >> n;
    vector<pt> pts;

    auto onEdge = [&](int x, int y) {
        return (x == 0 || x == w || y == 0 || y == h);
    };

    function<double(int, int)> makeFlag = [&](int x, int y) -> double {
        if (y == 0) return x;
        if (x == w) return w + y;
        if (y == h) return w + h + (w - x);
        return 2 * w + h + (h - y);
    };

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2; 
        cin >> x1 >> y1 >> x2 >> y2;
        if (onEdge(x1, y1) && onEdge(x2, y2)) {
            pts.push_back({ makeFlag(x1, y1), i });
            pts.push_back({ makeFlag(x2, y2), i });
        }
    }

    if (pts.empty()) {
        cout << "Y\n";
        return;
    }
    
    sort(pts.begin(), pts.end(), [](const pt& a, const pt& b) { 
        return a.flag < b.flag; 
    });

    int k = pts.size();
    int perimeter = 2 * w + 2 * h;
    
    double bestGap = -1;
    int bestIndex = 0;
    for (int i = 0; i < k - 1; i++) {
        double gap = pts[i + 1].flag - pts[i].flag;
        if (gap > bestGap) {
            bestGap = gap;
            bestIndex = i + 1;
        }
    }

    double gap = pts[0].flag + perimeter - pts[k - 1].flag;
    if (gap > bestGap) {
        bestGap = gap;
        bestIndex = 0;
    }
    
    stack<int> st;
    for (int j = 0; j < k; j++) {
        int idx = (bestIndex + j) % k;
        if (!st.empty() && st.top() == pts[idx].i) st.pop();
        else st.push(pts[idx].i);
    }
    
    cout << (st.empty() ? "Y" : "N") << "\n";
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

