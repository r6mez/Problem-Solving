#include <bits/stdc++.h>
#define ll   long long
#define vi   vector<int>
#define vll  vector<ll>
using namespace std;
#define all(v)  v.begin(), v.end()
void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
void UseFile() { freopen("file.in", "r", stdin); freopen("file.out", "w", stdout); }
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    for (const auto& i : v) os << i << ' ';
    return os;
}
template<typename T> istream& operator>>(istream& is, vector<T>& v){
    for (auto& i : v) is >> i;
    return is;
}

// A
void Ramez(){
  int n; cin >> n;
  vi a(n); 
  cin >> a;

  int counter = 0;
  for (int i = 1; i < n-1; i++) {
    if(a[i] > a[i-1] && a[i] > a[i+1]){
      counter++; 
    }
  }

  cout << counter << "\n";
}


// B
void Ramez(){
  int n; cin >> n;
  vi a(n); cin >> a;
  int sHeight, zHeight; cin >> sHeight >> zHeight;

  int sCounter = 0, zCounter = 0;
  for (int i = 0; i < n; i++) {
    if(a[i] < sHeight) break;
    sCounter++;
  } 

  int counter = 0;
  for (int i = 0; i < n; i++) {
    if(a[i] < zHeight) {
      counter = 0;
      continue;
    }

    counter++;
    zCounter = max(counter, zCounter);
  }

  cout << sCounter << "\n" << zCounter << "\n";
  if(sCounter > zCounter) cout << "ShaFeiii";
  else if(sCounter < zCounter) cout << "Zeyad";
  else cout << "draw"; 
}

// C
void Ramez(){
  int n; cin >> n;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    sum += x;
  }

  double sq = sqrt(sum);
  ll notFraction = sq;

  if(sq == notFraction){
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}


// D
void Ramez(){
  ll n; cin >> n;
  vll a(n); cin >> a;
  sort(all(a));
  a[0]++;
  ll ans = 1;
  for (int i = 0; i < n; i++) {
    ans *= a[i];
  }
  cout << ans << "\n";
}


// E 
void Ramez(){
  int a, b, x, y; cin >> a >> b >> x >> y;
  if(a == y) y--;
  cout << a << " " << y << "\n";
}

// F 
void Ramez(){
  int n; cin >> n;
  vi a(n), b(n); cin >> a >> b;
  for (int i = 0; i < n; i++) {
    if((a[i] > a[n-1] || b[i] > b[n-1]) && (b[i] > a[n-1] || a[i] > b[n-1])){
      cout << "No\n";
      return;
    }
  }

  cout << "Yes\n";
}


// G
void Ramez(){
  int n, m; cin >> n >> m;
  int q; cin >> q;
  while(q--){
    int ops; cin >> ops;
    if(ops == 0){
      int x, y; cin >> x >> y;
      int i = (y-1)*m + x;
      cout << i << "\n";
    } else {
      int i; cin >> i; 
      int y = ceil(i/(double)m);
      int x = (i%m == 0? m : i%m);
      cout << x << " " << y << "\n";
    }
  }
}


int main() {
    // UseFile();
    FastIO();
    int t = 1;
    cin >> t;
    while (t--) Ramez();
    return 0;
}






