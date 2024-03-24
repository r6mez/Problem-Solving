#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        int counter = 0;
        for (int i = 1; i <= n-2; ++i) {
            if(s[i-1] == 'm' && s[i] == 'a' && s[i+1] == 'p' && s[i+2] == 'i' && s[i+3] == 'e') {
                counter++;
                i += 3;
            } else if((s[i-1] == 'p' && s[i] == 'i' && s[i+1] == 'e') ||
               (s[i-1] == 'm' && s[i] == 'a' && s[i+1] == 'p')){
                counter++;
            }
        }

        cout << counter << "\n";
    }
    return 0;
}