#include <bits/stdc++.h>

constexpr int N = 15 + 7;
constexpr int M = 100 + 7;

int K, n;
int p[N], stc[N];
double f[M][1 << 15];

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
	K = read<int>(), n = read<int>();
	
	for (int i = 1, x; i <= n; i++) {
		p[i] = read<int>();
		
		while (x = read<int>()) {
			stc[i] = stc[i] | (1 << (x - 1));
		}
	}
	
	for (int i = K; i >= 1; i--)
		for (int j = 0; j < (1 << n); j++) {
			for (int k = 1; k <= n; k++)
				if ((j & stc[k]) == stc[k])
					f[i][j] += std::max(f[i + 1][j], f[i + 1][j | (1 << (k - 1))] + p[k]);
				else
					f[i][j] += f[i + 1][j];
			
			f[i][j] /= n;
		}
	
	printf("%.6lf\n", f[1][0]);
	return 0;
}
