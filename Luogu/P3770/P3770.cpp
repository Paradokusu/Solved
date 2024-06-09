#include <bits/stdc++.h>

constexpr int N = 2e7 + 7;

int n, k, S;
int seed, tot, now, st;
int res1, res2, res3;
int p[N], idx[N], npi[N];
int arr[N], pre[N];

int getrand() {
	seed = ((seed * 12321) ^ 9999) % 32768;
	return seed;
}

void generateData() {
	std::cin >> k >> seed >> S;
	int t = 0;
	n = k * 2 + 1;
	memset(p, 0, sizeof(p));
	
	for (int i = 1; i <= n; ++i) {
		p[i] = (getrand() / 128) % 2;
		t += p[i];
	}
	
	int i = 1;
	
	while (t > k) {
		while (p[i] == 0)
			++i;
		
		p[i] = 0;
		--t;
	}
	
	while (t < k) {
		while (p[i] == 1)
			++i;
		p[i] = 1;
		++t;
	}
}

void sol(int pt) {
	if (tot == 0)
		res1 = idx[pt];
	
	if (tot == S)
		res2 = idx[pt];
	
	if (tot == k - S)
		res3 = idx[pt];
	
	if (res1 && res2 && res3) {
		std::cout << res1 << "\n" << res2 << "\n" << res3 << "\n";
		exit(0);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	generateData();
	
	for (int i = 1; i <= n; i++)
		if (!p[i]) {
			st = i;
			break;
		}
	
	for (int i = 1; i <= n; i++) {
		idx[i] = st;
		npi[i] = p[st++];
		
		if (st > n)
			st = 1;
	}
	
	for (int i = 2; i <= n; i++)
		pre[i] = (pre[i - 1]) + (npi[i] ? 1 : -1);
	
	for (int i = 2; i <= n; i++)
		if (npi[i])
			arr[pre[i] + k]++;
	
	for (int i = k + 1; i <= 2 * k; i++)
		tot += arr[i];
	
	sol(1);
	now = k;
	
	for (int i = 2; i <= n; i++) {
		if (npi[i]) {
			++now;
			tot -= arr[now];
			arr[pre[i] + k]--;
			arr[pre[i] + k - 1]++;
		} else {
			tot += arr[now--];
			sol(i);
		}
	}
	
	return 0;
}
