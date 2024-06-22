#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 3e5 + 7;

int T, n, t0t;
int bgt, lst;
int a[N], d[N];
bool flg[N];

std::set<int> al, de;

struct node {
	int pre, nxt;
} l[N];

void solve() {
	scanf("%d", &n);
	t0t = lst = n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (i == 1) l[i].pre = -1;
		else l[i].pre = i - 1;
		if (i == n) l[i].nxt = -1;
		else l[i].nxt = i + 1;
	}
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &d[i]);
		al.insert(i);
		flg[i] = 1;
	}
	
	for (int k = 1; k <= n; k++) {
		if (t0t != 0 && t0t != 1) {
			de.clear();
			for (auto it = al.begin(); it != al.end(); it++) {
				if (d[*it] - a[l[*it].pre] - a[l[*it].nxt] < 0) {
					de.insert(*it);
					flg[*it] = 0;
				}
			}
			
			al.clear();
			for (auto it = de.begin(); it != de.end(); it++) {
				l[l[*it].pre].nxt = l[*it].nxt;
				l[l[*it].nxt].pre = l[*it].pre;
				if (flg[l[*it].pre]) al.insert(l[*it].pre);
				if (flg[l[*it].nxt]) al.insert(l[*it].nxt);
				t0t--;
			}
		}
		printf("%d ", lst - t0t);
		lst = t0t;
	}
	
	printf("\n");
}

int main() {
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}

