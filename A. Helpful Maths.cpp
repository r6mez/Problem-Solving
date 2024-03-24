#include <iostream> 
#include <vector>
#include <sstream>
using namespace std;

vector<int> getInputOfIntegers() {
    string input;
    getline(cin, input);
    vector<int> result;
    istringstream iss(input);
    int num;
    while (iss >> num) {
        result.push_back(num);
    }
    return result;
}

void swapTwoElements(int& element1, int& element2){
    int temp = element1;
    element1 = element2;
    element2 = temp;
}

void arrangeNumbers(){
    vector<int> numbers = getInputOfIntegers();

    //sort the numbers
    for (int i = 0; i < numbers.size(); i++)
    {
      for (int j = i+1; j < numbers.size(); j++)
      {
        if(numbers[i] > numbers[j]){
            swapTwoElements(numbers[i] , numbers[j]);
        }    
      }
    } 
    
    string sum = "";
    for (int i = 0; i < numbers.size(); i++)
    {
        sum.append(to_string(numbers[i]) + "+");
    }
    sum.pop_back();
    cout<<sum;
}

int main(){
    arrangeNumbers();
    return 0;
}