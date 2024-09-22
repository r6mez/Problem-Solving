#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    long long a[n], b[m];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    bool isSub = false;
    int lastK = 0;

    for (int i = 0; i < m; i++) {
        bool found = false; 
        for (int k = lastK; k < n; k++) {
            if (b[i] == a[k]) {
                found = true;
                lastK = k + 1; 
                break;
            }
        }
        
        if (!found) {
            isSub = false; 
            break;
        } else {
            isSub = true; 
        }
    }

    if (isSub) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
