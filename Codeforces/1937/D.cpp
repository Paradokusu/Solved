#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::string s;
	std::cin >> n >> s;
	std::vector<i64> sl(n + 1), sr(n + 1), idl(n + 1), idr(n + 1);
	
	for (int i = 1; i <= n; i++) {
		sr[i] = sr[i - 1] + (s[i - 1] == '>');
		sl[i] = sl[i - 1] + (s[i - 1] == '<');
		idr[i] = idr[i - 1] + i * (s[i - 1] == '>');
		idl[i] = idl[i - 1] + i * (s[i - 1] == '<');
	}
	
	std::function<int(int)> FindPre = [&](int x) {
		int l = 0, r = n + 1;
		
		while (l + 1 != r) {
			int mid = (l + r) / 2;
			
			if (sr[mid] < x)
				l = mid;
			else
				r = mid;
		}
		
		return r;
	};
	
	std::function<int(int)> FindSuf = [&](int x) {
		int l = 0, r = n + 1;
		
		while (l + 1 != r) {
			int mid = (l + r) / 2;
			
			if (sl[n] - sl[mid - 1] < x)
				r = mid;
			else
				l = mid;
		}
		
		return l;
	};
	
	for (int i = 1; i <= n; i++) {
		if (s[i - 1] == '>') {
			if (sr[i] > sl[n] - sl[i]) {
				int p = FindPre(sr[i] - (sl[n] - sl[i]));
				std::cout << 2 * ((idl[n] - idl[i]) - (idr[i] - idr[p - 1])) + i + (n + 1) << " ";
			} else {
				int p = FindSuf((sl[n] - sl[i]) - sr[i] + 1);
				std::cout << 2 * ((idl[p] - idl[i]) - (idr[i] - idr[0])) + i << " ";
			}
		} else {
			if (sr[i] >= sl[n] - sl[i - 1]) {
				int p = FindPre(sr[i] - (sl[n] - sl[i - 1]) + 1);
				std::cout << 2 * ((idl[n] - idl[i- 1]) - (idr[i] - idr[p - 1])) - i + (n + 1) << " ";
			} else {
				int p = FindSuf((sl[n] - sl[i - 1]) - sr[i]);
				std::cout << 2 * ((idl[p] - idl[i - 1]) - (idr[i] - idr[0])) - i << " ";
			}
		}
	}
	
	std::cout << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	int t;
	std::cin >> t;
	
	while (t--) {
		solve();
	}
	
	return 0;
}
