#include <iostream> 
#include <algorithm>
using namespace std;

string checkSameLetters(){
    string str1, str2, input;
    cin >> str1 >> str2 >> input;   

    string temp = str1+str2;

    sort(temp.begin(), temp.end());
    sort(input.begin(), input.end());

    
    if(temp != input) return "NO";
    else return "YES";
}


int main(){
    cout << checkSameLetters();
    return 0;
}