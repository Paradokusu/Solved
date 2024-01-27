#include <bits/stdc++.h>

constexpr int N = 5e3 + 7;
constexpr int D = 207;

int d, n, m;
int weight[N];
int w[D][N], fa[D][N], siz[D][N];

std::unordered_map<int, int> Map;
std::vector<int> v[D][N];

std::mt19937 myRand(time(nullptr));

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
			w[i][j] = myRand() * myRand() % myRand();
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
		
		if (siz[k][fx] > siz[k][fy]) std::swap(fx, fy);
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
