#include <iostream>
#include <algorithm>

using namespace std;

void CountDisticntNumbers(int* numbers, int arrSize){
    sort(numbers,numbers+arrSize);

    int distinctNumbers = 1;
    int lastNumber = numbers[0];

    for (int i = 1; i < arrSize; i++)
    {
        if(numbers[i] != lastNumber){ 
            distinctNumbers++;  
            lastNumber = numbers[i];     
        }
    }

    cout << distinctNumbers;    
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n;
    cin >> n;
    int numbers[n];

    for (int i = 0; i < n; i++)
    {
        cin>> numbers[i];
    }
    
    if(n != 0)
    CountDisticntNumbers(numbers,n);    
    else
    cout << 0;
    return 0;
}