#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e6 + 7;

i64 n, m, k;
i64 a[N];
int nxt[N], tmp[N], ans[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> k >> m;
	
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];
	
	int head = 1, tail = k + 1;
	nxt[1] = k + 1;
	
	for (int i = 2; i <= n; i++) {
		while (tail + 1 <= n && a[i] - a[head] > a[tail + 1] - a[i])
			head++, tail++;

		if (a[i] - a[head] >= a[tail] - a[i])
			nxt[i] = head;
		else
			nxt[i] = tail;
	}
	
	for (int i = 1; i <= n; i++)
		ans[i] = i;

	while (m) {
		if (m & 1)
			for (int i = 1; i <= n; i++)
				ans[i] = nxt[ans[i]];
		
		memcpy(tmp, nxt, sizeof(tmp));
		
		for (int i = 1; i <= n; i++)
			nxt[i] = tmp[tmp[i]];
		
		m >>= 1;
	}
	
	for (int i = 1; i <= n; i++)
		std::cout << ans[i] << " ";
	
	std::cout << "\n";
	return 0;
}
