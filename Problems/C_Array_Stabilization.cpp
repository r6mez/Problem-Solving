#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vi vector<int>

int calcInst(vi a){
    auto minIt = min_element(a.begin(),a.end());
    int minVal = *minIt;
    auto maxIt = max_element((a.begin()), a.end());
    int maxVal = *maxIt;
    int inst = maxVal - minVal;
    return inst;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int inst = calcInst(a);

    vi a1 = a;
    a1.erase(min_element(a1.begin(), a1.end()));
    vi a2 = a;
    a2.erase(max_element(a2.begin(), a2.end()));

    int inst1 = calcInst(a1);
    int inst2 = calcInst(a2);

    cout << min(inst1, inst2);
    return 0;
}
