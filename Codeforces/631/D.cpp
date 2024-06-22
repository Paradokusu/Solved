#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 7;

int n, m;
int nex[N];

struct node {
	i64 l;
	char c;
	
	friend bool operator <= (const node &a, const node &b) { return (a.c == b.c) && (a.l <= b.l); }
	friend bool operator == (const node &a, const node &b) { return (a.c == b.c) && (a.l == b.l); }
} a[N], b[N];

void ex(node *arr, int &siz) {
	int cot = 0;
	for (int i = 0; i < siz; i++) {
		if (cot == 0 || arr[cot - 1].c != arr[i].c)
			arr[cot++] = arr[i];
		else
			arr[cot - 1].l += arr[i].l;
	}
	siz = cot;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%lld-%c", &a[i].l, &a[i].c);
	for (int i = 0; i < m; i++)
		scanf("%lld-%c", &b[i].l, &b[i].c);
	
	ex(a, n);
	ex(b, m);
	
	i64 ans = 0;
	if (m == 1) {
		for (int i = 0; i < n; i++) {
			if (b[0] <= a[i])
				ans += a[i].l - b[0].l + 1;
		}
	} else if (m == 2) {
		for (int i = 0; i < n - 1; i++) {
			if (b[0] <= a[i] && b[1] <= a[i + 1])
				ans++;
		}		
	} else {
		nex[1] = 0;
		for (int i = 2; i < m - 1; i++) {
			int j = nex[i - 1];
			while (j > 0 && !(b[j + 1] == b[i]))
				j = nex[j];
			if (b[j + 1] == b[i])
				j++;
			nex[i] = j;
		}
		
		for (int i = 1, j = 0; i < n - 1; i++) {
			while (j > 0 && !(b[j + 1] == a[i]))
				j = nex[j];
			if (b[j + 1] == a[i])
				j++;
			if (j == m - 2) {
				if (b[0] <= a[i - j] && b[j + 1] <= a[i + 1])
					ans++;
				j = nex[j];
			}
		}
	}
	
	printf("%lld\n", ans);
	return 0;
}
