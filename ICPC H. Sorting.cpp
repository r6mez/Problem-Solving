#include <iostream>

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

    for (int j = 0; j < n-1; j++)
    {
        for (int i = 0; i < n-1; i++)
        {
            if(numbers[i] > numbers[i+1]) swap(numbers[i], numbers[i+1]);
        }
    } 

    for (int i = 0; i < n; i++)
    {
        cout << numbers[i] << " ";
    }
    return 0;
}