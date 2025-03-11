#include <iostream> 
#include <vector>
#include <sstream>
using namespace std;

vector<int> getInputOfIntegers(int numberOfIntegers) {
    vector<int> results;
    for (int i = 0; i < numberOfIntegers; i++)
    {
        int number;
        cin >> number;
        results.push_back(number);
    }
    
    return results;
}


void checkNumberIfCommon(){
    int sizeOfArray, commonElement;
    cin >> sizeOfArray >> commonElement;

    cin.ignore();

    vector<int> array = getInputOfIntegers(sizeOfArray);
    
    int count;
    int max_count = 0;
    int max_index = 0;

    for (int i = 0; i < array.size(); i++)
    {
        count = 1;
        for (int j = i+1; j < array.size(); j++)
        {
            if(array[i] == array[j]){
                count++;
            }
        }

        if(max_count <= count){
            max_count = count;
            max_index = i;
        }
    }

    if (array[max_index] == commonElement) cout << "Yes " << array[max_index] << endl;
    else cout << "No " << array[max_index] << endl;
}


int main(){
    int testCases;
    cin >> testCases;

    while (testCases--)
    {
        checkNumberIfCommon();
    }
    return 0;
}