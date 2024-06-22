#include <bits/stdc++.h>

constexpr int N = 2e6 + 7;

int n;
int ansLen, inLen, wLen;
int nex[N];
char ans[N], c[N];

int main() {
	scanf("%d", &n);
	for (int t = 1; t <= n; t++) {
		scanf(" %s", c + 1);
		
		inLen = strlen(c + 1);
		wLen = std::min(ansLen, inLen);
		int pos = inLen;
		c[++pos] = '$';
		nex[0] = nex[1] = 0;
		
		for (int i = 1; i <= wLen; i++)
			c[++pos] = ans[ansLen - (wLen - i)];
		
		for (int i = 1; i <= pos; i++) {
			int j = nex[i];
			while (j && c[i + 1] != c[j + 1])
				j = nex[j];
			if (c[i + 1] == c[j + 1])
				j++;
			nex[i + 1] = j;
		}
		
		for (int i = nex[pos] + 1; i <= inLen; i++)
			ans[++ansLen] = c[i];
	}
	
	for (int i = 1; i <= ansLen; i++)
		printf("%c", ans[i]);
	printf("\n");
	return 0;
}
