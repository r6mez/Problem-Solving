#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    long long n;
    cin >> n;
    long long number[n];
    for (int i = 0; i < n; i++)
    {
        cin >> number[i];
    }

    sort(number, number+n);
    int numberOfRanges = 1;
    for (int i = 0; i < n-1; i++)
    {
        if(number[i] != number[i+1]-1) numberOfRanges++;
    }
    cout << numberOfRanges;
    
    return 0;
}