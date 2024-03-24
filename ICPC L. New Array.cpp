#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n;
    cin >> n;
    int arr1[n],arr2[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }
        
    for (int i = 0; i < n; i++)
    {
        cout << arr2[i] << " ";
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }
    
    return 0;
}