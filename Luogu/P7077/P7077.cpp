#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 1e6 + 7;
constexpr int M = N << 1;
constexpr int MOD = 998244353;

template <typename T> T read() {
	T sum = 0, fl = 1;
	int ch = getchar();
	for (; !isdigit(ch); ch = getchar()) { if (ch == '-') fl = -1; }
	for (; isdigit(ch); ch = getchar()) sum = sum * 10 + ch - '0';
	return sum * fl;
}

template <typename T> void write(T x) {
	if (x < 0) { x = -x; putchar('-'); }
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

int n, m, Q, bn, idx;
int f[N], ind[N], ord[N];
int head[N], pre[M], to[M];

i64 a[N];

vector<int> g[M];
queue<int> q;

struct opr {
	int tp, p;
	i64 v, mul, sum;
} b[N];


void AddEdge(const int u, const int v) {
	pre[++idx] = head[u];
	head[u] = idx;
	to[idx] = v;
	ind[v]++;
}

void Topo() {
	for (int i = 1; i <= m; i++)
		if (!ind[i])
			q.push(i);

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		ord[++bn] = x;
		for (int i = head[x]; i; i = pre[i]) {
			int y = to[i];
			ind[y]--;
			if (!ind[y])
				q.push(y);
		}
	}
}

void Getmul() {
	for (int i = m; i; i--) {
		int x = ord[i];
		for (int j = head[x]; j; j = pre[j]) {
			int y = to[j];
			b[x].mul = b[x].mul * b[y].mul % MOD;
		}
	}
}

void Getsum() {
	for (int i = 1; i <= m; i++) {
		int x = ord[i];
		i64 now = 1;

		for (int j = head[x]; j; j = pre[j]) {
			int y = to[j];
			b[y].sum = (b[y].sum + b[x].sum * now % MOD) % MOD;
			now = now * b[y].mul % MOD;
		}
	}
}

int main() {
	// freopen("call.in", "r", stdin);
	// freopen("call.out", "w", stdout);

	n = read<int>();
	for (int i = 1; i <= n; i++)
		a[i] = read<int>();
	m = read<int>();
	for (int i = 1; i <= m; i++) {
		b[i].tp = read<int>();
		if (b[i].tp == 1) {
			b[i].p = read<int>();
			b[i].v = read<int>();
			b[i].mul = 1;
		} else if (b[i].tp == 2) {
			b[i].v = read<int>();
			b[i].mul = b[i].v;
		} else {
			b[i].p = read<int>();
			b[i].mul = 1;
			for (int j = 1, x; j <= b[i].p; j++) {
				x = read<int>();
				AddEdge(i, x);
			}
		}
	}

	Topo();
	Getmul();

	Q = read<int>();
	i64 now = 1;

	for (int i = 1; i <= Q; i++)
		f[i] = read<int>();
	for (int i = Q; i; i--) {
		int x = f[i];
		b[x].sum = (b[x].sum + now) % MOD;
		now = now * b[x].mul % MOD;
	}

	Getsum();

	for (int i = 1; i <= n; i++)
		a[i] = a[i] * now % MOD;

	for (int i = 1; i <= m; i++) {
		if (b[i].tp == 1) {
			a[b[i].p] = (a[b[i].p] + b[i].v * b[i].sum % MOD) % MOD;
		}
	}

	for (int i = 1; i <= n; i++) {
		write<i64>(a[i]);
		putchar(' ');
	}

	puts("");
	return 0;
}
