#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        if(n%i==0) cout << i << "\n";
    }
    
    return 0;
}