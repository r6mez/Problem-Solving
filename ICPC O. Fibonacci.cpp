#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    long long a = 0 , b = 1, c;
    for (int i = 0; i < n - 2; i++)
    {
        c = a+b;
        a = b;
        b = c;
    }

    if (n == 1) cout << 0;
    else if (n == 2) cout << 1;
    else cout << c;
    
    return 0;
}