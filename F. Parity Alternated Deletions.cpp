#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    auto nextElement = a.end();
    bool isLastOdd = (a[n-1]%2);
    bool changed = false;
    a.erase(a.end());
    while (!a.empty()){
        if(changed) nextElement = a.end();
        while ((*nextElement)%2 == isLastOdd){
            nextElement--;
            if((*nextElement)%2 != isLastOdd){
                changed = true;
                break;
            }
        }
        if(changed){
            isLastOdd = (*nextElement)%2;
            cout << *nextElement << " ";
            a.erase(nextElement);
        } else {
            break;
        };
    }
    cout << "\n";
    int sum = 0;
    for(int i: a){
        sum += i;
    }
    cout << sum;
    return 0;
}