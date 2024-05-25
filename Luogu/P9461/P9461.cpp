#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 1e6 + 7;
constexpr int MOD = 998244353;

int n, mx;
i64 S, cnt, res, wcnt;
int x[N], fa[N];
i64 w[N], sum[N];
bool b[N];
vector<int> P[N];

int find(int x) {
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

void upd(int k) {
	b[k] = 1;
	if (b[k - 1]) fa[find(k - 1)] = find(k);
	if (b[k + 1]) fa[find(k)] = find(k + 1);
	w[find(k)] += w[k - 1] + 1;
	S += (w[k - 1] + 1) * (sum[find(k)] - sum[k - 1]) % MOD;
	S %= MOD;
	wcnt += (w[k - 1] + 1) * (find(k) - (k - 1)) % MOD;
	wcnt %= MOD;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x[i]);
		sum[i] = sum[i - 1] + x[i];
		sum[i] %= MOD;
		P[x[i]].push_back(i);
		mx = max(mx, x[i]);
		fa[i] = i;
	}
	
	for (int i = mx; i >= 2; i--) {
		for (auto k : P[i])
			upd(k);
		res += (S - wcnt * (i - 1) % MOD) * i % MOD;
		cnt += S - wcnt * (i - 1) % MOD;
		res %= MOD;
		cnt %= MOD;
	}
	
	cnt = sum[n] * (sum[n] + 1) / 2 - cnt;
	cnt %= MOD;
	res += cnt;
	res = (res % MOD + MOD) % MOD;
	
	printf("%lld\n", res);
	return 0;
}
