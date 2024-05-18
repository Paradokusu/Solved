#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 7;
constexpr int inf = numeric_limits<int>::max();

int n, m, l;
int ans1, ans2;
string s1, s[N];
unordered_map<string, int> sum;
unordered_map<string, bool> fl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s1;
        fl[s1] = 1;
    }

    cin >> m;
    l = 1;
    for (int i = 1; i <= m; i++) {
        cin >> s[i];
        if (fl[s[i]]) sum[s[i]]++;
        if (sum[s[i]] == 1) {
            ans1++;
            ans2 = i - l + 1;
        }

        while (l <= i) {
            if (!fl[s[l]]) {
                l++;
                continue;
            }
            if (sum[s[l]] >= 2) {
                sum[s[l]]--;
                l++;
                continue;
            }
            break;
        }
        ans2 = min(ans2, i - l + 1);
    }

    cout << ans1 << "\n" << ans2 << "\n";
    return 0;
}
