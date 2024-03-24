#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int NumberOfStudents, HighestScore;
        cin >> NumberOfStudents >> HighestScore;

        int me;
        cin >> me;
        NumberOfStudents--;

        while(NumberOfStudents--){
            int student;
            cin >> student;          
            me += student;
        }
        if (me <= HighestScore) cout << me << "\n";
        else cout << HighestScore << "\n";
    }
    return 0;
}
