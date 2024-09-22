#include <iostream>
#include <algorithm>
using namespace std;

bool nextPermutation(string& s)
{
    if (s.size() == 1)
        return false;
 
    int i = s.size() - 1;
 
    while (true)
    {
        int j = i;
        --i;
 
        if (s[i] < s[j])
        {
            int k = s.size()-1;
 
            while (s[i] >= s[k])
                k--;
 
            swap(s[i], s[k]);
            reverse(s.begin() + j, s.end());
            return true;
        }
 
        if (i == 0)
        {
            reverse(s.begin(), s.end());
            return false;
        }
    }
}
 
void solve() {
    string s;
    cin>>s;
 
    //if(nextPermutation(s))
    if(next_permutation(s.begin(), s.end()))
        cout<< s << '\n';
    else
        cout<<"-1\n";
}
 
int main(){
    int t = 1; cin >> t;
    while (t--)
        solve();
}
 