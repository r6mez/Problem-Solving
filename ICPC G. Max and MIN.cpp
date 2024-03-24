#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    int numbers[n];
    int max = INT_MIN;
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
        if (numbers[i] > max) {
            max = numbers[i];
        }
        if(numbers[i] < min) {
            min = numbers[i];
        }
    }

    cout << min << " " << max;
    return 0;
}