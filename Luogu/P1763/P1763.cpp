/* 30pts */

#include <bits/stdc++.h>

using i64 = long long;
constexpr int N = 20;

i64 a, b, dep = 1;
bool flag;
std::array<i64, N> st, ans;

void dfs(i64 a, i64 b, int x) {
	if (x > dep) return;	// 层数超过了
	if (a == 1 && b > st[x - 1]) {	// 剩下 1 / b，找到答案
		st[x] = b;
		if (!flag || st[x] < ans[x])	// 答案复制
			for (int i = 1; i <= dep; i++)
				ans[i] = st[i];
		flag = true;
		return;
	}
	i64 l = std::max(b / a, st[x - 1] + 1);	// 从上一个或者 b / a 开始枚举
	i64 r = (dep - x + 1) * b / a;	// 枚举上限最优性剪枝
	if (flag && r >= ans[dep]) r = ans[dep] - 1;	// 如果有过解也可以确定上限
	for (i64 i = 1; i < r; i++) {
		st[x] = i;
		i64 gc = std::__gcd(a * i - b, b * i);
		dfs((a * i - b) / gc, b * i / gc, x + 1);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> a >> b;
	i64 c = std::__gcd(a, b);
	a /= c, b /= c, st[0] = 1;

	for (dep = 1; dep <= 10; dep++) {	// 迭代加深
		dfs(a, b, 1);
		if (flag) {
			for (int i = 1; i <= dep; i++)
				std::cout << ans[i] << " ";
			break;
		}
	}
	return 0;
}
