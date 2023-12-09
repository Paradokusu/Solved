#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1e5;

int n;
vector<int> v[N + 5];

int check(int x) {
	int res = 0, tot = v[0].size();
	vector<int> tmp;
	for (int i = 1; i <= N; i++) {
		int j = 0, k = v[i].size();
		while (k >= x) res += v[i][j++], --k, ++tot;
		while (j < v[i].size()) tmp.push_back(v[i][j++]);
	}
	sort(tmp.begin(), tmp.end());
	for (int i = 0; i < tmp.size(); i++) {
		if (tot >= x) break;
		res += tmp[i], ++tot;
	}
	return res;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int p, c;
		scanf("%d %d", &p, &c);
		v[p].push_back(c);
	}
	for (int i = 1; i <= N; i++)
		sort(v[i].begin(), v[i].end());

	int l = 1, r = n;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid) < check(mid + 1)) r = mid - 1;
		else l = mid + 1;
	}
	printf("%d\n", check(l));
	return 0;
}
