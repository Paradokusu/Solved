#include <bits/stdc++.h>

struct node {
	int id, st, re, pr;
	
	bool operator < (const node &a) const {
		if (pr == a.pr)
			return st > a.st;
		
		return pr < a.pr;
	}
};

long long tot_time;
node c;
std::priority_queue<node> q;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	while (std::cin >> c.id >> c.st >> c.re >> c.pr) {
		while (!q.empty() && tot_time + q.top().re <= c.st) {
			node t = q.top();
			q.pop();
			std::cout << t.id << " " << tot_time + t.re << "\n";
			tot_time += t.re;
		}
		
		if (!q.empty()) {
			node t = q.top();
			q.pop();
			t.re = t.re - c.st + tot_time;
			q.push(t);
		}
		
		q.push(c);
		tot_time = c.st;
	}
	
	while (!q.empty()) {
		node t = q.top();
		q.pop();
		tot_time += t.re;
		std::cout << t.id << " " << tot_time << "\n";
	}
	
	return 0;
}
