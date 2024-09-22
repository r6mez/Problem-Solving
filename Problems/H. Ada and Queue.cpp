#include <iostream>
#include <list>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n;
    cin >> n;

    list<int> q;
    while (n--){
        string s;
        cin >> s;
        if (s == "toFront"){
            int input;
            cin >> input;
            q.push_front(input);
        } else if (s == "push_back"){
            int input;
            cin >> input;
            q.push_back(input);
        } else if (s == "front"){
            if(q.empty()) cout << "No job for Ada?\n";
            else{
                cout << q.front() << "\n";
                 q.pop_front();
            } 
        } else if (s == "back") {
            if(q.empty()) cout << "No job for Ada?\n";
            else {
                cout << q.back() << "\n";
                q.pop_back();
            }
        } else if (s == "reverse"){
            q.reverse();
        }
    }
    return 0;
}