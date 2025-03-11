#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int testcases;
    cin >> testcases;

    while (testcases--){
        string n;
        cin >> n;
        string reversedString = "";

        for (long long i = (n.length() - 1); i >= 0; i--)
        {
            cout << n[i] << " ";
        }
        
        cout << "\n";
    }
    return 0;
}