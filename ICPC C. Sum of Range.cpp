#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    long long a,b;
    cin >> a >> b;
    long long mx = max(a,b), mn = min(a,b);
    long long sum = ((mx-mn+1)*(mx+mn))/2;
    long long even = (mx/2)*((mx/2)+1) - ((mn-1)/2)*(((mn-1)/2)+1);
    long long odd = sum - even;
    cout << sum << "\n" << even << "\n" << odd << "\n";
    return 0;
}

// 1 2 3 4 5 6

// 4 5 6
// 15 total
// 10 even
// 5 odd

// 1 2 3 4 5 6 7
// 28 total
// 12 even
// 16 odd