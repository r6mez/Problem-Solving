#include <iostream> 
using namespace std;

int ReadNumber(){
    int number;
    cin >> number;
    return number;
}

void solveOrNot(){
    int numberOfProblems = ReadNumber();
    int numberOfSolvedProblems = 0;
    for (int i = 0; i <= numberOfProblems; i++)
    {   
        string opinions;
        getline(cin,opinions);
        int numberOfAgree = 0;
        if (opinions[0] == '1') numberOfAgree++;
        if (opinions[2] == '1') numberOfAgree++;
        if (opinions[4] == '1') numberOfAgree++;
        if (numberOfAgree >= 2) numberOfSolvedProblems++;
    }
    cout << numberOfSolvedProblems;
}

int main(){
    solveOrNot();
    return 0;
}