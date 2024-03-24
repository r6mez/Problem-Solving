#include <bits/stdc++.h>
using namespace std;
unsigned long long llog2(unsigned long long n, int counter = 0){
    if(n == 1) return counter;
    return llog2(n/2, counter+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    unsigned long long n; cin >> n;
    cout << llog2(n);
    return 0;
}
