#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    long long n;
    cin >> n;
    double l2N = log2(n);
    double l2Nint = trunc(l2N);
    if(l2N - l2Nint == 0.0) cout << "YES";
    else cout << "NO";
    return 0;
}