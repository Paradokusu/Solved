#include <bits/stdc++.h>

using namespace std;

constexpr int N = 5e5 + 7;
constexpr int B1 = 19260817;
constexpr int B2 = 20190529;

int n, q, pct;
char s[N];
int p[N], mx[N], stc[N];
int base[N], myhash[N];
bool vis[N];

int mixhash(int l, int r) {
	return myhash[r] - base[r - l + 1] * myhash[l - 1];
}

int main() {
	scanf("%d", &n);
	scanf(" %s", s + 1);
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) {
			p[++pct] = i;
			mx[i] = i;
		}
		for (int j = 1; j <= pct && i * p[j] <= n; j++) {
			vis[i * p[j]] = 1;
			mx[i * p[j]] = p[j];
			if (!(i % p[j]))
				break;
		}
	}
	
	base[0] = 1;
	for (int i = 1; i <= n; i++) {
		base[i] = base[i - 1] * B1 * B2;
		myhash[i] = myhash[i - 1] * B1 * B2 + s[i] - 'a' + 1;
	}
	
	scanf("%d", &q);
	while (q--) {
		int l, r;
		scanf("%d %d", &l, &r);
		int len = r - l + 1, top = 0;
		while (len ^ 1) {
			stc[++top] = mx[len];
			len /= mx[len];
		}
		len = r - l + 1;
		for (int i = 1; i <= top; i++) {
			int tmp = len / stc[i];
			if (mixhash(l, r - tmp) == mixhash(l + tmp, r))
				len /= stc[i];
		}
		printf("%d\n", len);
	}
	
	return 0;
}
