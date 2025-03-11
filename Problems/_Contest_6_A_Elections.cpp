#include <iostream>
#include <cmath>
using namespace std;

long long output(long long max, long long x){
    // gives zero with the max value
    if(x == max) return (max - x);
    // gives the normal result result
    else return (max - x) + 1;
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long a, b, c;
        cin >> a >> b >> c;
        long long maxV = (a>b? (a>c?a:c) : (b>c?b:c));
        // handling if the three var the same
        if (a == b && b == c) cout << (1) << " " << (1) << " " << (1) << "\n";
        // handles if there's 2 max
        else if ((a == b && a == maxV) || (b == c && b == maxV) || (a == c && a == maxV)) cout << (maxV - a + 1) << " " << (maxV - b + 1) << " " << (maxV - c + 1) << "\n";
        // handling the normal type
        else cout << output(maxV, a) << " " << output(maxV, b) << " " << output(maxV, c) << "\n"; 
   }
    return 0;
}