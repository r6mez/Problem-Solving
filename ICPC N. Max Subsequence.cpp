#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int n;
    string t;

    cin >> n;
    cin >> t;

    int x = 0;
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (t[i] != t[i+1] && i+1 != n) {
            x++;
            if (max < x ){
                max = x;
            }
        }
        else x = 0;
    }

    cout << max+1;
    
    return 0;
}