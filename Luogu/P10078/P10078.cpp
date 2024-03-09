#include <bits/stdc++.h>

constexpr int N = 1e6 + 7;
constexpr int inf = 2147483647;

int n, Max, Min;
int mxn[N], mnn[N];

struct node {
	int x, y, id;
} p[N];

std::bitset<N> flg;

bool cmpx(const node &a, const node &b) {
	return a.x < b.x;
}

bool cmpy(const node &a, const node &b) {
	return a.y < b.y;
}

void Update(int x) {
	Max = std::max(Max, x);
	Min = std::min(Min, x);
}

bool Check(int x, int i) {
	// 挡没挡住
	
	if (mxn[i] > x && Min <= x)
		return 1;
	
	if (mnn[i] < x && Max >= x)
		return 1;
	
	if (Max >= x && Min <= x)
		return 1;
	
	return 0;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	std::cin >> n;
	
	for (int i = 1; i <= n; i++) {
		std::cin >> p[i].x >> p[i].y;
		p[i].id = i;
	}
	
	std::sort(p + 1, p + n + 1, cmpy);
	Max = -inf, Min = inf;
	
	/* 预处理 y 坐标相同的情况 */
	for (int i = 1; i <= n; i++) {
		mxn[i] = mnn[i] = p[i].x;
		
		if (i > 1 && p[i].y == p[i - 1].y) {
			mxn[i] = std::max(mxn[i], mxn[i - 1]);
			mnn[i] = std::min(mnn[i], mnn[i - 1]);
		}
	}
	
	for (int i = n - 1; i; i--) {
		if (p[i].y == p[i + 1].y) {
			mxn[i] = mxn[i + 1];
			mnn[i] = mnn[i + 1];
		}
	}
	
	for (int i = 1; i <= n; i++) {	// 下
		int l = i - 1;
		
		while (l > 0 && p[l].y == p[i - 1].y && p[l].y != p[i].y) {
			Update(p[l].x);
			l--;
		}
		
		if (!Check(p[i].x, i)) {
			flg[p[i].id] = 1;
		}
	}
	
	Max = -inf, Min = inf;
	
	for (int i = n; i; i--) {	// 上
		int l = i + 1;
		
		while (l <= n && p[l].y == p[i + 1].y && p[l].y != p[i].y) {
			Update(p[l].x);
			l++;
		}
		
		if (!Check(p[i].x, i)) {
			flg[p[i].id] = 1;
		}
	}
	
	std::sort(p + 1, p + n + 1, cmpx);
	
	/* 预处理 x 坐标相同的情况 */
	for (int i = 1; i <= n; i++) {
		mxn[i] = mnn[i] = p[i].y;
		
		if (i > 1 && p[i].x == p[i - 1].x) {
			mxn[i] = std::max(mxn[i], mxn[i - 1]);
			mnn[i] = std::min(mnn[i], mnn[i - 1]);
		}
	}
	
	for (int i = n - 1; i; i--) {
		if (p[i].x == p[i + 1].x) {
			mxn[i] = mxn[i + 1];
			mnn[i] = mnn[i + 1];
		}
	}

	Max = -inf, Min = inf;
	
	for (int i = 1; i <= n; i++) {	// 左
		int l = i - 1;
		
		while (l > 0 && p[l].x == p[i - 1].x && p[l].x != p[i].x) {
			Update(p[l].y);
			l--;
		}
		
		if (!Check(p[i].y, i)) {
			flg[p[i].id] = 1;
		}
	}
	
	Max = -inf, Min = inf;
	
	for (int i = n; i; i--) {	// 右
		int l = i + 1;
		
		while (l <= n && p[l].x == p[i + 1].x && p[l].x != p[i].x) {
			Update(p[l].y);
			l++;
		}
		
		if (!Check(p[i].y, i)) {
			flg[p[i].id] = 1;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (flg[i])
			std::cout << "1";
		else
			std::cout << "0";
	}
	
	std::cout << "\n";
	return 0;
}
