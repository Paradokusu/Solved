#include <bits/stdc++.h>

using namespace std;
constexpr int N = 5e3 + 5;
constexpr int Inf = 1e9;

int n;
bool a[N], b[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) { char ch; scanf(" %c ", &ch); a[i] = (ch == 'B' ? 0 : 1); }
	int minK = Inf, ansLen;
	for (int len = 1; len <= n; len++) {
		memset(b, 0, sizeof(b));
		bool x = 0, flag = 1; int cnt = 0;	// flag 记录当前长度是否有解
		for (int i = 1; i <= n; i++) {
			x ^= b[i];
			if (!(a[i] ^ x)) {	// 若当前位置为 0
				if (i + len - 1 > n) { flag = 0; break; }	// 一次翻转的长度大于剩余的长度
				x ^= 1, b[i + len] ^= 1, ++cnt;
			}
		}
		if (flag) {
			if (cnt < minK) minK = cnt, ansLen = len;
		}
	}
	printf("%d %d\n", ansLen, minK);
	return 0;
}
