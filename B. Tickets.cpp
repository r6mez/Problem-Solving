#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);

    int n;
    cin >> n;

    queue<int> q;
    while(n--){
        int a, b;
        cin >> a >> b;
        if(a == 1){
            q.push(b);
        } else {
            if(q.front() == b){
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
            q.pop();
        }
    }    
    return 0;
}