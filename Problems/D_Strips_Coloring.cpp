#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#define ll long long
#define mapii unordered_map<int,int>
#define vi vector<int>
#define vll vector<ll>
#define all(v) v.begin(), v.end()
using namespace std;
const int MOD = 1000000007;

void FastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }

int main() {
    freopen("strips.in", "r", stdin);
    FastIO();

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

//هنتجاهل الاصفار اللي على الطرفين و نبدا نغير و نلون في اللي موجوده في النص 
// هنمشي نعد عدد البلوكات اللي فيها اصفار و فيها كام صفر
// بعد عدد القطعات اللي ممكن اعملها لو مش لونت خالص و لو لونت اي مجموعه اصفار من اللي في النص يبقى عدد القطعات دي هتقل بمقدار 2
// اما لو لونت حاجه على الطرف يبقى عدد القطعات هتقل بمقدار 1

        int i = 0;
        while (i < n && s[i] == '0') i++; // اول واحد اقابله

        int j = n - 1;
        while (j >= 0 && s[j] == '0') j--; // آخر واحد اقابله

        vi zeros_inMiddle;

        while (i <= j) {
            if (s[i] == '1') {
                i++;
                int cnt = 0;
                while (i <= j && s[i] == '0') {
                    cnt++;
                    i++;
                }
                if (i <= j && cnt > 0)
                    zeros_inMiddle.push_back(cnt);
            } else {
                i++;
            }
        }

        sort(all(zeros_inMiddle));

        int cuts = 0;
        if (n > 0) {
            char prev = s[0];
            for (int i = 1; i < n; i++) {
                if (s[i] != prev) {
                    cuts++;
                    prev = s[i];
                }
            }
        }

        int connect = 0;
        for (int x : zeros_inMiddle) {
            if (k >= x) {
                connect += 2;
                k -= x;
            } else break;
        }

        vi zeros_first_last;

        if (s[0] == '0') {
            int cnt = 0;
            for (char c : s) {
                if (c == '0') cnt++;
                else break;
            }
            zeros_first_last.push_back(cnt);
        }

        if (s.back() == '0') {
            int cnt = 0;
            for (int i = n - 1; i >= 0; i--) {
                if (s[i] == '0') cnt++;
                else break;
            }
            zeros_first_last.push_back(cnt);
        }

        sort(all(zeros_first_last));

        for (int x : zeros_first_last) {
            if (k >= x) {
                connect += 1;
                k -= x;
            } else break;
        }

        int min_cuts = max(0, cuts - connect);
        cout << min_cuts << endl;
    }

    return 0;
}