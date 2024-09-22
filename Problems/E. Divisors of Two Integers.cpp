#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vi a(n);
    int freq[10001] = {0};
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        freq[a[i]]++;
    }
    int d1 = *max_element(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        if(d1 % a[i] == 0){
            if(freq[a[i]] != 2){
                a[i] = 0;
            } else {
                freq[a[i]]--;
            }
        }
    }
    int d2 = *max_element(a.begin(), a.end());
    cout << d1 << " " << (d2 != 0? d2 : d1/2);
    return 0;
}

