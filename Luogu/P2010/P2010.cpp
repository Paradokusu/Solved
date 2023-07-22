#include <bits/stdc++.h>

using namespace std;
const int N = 15;

int date1, date2;
int cnt, date, ans;

int d[N] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    scanf("%d %d", &date1, &date2);

    for (int i = 1; i <= 12; i++) {
        // 枚举月和日
        for (int j = 1; j <= d[i]; j++) {
            cnt = (j % 10) * 1000 + (j / 10) * 100 + (i % 10) * 10 + (i / 10);
            date = cnt * 10000 + (i * 100) + j;
            if (date < date1 || date > date2) continue;
            else ans++;
        }
    }

    printf("%d", ans);
    return 0;
}
