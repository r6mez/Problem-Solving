#include <iostream>
using namespace std;

/*
1. check if experssion is right
2. if right print yes and exist
3. if not find the right answer and print it and exist
*/

int main(){
    long long a,b,c;
    char s,q;
    cin >> a >> s >> b >> q >> c;

    if((s == '+' && a+b==c) || (s == '-' && a-b==c) || (s == '*' && a*b==c))
        cout << "Yes";
    else{
        switch (s)
        {
        case '+':
            cout << a+b;
            break;
        case '-':
            cout << a-b;
            break;
        case '*':
            cout << a*b;
            break;
        }
    }
    return 0;
}