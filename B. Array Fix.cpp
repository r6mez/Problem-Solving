#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int nextIndexBiggerThan10(vector<int>& a)
{
    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] >= 10)
            return i;
    }
    return -1;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        bool sorted = true;

        while (!is_sorted(a.begin(), a.end())){
            int i = nextIndexBiggerThan10(a);
            if(i == -1) {
                sorted = false;
                break;
            }
            int num = a[i];
            a.erase(a.begin() + i);
            vector<int> digits;
            do {
                digits.push_back(num % 10);
                num /= 10;
            } while (num > 0);
            reverse(digits.begin(), digits.end());
            a.insert(a.begin() + i, digits.begin(), digits.end());
        }

        cout << (sorted? "YES\n" : "NO\n");
    }
    return 0;
}
