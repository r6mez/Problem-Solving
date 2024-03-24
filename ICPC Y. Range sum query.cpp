#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    long long numbers[n], prefixs_sum[n+1] = {0};

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
        prefixs_sum[i+1] = prefixs_sum[i] + numbers[i];
    }

    for (int i = 0; i < q; i++)
    {
        int l,r;
        cin >> l >> r;
        cout << prefixs_sum[r] - prefixs_sum[l - 1] << "\n";
    }
    return 0;
}