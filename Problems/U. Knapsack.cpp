#include <bits/stdc++.h>
using namespace std;

class item {
public:
    int value;
    int weight;
};

int maxKnapsackValue(int n, int w, vector<item> items){
    if(w == 0 || n == 0) return 0;
    else if(items[n-1].weight > w) return maxKnapsackValue(n-1,w,items);
    else {
        int valueIfWeSelectCurrentValue = (items[n-1].value + maxKnapsackValue(n-1, w - items[n-1].weight, items));
        int valueIfWeDont = maxKnapsackValue(n-1, w, items);
        return max(valueIfWeSelectCurrentValue,valueIfWeDont);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,w; cin >> n >> w;
    vector<item> items(n);
    for (int i = 0; i < n; ++i) {
        cin >> items[i].weight >> items[i].value;
    }
    cout << maxKnapsackValue(n,w,items);
    return 0;
}