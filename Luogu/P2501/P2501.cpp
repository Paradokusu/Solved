#include <bits/stdc++.h>

/*
* 先敲掉第一问：
* 改变最少，转换一下主语就是保留最多！！！从保留两个数的情况开始考虑
* 发现保留充分条件为 a_j - a_i >= j - i -> a_j - j >= a_i - i
* 即保留 a_i 的必要条件为 a_i 单调不降
* 设 b_i = a_i - i，求其最长不降子序列长度就是答案
* ***
* 再解决第二问：
* 找 b_i 结论
*/

using i64 = long long;

constexpr int N = 4e4 + 7;
constexpr int inf = 2147483647;

int n, lgth;
int mn[N], b[N], dp[N];	// mn: 长度为 i 的最长不降最小结尾，dp[i]: 以 i 结尾最长不降子序列长度
i64 g[N], pre[N], suf[N];	// g[i]: 最后一位是 b_i 时单调不降代价
std::vector<int> ed[N];	// 记录长度为 i 的最长不降子序列的结尾

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n;
	
	for (int i = 1, in; i <= n; i++) {
		std::cin >> in;
		b[i] = in - i;
	}
	
	b[0] = -inf;
	b[n + 1] = inf;
	
	for (int i = 1; i <= n + 1; i++) {
		int l = 0, r = lgth;
		
		while (l < r) {
			int mid = (l + r + 1) >> 1;
			
			if (mn[mid] <= b[i])
				l = mid;
			else
				r = mid - 1;
		}
		
		if (l == lgth)
			++lgth;
		
		dp[i] = l + 1;
		mn[l + 1] = b[i];
		ed[dp[i]].push_back(i);	// 记录结尾
	}
	
	ed[0].push_back(0);
	memset(g, 0x3f, sizeof(g));
	g[0] = 0;
	
	for (int i = 1; i <= n + 1; i++) {
		for (int j = 0, siz = ed[dp[i] - 1].size(); j < siz; j++) {
			int from = ed[dp[i] - 1][j];
			
			if (from > i || b[from] > b[i])
				continue;
			
			pre[from] = suf[i - 1] = 0;
			
			for (int k = from + 1; k <= i - 1; k++)
				pre[k] = pre[k - 1] + std::abs(b[k] - b[from]);
			
			for (int k = i - 2; k >= from; k--)
				suf[k] = suf[k + 1] + std::abs(b[k + 1] - b[i]);
			
			for (int k = from; k <= i - 1; k++)
				g[i] = std::min(g[i], g[from] + pre[k] + suf[k]);
		}
	}
	
	std::cout << n - lgth + 1 << "\n" << g[n + 1] << "\n";
	return 0;
}
