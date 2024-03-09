#include <bits/stdc++.h>

constexpr int N = 40007;

int n, m, tot;
int block, num, bid[N], L[N], R[N];
int a[N], val[N], cnt[N];
int t[4007][4007];

std::map<int, int> mp;
std::vector<int> v[N];

template <typename T> T read() {
	T sum = 0, fl = 1;
	int ch = getchar();
	for (; !isdigit(ch); ch = getchar()) { if (ch == '-') fl = -1; }
	for (; isdigit(ch); ch = getchar()) sum = sum * 10 + ch - '0';
	return sum * fl;
}

template <typename T> void write(T x) {
	if (x < 0) { x = -x; putchar('-'); }
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}


void Pre(int x) {
	memset(cnt, 0, sizeof(cnt));
	int mx = 0, id = 0;
	
	for (int i = L[x]; i <= n; i++) {
		cnt[a[i]]++;
		
		if (cnt[a[i]] > mx || (cnt[a[i]] == mx && val[a[i]] < val[id])) {
			mx = cnt[a[i]];
			id = a[i];
		}
		
		t[x][bid[i]] = id;
	}
}

void Build() {
	block = 30;
	num = n / block;
	
	if (n % block) {
		num++;
	}
	
	for (int i = 1; i <= num; i++) {
		L[i] = (i - 1) * block + 1;
		R[i] = i * block;
	}
	
	R[num] = n;
	
	for (int i = 1; i <= n; i++) {
		bid[i] = (i - 1) / block + 1;
	}
	
	for (int i = 1; i <= num; i++) {
		Pre(i);
	}
}

int SrhAns(int l, int r, int x) {
	return std::upper_bound(v[x].begin(), v[x].end(), r) - std::lower_bound(v[x].begin(), v[x].end(), l);
}

int Query(int l, int r) {
	int mx = 0, id = t[bid[l] + 1][bid[r] - 1];
	mx = SrhAns(l, r, id);
	
	if (bid[l] == bid[r]) {
		for (int i = l; i <= r; i++) {
			int x = SrhAns(l, r, a[i]);
			
			if (x > mx || (x == mx && val[a[i]] < val[id])) {
				mx = x;
				id = a[i];
			}
		}
		
		return id;
	}
	
	for (int i = l; i <= R[bid[l]]; i++) {
		int x = SrhAns(l, r, a[i]);
		
		if (x > mx || (x == mx && val[a[i]] < val[id])) {
			mx = x;
			id = a[i];
		}
	}
	
	for (int i = L[bid[r]]; i <= r; i++) {
		int x = SrhAns(l, r, a[i]);
		
		if (x > mx || (x == mx && val[a[i]] < val[id])) {
			mx = x;
			id = a[i];
		}
	}
	
	return id;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	n = read<int>(), m = read<int>();
	
	for (int i = 1; i <= n; i++) {
		a[i] = read<int>();
		
		if (mp[a[i]] == 0) {
			mp[a[i]] = ++tot;
			val[tot] = a[i];
		}
		
		a[i] = mp[a[i]];
		v[a[i]].push_back(i);
	}
	
	Build();
	
	int ans = 0;
	
	while (m--) {
		int l = read<int>(), r = read<int>();
		
		l = (l + ans - 1) % n + 1;
		r = (r + ans - 1) % n + 1;
		
		if (l > r) {
			std::swap(l, r);
		}

		ans = val[Query(l, r)];		
		write<int>(ans);
		puts("");
	}
	
	return 0;
}
