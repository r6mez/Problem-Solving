#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    vector <int> sum(n+1,0);
    int earliestOddSumIndex = -1;
    int maxLength = -1;

    for(int i = 1; i <= n; i++)
    {
        int j; cin >> j;
        sum[i] = sum[i-1] + j;

        if(sum[i] % 2 == 0) {
            if(earliestOddSumIndex != -1) {
                maxLength = max(maxLength, i - earliestOddSumIndex);
            }
        } else {
            maxLength = i;
            if(earliestOddSumIndex == -1) {
                earliestOddSumIndex = i;
            }
        }
    }

    cout << maxLength << "\n";
    return 0 ;
}