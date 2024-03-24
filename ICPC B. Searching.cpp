#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    int numbers[n];
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    int x;
    cin >> x;

    bool isFound = false;

    for (int i = 0; i < n; i++)
    {
        if(x == numbers[i]){
            cout << i;
            isFound = true;
            break;
        }
    }
    
    if(!isFound) cout << -1;
    return 0;
}