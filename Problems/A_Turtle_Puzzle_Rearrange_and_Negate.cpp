// Online C++ compiler to run C++ program online
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int sum = 0;
        while(n--){
            int x;
            cin >> x;
            sum += abs(x);
        }
        cout << sum << endl;
    }
    return 0;
}