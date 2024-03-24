#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        int a[n];
        int sum = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
        }
        
        if(sum % 3 == 0){
            cout << 0 << endl;
            continue;
        } else if ((sum+1) % 3 == 0){
            cout << 1 << endl;
            continue;
        }
        
        bool printed = false;
        for(int i = 0; i < n; i++){
            if((sum-a[i])%3 == 0){
                cout << 1 << endl;
                printed = true;
                break;
            }
        }
        if(printed == false)
        cout << 2 << endl;
    }
        return 0;
}