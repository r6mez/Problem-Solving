#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    bool headerNotSeen = true;
    int counter = 0;
    stack<string> html;
    int n;
    cin >> n; 
    
    while(n--){
        string value;
        cin >> value;

        if(headerNotSeen && value != "Header"){
            cout << "WA" << endl;
            return 0;
        }
        headerNotSeen = false;

        if(value == "Header") counter++;
        if(counter > 1) {
            cout << "WA" << endl;
            return 0;
        }

        if(html.empty()){
            html.push(value);
        } else{
            if(value == "End" + html.top()) html.pop();
            else html.push(value);
        }
    }

    if(html.empty()) cout << "ACC" << endl;
    else cout << "WA" << endl;
    
    return 0;
}