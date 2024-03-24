#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    freopen("cowsignal.in","r",stdin);
    freopen("cowsignal.out","w",stdout);
    
    int n,m;
    cin >> n >> m;
    
    int road[n][2];
    int journey[m][2];

    for (int i = 0; i < n; i++)
    {
        cin >> road[i][0] >> road[i][1];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> journey[i][0] >> journey[i][1];
    }

    int max_over_limit = 0, traveled = 0;
    

    cout << max_over_limit;
    return 0;
}