#include <bits/stdc++.h>

constexpr int N = 50007;

int n;
int ans[N];

struct COW {
	int id, l, r, ans;
} cow[N];

bool cmp(const COW &a, const COW &b) {
	return a.l < b.l;
}

std::priority_queue<std::pair<int, int>> s;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		cow[i].id = i;
		std::cin >> cow[i].l >> cow[i].r;
	}
	
	std::sort(cow + 1, cow + n + 1, cmp);
	
	for (int i = 1; i <= n; i++) {
		int num = s.size();
		if (num && -s.top().first < cow[i].l) {
			cow[i].ans = s.top().second;
			s.pop();
			s.push({-cow[i].r, cow[i].ans});
			continue;
		}
		
		cow[i].ans = ++num;
		s.push({-cow[i].r, num});
	}
	
	std::cout << s.size() << "\n";
	for (int i = 1; i <= n; i++)
		ans[cow[i].id] = cow[i].ans;
	for (int i = 1; i <= n; i++)
		std::cout << ans[i] << "\n";
	
	return 0;
}
