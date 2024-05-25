#include <bits/stdc++.h>

using namespace std;

constexpr int N = 8e4 + 7;

int n, top, head;
long long ans;
int stc[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &head);
		while (top > 0 && head >= stc[top])
			top--;
		ans += top;
		top++;
		stc[top] = head;
	}
	printf("%lld\n", ans);
	return 0;
}
