#include <iostream>
#include <stack>
#include <set>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<ll> st;
    multiset<ll> ms;

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int op;
        cin >> op;
        if(op == 1){
            ll x;
            cin >> x;
            st.push(x);
            ms.insert(x);
        } else {
            ll top = st.top();
            st.pop();
            ms.erase(ms.find(top));
        }
        cout << *ms.rbegin() << "\n";
    }
    return 0;
}