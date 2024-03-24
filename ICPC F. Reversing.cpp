#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n;
    cin >> n;
    long long numbers[n];

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    for (int i = 0; i < n/2; i++)
    {
        long long temp = numbers[i];
        numbers[i] = numbers[n-i-1];
        numbers[n-i-1] = temp;
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << numbers[i] << " "; 
    }
    
    
    return 0;
}