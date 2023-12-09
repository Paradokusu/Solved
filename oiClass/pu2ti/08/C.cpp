#include <bits/stdc++.h>

#define inline inline __attribute__((always_inline))

using namespace std;
constexpr int N = 1e5 + 5;

int read();
void write(int x);

int n, ind[N];
struct node {
	int in, cnt;
} a[N];
vector<int> g[N];
queue<int> q;

void Topo() {
	for (int i = 1; i <= n; i++) { if (a[i].in == 1) { q.push(i); a[i].cnt = 1; } }
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = 0; i < g[x].size(); i++) {
			int t = g[x][i]; a[t].in--;
			if (a[t].in == 1) { a[t].cnt = a[x].cnt + 1; q.push(t); }
		}
	}
}

int main() {
	n = read();
	for (int i = 1; i <= n - 1; i++) { int u = read(), v = read(); a[u].in++, a[v].in++; g[v].push_back(u), g[u].push_back(v); }
	Topo();
	for (int i = 1; i <= n; i++) write(a[i].cnt), putchar(' ');
	return 0;
}

int read() { int x = 0, f = 1; char ch = getchar(); while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); } while (ch >= '0' && ch <= '9') { x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar(); } return x * f; }
void write(int x) { if (x < 0) putchar('-'), x = -x; if (x > 9) write(x / 10); putchar(x % 10 + '0'); }
