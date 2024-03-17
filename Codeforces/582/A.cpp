#include <bits/stdc++.h>

using namespace std;

constexpr int N = 507;

int n, cot, ans;
int a[N], num[N * N];

std::map<int, int> mp;

int main() {
	scanf("%d", &n);
	for (int i = 1, inp; i <= n * n; i++) {
		scanf("%d", &inp);
		if (!mp[inp])
			num[++cot] = inp;
		mp[inp]++;
	}
	
	sort(num + 1, num + cot + 1);

	for (int i = cot; i >= 1 && ans < n;) {
		while (!mp[num[i]])
			i--;
		a[++ans] = num[i];	// 最大值
		mp[num[i]]--;	// gcd(num[i], num[i])
		for (int j = 1; j < ans; j++)
			mp[__gcd(num[i], a[j])] -= 2;
	}
	
	for (int i = 1; i <= ans; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
