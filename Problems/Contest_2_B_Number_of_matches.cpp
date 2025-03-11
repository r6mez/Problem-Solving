#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int n, sum = 0, maxGoals = 0;
    cin >> n;
    while(n--){
        int thisMatch;
        cin >> thisMatch;
        
        if(thisMatch){
            sum++;
            if(sum>maxGoals){
                maxGoals = sum;
            }
        } else {
            sum = 0;
        }
    }
    if(maxGoals != 0) cout << maxGoals;
    else cout << "Bad Luck";
    return 0;
}