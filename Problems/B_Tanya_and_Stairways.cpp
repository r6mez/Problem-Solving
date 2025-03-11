#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vi vector<int>



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int a[n];
    int stairs = 0;
    vi steps;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1) {
            stairs++;
            if(i != 0) steps.push_back(a[i-1]);
        }
        if(i == n-1) steps.push_back(a[i]);
    }

    cout << stairs << "\n";
    for (int i : steps) {
        cout << i << " ";
    }
    return 0;
}
