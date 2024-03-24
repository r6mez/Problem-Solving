#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n , q;
    cin >> n >> q;
    long long num[n];
    
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    while (q--){
        long long x; 
        cin >> x;
        int w = 0;
        for (int i = 0; i < n; i++)
        {
            if(num[i] > x) w++;
        }
        cout << w << "\n";
    }
    
    return 0;
}