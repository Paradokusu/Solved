#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5 + 5e4 + 7;

int n;
i64 sum, ans;

struct node {
	i64 t1, t2;
} a[N];

std::priority_queue<i64> q;

bool cmp(const node &x, const node &y) {
	return x.t2 < y.t2;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n;
	
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i].t1 >> a[i].t2;
	}
	
	std::sort(a + 1, a + n + 1, cmp);
	
	for (int i = 1; i <= n; i++) {
		sum += a[i].t1;
		q.push(a[i].t1);
		
		if (sum <= a[i].t2) {	// 可修理就修理
			ans++;
		} else {	// 否则将耗时最长的建筑直接报废
			sum -= q.top();
			q.pop();
		}
	}
	
	std::cout << ans << "\n";
	return 0;
}
