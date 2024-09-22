#include <bits/stdc++.h>
using namespace std;

void printSequenceLength(int n, int length = 1){
    if (n == 1) {
        cout << length;
        return;
    } else {
        int nextSequnce = (n%2 == 0? n/2 : 3*n+1);
        printSequenceLength(nextSequnce, length+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    printSequenceLength(n);
    return 0;
}
