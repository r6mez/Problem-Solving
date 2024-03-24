#include <iostream> 
#include <vector>
using namespace std;

string swap(string str, int index1, int index2){
    char temp = str[index1];
    str[index1] = str[index2];
    str[index2] = temp;
    return str;
}

void chackIfSwapsIsGood(){
    int numberOfTestCases;
    cin >> numberOfTestCases;

    vector<string> results;

    for (int i = 0; i < numberOfTestCases; i++)
    {
        string cards;
        cin >> cards;

        string swap1 = swap(cards, 0, 1);
        string swap2 = swap(cards, 1, 2);
        string swap3 = swap(cards, 0, 2);

        if(cards == "abc" || swap1 == "abc" || swap2 == "abc" || swap3 == "abc") results.push_back("Yes");
        else results.push_back("No");
    }
    
    for (int i = 0; i < results.size(); i++)
    {
        cout << results[i] << endl;
    }
    
}


int main(){
    chackIfSwapsIsGood();
    return 0;
}