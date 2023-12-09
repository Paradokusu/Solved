#include <bits/stdc++.h>

using namespace std;
constexpr int N = 550;

int r, c, a, b;
int g[N][N];

bool check(int num) {
	int i = 1, j = 1, tot1 = 0;
	while (j <= r) {
		int s = 1, sum = 0, tot2 = 0;	// s 指针为这刀切哪里，tot1 为横着切，tot2 为竖着切
		while (s <= c) {
			for (int k = i; k <= j; k++) sum += g[k][s];
			if (sum >= num) sum = 0, tot2++;
			s++;
		}
		if (tot2 >= b) i = j + 1, tot1++;
		j++;
	}
	if (tot1 >= a) return true;
	return false;
}

int main() {
	int left = -1, right = 0;
	scanf("%d %d %d %d", &r, &c, &a, &b);
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			scanf("%d", &g[i][j]), right += g[i][j];
	int ans = 0;
	while (left <= right) {
		int mid = (left + right) >> 1;
		if (check(mid)) ans = mid, left = mid + 1;
		else right = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}
