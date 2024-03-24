#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n;
    cin >> n;

    int maxnumber = 0;
    for (n; n > 0; n--)
    {
        int x; 
        cin >> x;

        if(x>maxnumber) maxnumber = x;
    }

    cout << maxnumber;
    return 0;
}