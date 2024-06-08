#include <bits/stdc++.h>

using namespace std;

constexpr int N = 5;

int x[N], y[N];

bool allEqual() {
	return ((x[1] == x[2] && x[1] == x[3]) || (y[1] == y[2] && y[1] == y[3]));
}

bool inMid(int a, int b, int c) {
	return (min(a, b) <= c && c <= max(a, b));
}

bool check(int a, int b, int c) {
	return (((x[a] == x[c] || x[b] == x[c]) && inMid(y[a], y[b], y[c])) || ((y[a] == y[c] || y[b] == y[c]) && inMid(x[a], x[b], x[c])));
}

int main() {
	for (int i = 1; i <= 3; i++)
		scanf("%d %d", &x[i], &y[i]);
	
	if (allEqual()) printf("1\n");
	else if (check(1, 2, 3) || check(1, 3, 2) || check(2, 3, 1)) printf("2\n");
	else printf("3\n");
	
	return 0;
}
