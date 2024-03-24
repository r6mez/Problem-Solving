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

    int min = INT_MAX;
    
    for (int i = 0; i < n; i++)
    {
        if(numbers[i] < min) min = numbers[i];
    }
    
    int minFreq = 0;
    for (int i = 0; i < n; i++)
    {
        if(numbers[i] == min) minFreq++;
    }

    if(minFreq % 2 != 0) cout << "Lucky";
    else cout << "Unlucky";
    
    return 0;
}