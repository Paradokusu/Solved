#include <bits/stdc++.h>

using namespace std;

constexpr int inf = 1e9;

int main() {
	int l = 1, r = inf, res;
	while (l <= r) {
		int mid = (l + r) >> 1;
		printf("%d\n", mid);
		fflush(stdout);
		scanf("%d", &res);
		if (res == 0) return 0;
		else if (res == -1) l = mid + 1;
		else if (res == 1) r = mid - 1;
	}
	return 0;
}
