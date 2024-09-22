#include <iostream>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--){
        int n;
        cin >> n;
        if(n%2 != 0){
            cout << "NO\n";
        }else {
            cout << "YES\n";
            char c = 'A';
            for (int i = 0; i < n/2; ++i) {
                cout << c << c;
                c++;
            }
            cout << '\n';
        }
    }
    return 0;
}
