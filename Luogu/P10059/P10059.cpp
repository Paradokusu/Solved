#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 7;
constexpr int M = 1e6 + 7;
constexpr int inf = numeric_limits<int>::max();

int T, n, k;
int cot;
int a[N];
int lg[N], qmx[20][N], qmn[20][N];

void build() {
	for (int i = 1; i <= 100000; i++)
		for (int j = 1; j < 18; j++)
			qmx[j][i] = -inf;
	for (int i = 1; i <= 100000; i++)
		for (int j = 1; j < 18; j++)
			qmn[j][i] = inf;
	for (int i = 1; i <= n; i++)
		qmx[0][i] = qmn[0][i] = a[i];
	for (int j = 1; j < 18; j++)
		for (int i = 1; i + (1 << j) <= n + 1; i++) {
			qmx[j][i] = max(qmx[j - 1][i], qmx[j - 1][i + (1 << (j - 1))]);
			qmn[j][i] = min(qmn[j - 1][i], qmn[j - 1][i + (1 << (j - 1))]);
		}
}

int amx(int l, int r) {
	int p = lg[r - l + 1];
	return max(qmx[p][l], qmx[p][r - (1 << p) + 1]);
}

int amn(int l, int r) {
	int p = lg[r - l + 1];
	return min(qmn[p][l], qmn[p][r - (1 << p) + 1]);
}

bool check(int x) {
	int sum = 0;
	for (int i = 1; i <= n - x + 1; i++) {
		int p = amx(i, i + x - 1);
		int q = amn(i, i + x - 1);
		if (p - q >= cot)
			sum++;
	}
	return sum >= k;
}

void solve() {
	scanf("%d %d", &n, &k);
	cot = inf;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	build();
	for (int i = 1; i <= k; i++)
		cot = min(cot, amx(i, n - k + i) - amn(i, n - k + i));
	printf("%d ", cot);
	
	int l = 1, r = n - k + 1, ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (!check(mid))
			l = mid + 1;
		else {
			r = mid - 1;
			ans = mid;
		}
	}
	printf("%d\n", ans);
}

int main() {
	for (int i = 1; i < N; i++)
		lg[i] = __lg(i);

	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
