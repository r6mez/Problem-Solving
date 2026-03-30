#include "bits/stdc++.h"
#define int long long
using namespace std;

vector<int> zFunction(const string &s) {
  int n = s.size();
  vector<int> z(n, 0);
  z[0] = n;
  int l = 0, r = 0;
  for (int i = 1; i < n; i++) {
    if (i < r)
      z[i] = min(r - i, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]])
      z[i]++;
    if (i + z[i] > r)
      l = i, r = i + z[i];
  }
  return z;
}

string shortestRepeatingSubstring(const string &s) {
  int n = s.size();
  vector<int> z = zFunction(s);

  for (int sz = 1; sz <= n; sz++) {
    if (n % sz != 0)
      continue;

    bool valid = true;
    for (int k = 1; k < n / sz; k++) {
      if (z[k * sz] < sz) {
        valid = false;
        break;
      }
    }

    if (valid)
      return s.substr(0, sz);
  }

  return s;
}

int sum = 0;
void process(int a, int b) {
  for (int x = a; x <= b; x++) {
    string s = to_string(x);
    int n = s.length();
    string t = shortestRepeatingSubstring(s);
    if (t != s) {
      sum += x;
    }
  }
}

signed main() {
  freopen("file.in", "r", stdin);
  freopen("file.out", "w", stdout);

  char dash, comma;
  int a, b;
  while (cin >> a >> dash >> b >> comma) {
    process(a, b);
  }

  process(a, b);

  cout << sum << "\n";
  return 0;
}