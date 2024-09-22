#include <iostream> 
using namespace std;

void compareTwoNumbers(){
    string num1, num2;
    cin >> num1 >> num2;

    string result = "";
   
    for (int i = 0; i < num1.size(); i++)
    {
        if(num1[i] != num2[i]){
            result.push_back('1');
        } else {
            result.push_back('0');
        }
    }

    cout << result;
}


int main(){
    compareTwoNumbers();
    return 0;
}