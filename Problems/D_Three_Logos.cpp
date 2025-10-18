/*
    One day, I'm gonna grow wings
*/
// D. Three Logos
// URL: https://codeforces.com/problemset/problem/581/D
// Time: 10/8/2025, 9:10:29 PM
#include <bits/stdc++.h>
using namespace std;
#define int         long long
#define vi          vector<int>
#define pii         pair<int, int>
#define all(v)      v.begin(), v.end()
#define finish(s)   { cout << s << "\n"; return; }
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
void FastIO() { cin.tie(nullptr)->sync_with_stdio(false); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
const int MOD = 1000000007, INF = 2e18;

struct point {
	int x, y;
	char ch;

	void print(void) {
		for (int i = 0; i < this->y; i++) {
			for (int j = 0; j < this->x; j++) cout << this->ch;
			cout << '\n';
		}
	}
};

void solve(void) {
	point a, b, c;

	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
	a.ch = 'A';
	b.ch = 'B';
	c.ch = 'C';

	// Rotate logos to reduce the amount of casework
	// Longer side = x, shorter side = y
	if (a.x < a.y) swap(a.x, a.y);
	if (b.x < b.y) swap(b.x, b.y);
	if (c.x < c.y) swap(c.x, c.y);

	// First case: all 3 have the same width, so try to place them one under the other
	if (a.x == b.x && a.x == c.x) {
		if (a.y + b.y + c.y == a.x) {  // If they actually form a square
			cout << a.x << "\n";

			a.print();
			b.print();
			c.print();

		} else {
			cout << "-1\n";
		}
		return;
	}

	// Let a be the logo with the largest x
	if (c.x > b.x) swap(b, c);
	if (b.x > a.x) swap(a, b);

	int remaining_y = a.x - a.y;
	// Rotate them as needed
	if (b.x == remaining_y) swap(b.x, b.y);
	if (c.x == remaining_y) swap(c.x, c.y);

	if (b.x + c.x == a.x && c.y == remaining_y && b.y == remaining_y) {
		cout << a.x << "\n";
		a.print();

		for (int i = 0; i < b.y; i++) {
			for (int j = 0; j < b.x; j++) cout << b.ch;
			for (int j = 0; j < c.x; j++) cout << c.ch;
			cout << '\n';
		}
		return;
	}

	cout << "-1\n";
}

/*

*/

signed main() {
    // UseFile();
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
}