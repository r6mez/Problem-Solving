#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    int a[n], b[n];
    
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    sort(a, a+n);
    sort(b, b+n);

    bool isEqual = true;

    for (int i = 0; i < n; i++)
    {
        if(a[i] != b[i]) isEqual = false; 
    }

    if (isEqual) cout << "yes";
    else cout << "no";
    
    return 0;
}


