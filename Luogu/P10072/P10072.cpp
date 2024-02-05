#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 7;

int n, m, sum, cnt = 1;
int a[N], b[N];
long long ans;

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

int main() {
	n = read<int>(), m = read<int>();
	
	for (int i = 1; i <= n; i++)
		a[i] = read<int>();
	sort(a + 1, a + n + 1);
	
	while (m > 0 && n - cnt >= 2) {
		sum++;
		m--;
		while (a[cnt] - sum <= 0)
			cnt++;
		ans += n - cnt + 1;
	}
	
	if (m > 0) {
		if (a[cnt - 2] == 1) {
			m--;
			cnt = n - 1;
			ans++;
		}
	}
	
	while (m > 0) {
		a[cnt] -= 2;
		m--;
		if (a[cnt] - sum > 0)
			ans += n - cnt + 1;
		else
			ans += n - cnt++;
	}
	
	if (m > 0) {
		if (a[cnt - 2] == 1) {
			m--;
			cnt = n - 1;
			ans++;
		}
	}
	
	while (m > 0) {
		a[cnt] -= 2;
		m--;
		if (a[cnt] - sum > 0)
			ans += n - cnt + 1;
		else
			ans += n - cnt++;
	}
	
	while (cnt <= n) {
		ans += 1ll * (n - cnt + 1) * (a[cnt] - sum - 1) + (n - cnt);
		cnt++;
	}
	
	write<long long>(ans);
	return 0;
}
