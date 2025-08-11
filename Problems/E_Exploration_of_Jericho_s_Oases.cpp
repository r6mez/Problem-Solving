#include <bits/stdc++.h>
using namespace std;
#define double long double
#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007;

struct point {
    double x, y;

    friend istream &operator>>(istream &in, point &p) {
        return in >> p.x >> p.y;
    }
};

double slope(point a, point b){
    return (a.y - b.y)/(a.x - b.x);
}

double toDegree(double angle){
    const double pi = acos(-1);
    return ((180.0 * angle)) / pi;
}

void Ramez() {
    point a, b, c, t; cin >> a >> b >> c >> t;
    int movable; cin >> movable;
    if(movable == 1){
        swap(a, b);
    }

    double theta = toDegree(atan(abs((slope(b, c) - slope(t, a)) / (1 + slope(b, c) * slope(t, a))))); // between target and constant (b -> c)
    double alpha = toDegree(atan(slope(b, a) - slope(t, a))); // between target and movable (b -> a)
    
    cout << theta << "\n" << alpha << "\n";
    if(theta > 90) {
        cout << "NO\n";
        return;
    }
    
    double answer = abs(2 * theta - alpha);
    
    // if()
    
    // cout << answer << "\n";
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