#include <bits/stdc++.h>

using namespace std;
using i128 = __int128;

constexpr int N = 105;

int l, t;
i128 s;
char k, a[N], x[N], y[N];
bool b[N];

template <typename T>
void write(T x) {
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}

void dfs(char c) {
	if (b[c]) return;
	b[c] = 1;
	for (int i = 0; i < k; i++)
		if (x[i] == c)
			dfs(y[i]);
}

int main() {
	scanf("%s %d", a, &k);
	l = strlen(a);
	
	for (int i = 0; i < k; i++)
		scanf(" %c %c", &x[i], &y[i]);
	
	dfs(a[0]);
	b[0] = 0;
	
	for (char i = '1'; i <= '9'; i++)
		t += b[i], b[i] = 0;

	s = t, t = 0;
	
	for (int i = 1; i < l; i++) {
		dfs(a[i]);
		for (char i = '0'; i <= '9'; i++)
			t += b[i], b[i] = 0;
		s *= t, t = 0;
	}
	
	write(s);
	return 0;
}
