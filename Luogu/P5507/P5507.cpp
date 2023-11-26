#include <bits/stdc++.h>

constexpr int N = 1 << 24;

std::array<int, N> g, fa, ans, choice;
std::array<std::array<int, 5>, 15> nxt;

struct node {
	int state;	// 状态
	double F;	// 估价函数对应函数值

	node (int s) : state(s) {	// 构造函数，相当于 node(int s): state = s
		/* 估价函数 - A* 的精髓 */
		double h = 0;
		F = 0;
		for (int i = 0; i < 12; i++)
			if ((s >> (i * 2)) & 3)	//计算不出在状态 1 的旋钮对应的 h 值
				h += 4 - ((s >> (i * 2) & 3));
		F = h + g[s];	// 计算估价函数
	}

	bool operator < (const node &y) const {
		return F > y.F;	// 估价函数值小的有限
	}
};

std::priority_queue<node> q;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	int button, start = 0;
	for (int i = 0; i < 12; i++) {
		std::cin >> button;	// 读入  i + 1 个旋钮的位置
		start |= (button - 1) << (i * 2);	// 记录初始状态
		for (int j = 0; j < 4; j++) {
			std::cin >> nxt[i][j];
			nxt[i][j] -= 1;
		}
	}
	q.push(node(start));
	g[start] = 0;
	while (!q.empty()) {
		int state = q.top().state;
		q.pop();
		if (state == 0) break;
		int si, sNxt, nx, nextState;
		for (int i = 0; i < 12; i++) {
			si = (state >> (i * 2)) & 3;	// 第 i 个按钮的状态
			nx = nxt[i][si];	// 受牵连的按钮
			sNxt = (state >> (nx * 2)) & 3;	// 受牵连的按钮的状态
			nextState = state ^ (si << (i * 2)) ^ (((si + 1) & 3) << (i * 2));
			nextState = nextState ^ (sNxt << (nx * 2)) ^ (((sNxt + 1) & 3) << (nx * 2));
			// 没有访问过，转移新状态
			if (!g[nextState]) {
				g[nextState] = g[state] + 1;
				fa[nextState] = state;	// 记录操作路径
				choice[nextState] = i + 1;	// 记录操作按钮
				q.push(node(nextState));
			}
		}
	}
	int cnt = 0, state = 0;
	while (state != start) {
		ans[++cnt] = choice[state];
		state = fa[state];
	}
	std::cout << cnt << "\n";
	for (int i = cnt; i; i--)
		std::cout << ans[i] << " ";
	return 0;
}
