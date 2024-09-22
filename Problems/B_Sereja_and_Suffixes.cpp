#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> freq(100001, 0); 
    vector<int> prefixSumOfFrequecies(n, 0);

    freq[a[n-1]] = 1;
    prefixSumOfFrequecies[n-1] = 1;
    
    for (int i = n-2; i >= 0; i--) {
        if(freq[a[i]] == 0){
            freq[a[i]]++;
            prefixSumOfFrequecies[i] = prefixSumOfFrequecies[i+1] + 1;
        } else {
            prefixSumOfFrequecies[i] = prefixSumOfFrequecies[i+1];
        }
    }
    
    while (m--) {
        int x;
        cin >> x;
        cout << prefixSumOfFrequecies[x-1] << "\n";
    } 
    return 0;
}
