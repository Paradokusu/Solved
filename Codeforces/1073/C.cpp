#include <bits/stdc++.h>

using namespace std;
constexpr int N = 2e5 + 5;

int n, x, y;
char s[N];

bool can(pair<int, int> u, pair<int, int> v, int len) {
	int d = abs(u.first - v.first) + abs(u.second - v.second);
	if (d % 2 != len % 2) return false;
	return len >= d;
}

void update(pair<int, int> &pos, char mv, int d) {
	if (mv == 'U') pos.second += d;
	else if (mv == 'D') pos.second -= d;
	else if (mv == 'R') pos.first += d;
	else if (mv == 'L') pos.first -= d;
}

bool check(int len) {
	pair<int, int> pos = {0, 0};
	for (int i = len; i < n; i++)
		update(pos, s[i], 1);
	int l = 0, r = len;
	while (true) {
		if (can(pos, {x, y}, len)) return true;
		if (r == n) break;
		update(pos, s[l++], 1);
		update(pos, s[r++], -1);
	}
	return false;
}

int main() {
	scanf("%d %s %d %d", &n, s, &x, &y);

	if (!check(n)) { printf("-1\n"); return 0; }
	int l = -1, r = n;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid;
	}
	printf("%d\n", r);
	return 0;
}
