#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define endl "\n"

template <typename T>
istream& operator>>(istream& input, vector<T>& data)
{
    for (T& x : data)
        input >> x;
    return input;
}

template <typename T>
ostream& operator<<(ostream& output, const vector<T>& data)
{

    for (const T& x : data)
        output << x << " ";
    return output;
}

ll dist(pair<int, int> i, pair<int, int> j)
{
    return (ll)abs(i.first - j.first) + (ll)abs(i.second - j.second);
}

void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }

int main()
{
    FastIO();
    int t, n, e, m;
    cin >> t;
    while (t--)
    {
        cin >> n;
        e = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> m;
            if (!(m & 1))
                e++;
        }
        if (n & 1)
            cout << -1 << "\n";
        else
        {
            ll ans = (n >> 1) - e;
            cout << ans << "\n";
        }
    }
    return 0;
}