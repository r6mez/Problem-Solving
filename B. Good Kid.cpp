#include <iostream> 
#include <vector>
using namespace std;

void clacMaxMultiplation(){
    int numberOfDigits;
    cin >> numberOfDigits;

    vector<int> digits;

    for (int i = 0; i < numberOfDigits; i++)
    {
        int digit;
        cin >> digit;
        digits.push_back(digit);
    }

    int minNumberInDigits = 10;
    int minNumberIndex = 0;
    
    for (int i = 0; i < digits.size(); i++)
    {
        if(minNumberInDigits > digits[i]){
            minNumberIndex = i;
            minNumberInDigits = digits[i];
        }
    }
    
    digits[minNumberIndex]++;

    int result = 1;
    for(int i : digits){
        result = result * i;
    }
    
    cout << result << endl;
}


int main(){
    int numberOfTestCases;
    cin >> numberOfTestCases;

    while(numberOfTestCases--){
        clacMaxMultiplation();
    }
    return 0;
}