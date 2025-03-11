#include <iostream>

using namespace std;

void shiftNTimes(int numbers[], int arrSize,int numberOfShifts){
    while(numberOfShifts--){
        int lastElement = numbers[arrSize-1];
        for (int i = arrSize-1; i > 0; i--)
        {
            numbers[i] = numbers[i-1]; 
        }
        numbers[0] = lastElement;
    }

    for (int i = 0; i < arrSize; i++)
    {
        cout << numbers[i] << " ";
    }
    
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n,x;
    cin >> n >> x;
    int numbers[n];

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }
    
    shiftNTimes(numbers, n, x);
    
    return 0;
}