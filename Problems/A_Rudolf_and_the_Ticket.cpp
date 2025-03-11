#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        int n,m,k; cin >> n >> m >> k;
        int left[n], right[m];
        for (int i = 0; i < n; ++i) {
            cin >> left[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> right[i];
        }

        int counter = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(left[i] + right[j] <= k) counter++;
            }
        }
        cout << counter << "\n";
    }
    return 0;
}
