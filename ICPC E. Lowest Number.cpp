#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int n; 
    cin >> n;
    int numbers[n];

    int min = 100000, minIndex;
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
        if (numbers[i] < min) {
            min = numbers[i];
            minIndex = i;
        }
    }
    
    cout << min << " " << minIndex+1;
    
    return 0;
}