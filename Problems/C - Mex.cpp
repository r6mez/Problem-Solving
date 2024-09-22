#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector <int> f(n + 1, 0);

        for (int i = 0; i < n; i++){
            int x; cin >> x;
            f[x]++;
        }

        int c = 0;
        for (int i = 0; i <= n; i++){
            c += (f[i] == 1);
            if ((c == 2) || (f[i] == 0)){
                cout << i << "\n";
                break;
            }
        }
    }
    return 0;
}