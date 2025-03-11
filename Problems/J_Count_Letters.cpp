#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int num = 0;
    int index = 0;
    while (index < s.length()){
        for (int i = index; i < s.length(); i++)
        {
            if(s[i] == s[i+1]) {
                num++;
                index++;    
            }
            else {
                num++;
                index++;   
                break;
            };
        }
        cout << s[index-1] << " : " << num << "\n";
        num = 0;
    }
    return 0;
}