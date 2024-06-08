#include <bits/stdc++.h>

using namespace std;

constexpr int N = 5e3 + 7;
constexpr int D = 207;

int d, n, m;
int weight[N];
int w[D][N], fa[D][N], siz[D][N];

struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		x ^= x << 13;
		x ^= x >> 7;
		x ^= x << 17;
		return x; 
	}
	size_t operator () (uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); // 时间戳
		return splitmix64(x + FIXED_RANDOM);
	}
};

unordered_map<int, int, custom_hash> Map;
vector<int> v[D][N];

random_device rdv;
mt19937_64 myrand(rdv());

int find(int k, int x) {
	if (fa[k][x] != x) {
		fa[k][x] = find(k, fa[k][x]);
		return fa[k][x];
	}
	
	return x;
}

int main() {
	scanf("%d %d %d", &d, &n, &m);
	for (int i = 1; i <= d; i++) {
		for (int j = 1; j <= n; j++) {
			w[i][j] = myrand() * myrand() % myrand();
			weight[j] += w[i][j];
			v[i][j].emplace_back(j);
			fa[i][j] = j;
			siz[i][j] = 1;
		}
	}
	
	for (int i = 1; i <= n; i++)
		Map[weight[i]]++;

	int ans = n;
	for (int i = 1; i <= m; i++) {
		int x, y, k;
		scanf("%d %d %d", &x, &y, &k);
		int fx = find(k, x), fy = find(k, y);
		
		if (fx == fy) {
			printf("%d\n", ans);
			continue;
		}
		
		if (siz[k][fx] > siz[k][fy]) swap(fx, fy);
		fa[k][fx] = fy;
		siz[k][fy] += siz[k][fx];
		
		for (auto i : v[k][fx]) {
			ans -= (--Map[weight[i]]) * 2;
			weight[i] -= w[k][fx];
			weight[i] += w[k][fy];
			ans += Map[weight[i]] * 2;
			Map[weight[i]]++;
			v[k][fy].push_back(i);
		}
		
		v[k][fx].clear();
		printf("%d\n", ans);
	}
	
	return 0;
}
