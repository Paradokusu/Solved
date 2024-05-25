#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e3 + 7;
constexpr int inf = numeric_limits<int>::max();

int n, lst;
int a[N], mn[N], col[N];
bool flg;

stack<int> s1, s2;

struct edge {
	int to, nxt;
} e[N << 1];

int tot, head[N];
void addedge(int u, int v) {
	e[++tot].to = v, e[tot].nxt = head[u];
	head[u] = tot;
}

void dfs(int u) {
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (!col[v]) {
			if (col[u] == 1) col[v] = 2;
			else col[v] = 1;
			dfs(v);
		} else {
			if (col[v] == col[u]) flg = 1;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	mn[n + 1] = inf;
	for (int i = n; i; i--)
		mn[i] = min(mn[i + 1], a[i]);
	
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (a[i] < a[j] && mn[j + 1] < a[i]) {
				addedge(i, j);
				addedge(j, i);
			}
		}
	}
	
	for (int i = 1; i <= n; i++)
		if (!col[i]) {
			col[i] = 1;
			dfs(i);
		}
	
	if (flg) {
		printf("0\n");
		exit(0);
	}
	
	for (int i = 1; i <= n; i++) {
		if (col[i] == 1) {
			while (!s1.empty() && (a[i] > s1.top())) {
				while (!s2.empty() && (s2.top() == lst + 1)) {
					lst++;
					s2.pop();
					printf("d ");
				}
				lst = max(lst, s1.top());
				s1.pop();
				printf("b ");
			}
			s1.push(a[i]);
			printf("a ");
		} else {
			while (!s1.empty() && (s1.top() == lst + 1)) {
				lst++;
				s1.pop();
				printf("b ");
			}
			while (!s2.empty() && a[i] > s2.top())  {
				lst = max(lst, s2.top());
				s2.pop();
				printf("d ");
			}
			while (!s1.empty() && s1.top() == lst + 1) {
				lst++;
				s1.pop();
				printf("b ");
			}
			s2.push(a[i]);
			printf("c ");
		}
	}
	
	for (int i = 1; i <= 2; i++) {
		while (!s1.empty() && (s1.top() == lst + 1)) {
			lst++;
			s1.pop();
			printf("b ");
		}
		while (!s2.empty() && (s2.top() == lst + 1)) {
			lst++;
			s2.pop();
			printf("d ");
		}
	}
	
	return 0;
}
