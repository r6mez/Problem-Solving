#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    long long n;
    cin >> n;
    if(n%2 != 0){
        for (int i = 0; i < n; i++)
        {
            cout << char('a') << ' ';
        }
    } else {
        for (int i = 0; i < n-1; i++)
        {
            cout << char('a') << ' ';
        }
        cout << char('b');
    }
    
    return 0;
}