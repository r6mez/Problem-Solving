#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define vi vector<int>
using namespace std;

void Rang(int& t)
{
    int n, m, k;
    while (t--)
    {
        cin >> n >> m >> k;

        vi a(n);
        for (auto& x : a) cin >> x;

        int i = 0; int j = m - 1;
        while (j < n)
        {
            if (!is_sorted(a.begin() + i, a.begin() + j + 1))
                sort(a.begin() + i, a.begin() + j + 1);
            i++; j++;
        }

        cout << a[k - 1] << endl;

    }

}

int main()
{
    int t; cin >> t;
    Rang(t);

    return 0;
}