#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        long long n, factorial=1; 
        cin >> n;
        for (n; n > 0; n--)
        {
           factorial *= n;
        }
        cout << factorial << "\n";
    }
    return 0;
}