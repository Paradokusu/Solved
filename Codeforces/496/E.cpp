#include <bits/stdc++.h>

constexpr int N = 1e5 + 7;

int n, m;
int ans[N];

struct music {
	int a, b, id;
} a[N];

struct musician {
	int c, d, k, id;
} b[N];

struct node {
	int val, id;
	
	bool operator < (const node &x) const {
		return val < x.val;
	}
};

std::multiset<node> s;

bool cmp1(const music &x, const music &y) {
	return x.b < y.b;
}

bool cmp2(const musician &x, const musician &y) {
	return x.d < y.d;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &a[i].a, &a[i].b);
		a[i].id = i;
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &b[i].c, &b[i].d, &b[i].k);
		b[i].id = i;
	}
	
	std::sort(a + 1, a + n + 1, cmp1);
	std::sort(b + 1, b + m + 1, cmp2);
	
	int j = 1;
	for (int i = 1; i <= m; i++) {
		while (j <= n && a[j].b <= b[i].d) {
			s.insert({a[j].a, a[j].id});
			j++;
		}
		while (b[i].k) {
			auto it = s.lower_bound({b[i].c, 0});
			if (it == s.end()) break;
			ans[it -> id] = b[i].id;
			b[i].k--;
			s.erase(s.find(*it));
		}
	}
	
	for (int i = 1; i <= n; i++)
		if (!ans[i]) {
			printf("NO\n");
			exit(0);
		}
	
	printf("YES\n");
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}
