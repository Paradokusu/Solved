#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e6 + 7;
constexpr int MOD = 1e9 + 7;

int n, l;
int nxt[N], lg[20][N];
char s[N];

int main() {
	scanf("%d", &n);
	
	while (n--) {
		scanf(" %s", s + 1);
		nxt[1] = 0;
		l = strlen(s + 1);
		long long ans = 1;
		
		for (int i = 2; i <= l; i++) {
			int j = nxt[i - 1];
			while (j && s[i] != s[j + 1])
				j = nxt[j];

			if (s[i] == s[j + 1])
				nxt[i] = j + 1;
			else
				nxt[i] = 0;
			
			lg[0][i] = nxt[i];
		}
		
		for (int j = 1; j <= 20; j++)
			for (int i = 1; i <= l; i++)
				lg[j][i] = lg[j - 1][lg[j - 1][i]];

		for (int i = 2; i <= l; i++) {
			int cot = i;
			for (int j = 19; j >= 0; j--)
				if (lg[j][cot] * 2 > i)
					cot = lg[j][cot];
			
			int g = 0;
			for (int j = 19; j >= 0; j--) {
				if (lg[j][cot]) {
					g += (1 << j);
					cot = lg[j][cot];
				}
			}
			
			ans = 1ll * ans * (g + 1) % MOD;
		}
		
		printf("%lld\n", ans);
	}
	
	return 0;
}
