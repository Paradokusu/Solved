#include <bits/stdc++.h>

constexpr int N = 2e4 + 7;
constexpr int M = 1e5 + 7;

int n, m;
int fa[N], b[N];

struct node {
	int x, y, z;
} f[M];

bool cmp(const node &a, const node &b) {
	return a.z > b.z;
}

int Find(int x) {
	if (x != fa[x])
		return fa[x] = Find(fa[x]);

	return x;
}

void Add(int x, int y) {
	x = Find(x);
	y = Find(y);
	fa[x] = y;
}

bool Check(int x, int y) {
	x = Find(x);
	y = Find(y);
	
	if (x == y)
		return 1;

	return 0;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	std::cin >> n >> m;
	std::iota(fa + 1, fa + n + 1, 1);

	for (int i = 1; i <= m; i++) {
		std::cin >> f[i].x >> f[i].y >> f[i].z;	
	}
	
	std::sort(f + 1, f + m + 1, cmp);
	
	for (int i = 1; i <= m + 1; i++) {
		if (Check(f[i].x, f[i].y)) {
			std::cout << f[i].z << "\n";
			break;
		} else {
			if (!b[f[i].x])
				b[f[i].x] = f[i].y;
			else
				Add(b[f[i].x], f[i].y);
			
			if (!b[f[i].y])
				b[f[i].y] = f[i].x;
			else
				Add(b[f[i].y], f[i].x);
		}
	}
	
	return 0;
}
