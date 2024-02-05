#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e6 + 7;
constexpr int inf = 19260817;

int n, m;
int top, t1a, t1b, t2a, t2b;
int cst[N], v[N], dp[N];

struct node {
	int a, b, c;
} k[N];

void work() {
	for (int i = 1; i <= n; i++) {
		int t = 1;
		while (k[i].c != 0) {
			cst[++top] = k[i].a * t;
			v[top] = k[i].b * t;
			k[i].c -= t;
			t *= 2;
			
			if (k[i].c < t) {
				cst[++top] = k[i].a * k[i].c;
				v[top] = k[i].b * k[i].c;
				break;
			}
		}
	}
}

int main() {
	scanf("%d:%d %d:%d", &t1a, &t1b, &t2a, &t2b);
	if (t1b > t2b) {
		t2b += 60;
		t2a--;
	}
	m = (t2a - t1a) * 60 + t2b - t1b;
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &k[i].a, &k[i].b, &k[i].c);
		if (!k[i].c)
			k[i].c = inf;
	}
	
	work();
	
	for (int i = 1; i <= top; i++)
		for (int j = m; j >= cst[i]; j--)
			dp[j] = max(dp[j], dp[j - cst[i]] + v[i]);
	
	printf("%d\n", dp[m]);
	return 0;
}
