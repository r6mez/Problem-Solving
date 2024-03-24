#include <iostream>
#include <algorithm>
using namespace std;

bool compare(long a, long b){
    return a > b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    long long a[n], b[n];
    long long  c[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        c[i] = a[i]-b[i];
    }

    sort(c, c+n, compare);

    long long counter = 0;
    long long i = 0, j = n-1;
    while (i <= j){
        if(c[i] + c[j] > 0) {
            counter += (j - i); // pairs number
            i++;
        } else {
            j--;
        }
    }

    cout << counter;
    return 0;
}
