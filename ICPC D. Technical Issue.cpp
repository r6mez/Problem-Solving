#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int numberOfteams;
        cin >> numberOfteams;
        string data[numberOfteams][3];
        for (int i = 0; i < numberOfteams; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> data[i][j];
            }
        }
        
        
        int maxScore = 0;
        int maxScoreIndex = 0; 
        int maxScoreTeams = 1;

        long long minTime = LONG_LONG_MAX;
        int minTimeIndex = 0;

        for (int i = 1; i < numberOfteams; i++)
        {
            if(stoi(data[i][1]) > maxScore) {
                maxScore = stoi(data[i][1]);
                maxScoreIndex = i;
                maxScoreTeams = 1;
                minTime = stoi(data[i][2]);  // Update minTime along with maxScore
                minTimeIndex = i;
            } else if (stoi(data[i][1]) == maxScore) {
                maxScoreIndex = i;
                maxScoreTeams++;
            }

            if(stoi(data[i][2]) < minTime && maxScoreIndex == i) {
                minTime = stoi(data[i][2]);
                minTimeIndex = i;
            }
        }

        if(maxScoreTeams == 1){
            cout << data[maxScoreIndex][0] << "\n";
        } else {
            cout << data[minTimeIndex][0] << "\n"; 
        }
        
    }   
    return 0;
}