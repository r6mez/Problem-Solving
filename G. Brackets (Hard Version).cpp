#include <iostream>
#include <stack>
using namespace std;


int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    stack<char> stack;
    string str;
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        if(stack.empty()){
            stack.push(str[i]);
        } else{
            if((stack.top() == '{' && str[i] == '}') ||
               (stack.top() == '[' && str[i] == ']') ||
               (stack.top() == '(' && str[i] == ')')) 
            {
                stack.pop();
            } else{
                stack.push(str[i]);
            }
        }
    }
    
    if(stack.empty()) cout << "yes" << endl;
    else cout << "no" << endl;
    
    return 0;
}