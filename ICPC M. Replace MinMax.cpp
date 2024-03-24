#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    int numbers[n];

    int max = INT_MIN;
    int maxi = 0;
    int min = INT_MAX;
    int mini = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
        if (numbers[i] > max) {
            max = numbers[i];
            maxi = i;
        }
        if(numbers[i] < min) {
            min = numbers[i];
            mini = i;
        }
    }
    
    swap(numbers[maxi], numbers[mini]);

    for (int i = 0; i < n; i++)
    {
        cout << numbers[i] << " ";
    }
    
    return 0;
}