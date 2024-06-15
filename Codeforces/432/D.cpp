#include <bits/stdc++.h>

constexpr int N = 1e5 + 7;

int n;
int nex[N], dp[N];
char s[N];

std::vector<int> ans;

int main() {
    scanf(" %s", s + 1);
    n = strlen(s + 1);

    for (int i = 2, j = 0; i <= n; i++) {
        while (j && s[i] != s[j + 1])
            j = nex[j];
        if (s[j + 1] == s[i])
            j++;
        nex[i] = j;
    }

    for (int i = nex[n]; i; i = nex[i])
        ans.push_back(i);
    
    for (int i = n; i >= 1; i--) {
        dp[i]++;
        dp[nex[i]] += dp[i];
    }

    printf("%d\n", ans.size() + 1);
    for (int i = ans.size() - 1; i >= 0; i--)
        printf("%d %d\n", ans[i], dp[ans[i]]);
    printf("%d %d\n", n, dp[n]);
    return 0;
}
