#include <bits/stdc++.h>

constexpr int N = 5e3 + 50;

struct node {
	int x, y;
};

std::array<node, N> s;

int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

void write(int x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

bool cmp1(const node &a, const node &b) {		// 按横坐标排序
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

bool cmp2(const node &a, const node &b) {		// 按纵坐标排序
	if (a.y != b.y) return a.y < b.y;
	return a.x < b.x;
}

void solve() {
	constexpr int INF = 1e9;
	int l = read(), w = read(), n = read();
	for (int i = 1; i <= n; i++)
		s[i].x = read(), s[i].y = read();

	// 将四个顶点的坐标预处理为障碍
	s[++n].x = 0, s[n].y = 0;
	s[++n].x = 0, s[n].y = w;
	s[++n].x = l, s[n].y = 0;
	s[++n].x = l, s[n].y = w;

	int X1, X2, Y1, Y2;	// 左边界，右边界，下边界，上边界
	int ans = -INF;
	std::sort(s.begin() + 1, s.begin() + n + 1, cmp1);
	for (int i = 1; i <= n; i++) {		// 从左往右
		X1 = s[i].x, Y1 = 0, Y2 = w;
		for (int j = i + 1; j <= n; j++) {
			X2 = s[j].x;
			ans = std::max(ans, (X2 - X1) * (Y2 - Y1));
			if (s[j].y < s[i].y) Y1 = std::max(Y1, s[j].y);
			else Y2 = std::min(Y2, s[j].y);
		}
	}
	for (int i = n ; i >= 1; i--) {		// 从右往左
		X1 = s[i].x, Y1 = 0, Y2 = w;
		for (int j = i - 1; j >= 1; j--) {
			X2 = s[j].x;
			ans = std::max(ans, (X1 - X2) * (Y2 - Y1));
			if (s[j].y < s[i].y) Y1 = std::max(Y1, s[j].y);
			else Y2 = std::min(Y2, s[j].y);
		}
	}

	// 处理特殊左右边界为边界的情况
	std::sort(s.begin() + 1, s.begin() + n + 1, cmp2);
	for (int i = 1; i <= n - 1; i++)
		ans = std::max(ans, l * (s[i + 1].y - s[i].y));

	write(ans);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	solve();
	return 0;
}
