#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 N = 1e6 + 5;

i64 n, m;
i64 r[N], d[N], s[N], t[N], diff[N], sum[N];

i64 read();
void write(i64 x);

bool check(i64 x) {
	memset(diff, 0, sizeof(diff));
	
	for (i64 i = 1; i <= x; i++) {
		diff[s[i]] += d[i];
		diff[t[i] + 1] -= d[i];
	}
	
	for (i64 i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + diff[i];
	
		if (sum[i] > r[i])
			return false;
	}
	
	return true;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	std::cin >> n >> m;
	for (i64 i = 1; i <= n; i++)
		std::cin >> r[i];
	for (i64 i = 1; i <= m; i++)
		std::cin >> d[i] >> s[i] >> t[i];

	i64 begin = 1, end = m;
	
	if (check(m)) {
		std::cout << "0\n";
		return 0;
	}
	
	while (begin < end) {
		i64 mid = (begin + end) >> 1;
		
		if (check(mid))
			begin = mid + 1;
		else
			end = mid;
	}

	std::cout << "-1\n" << begin << "\n";
	return 0;
}
