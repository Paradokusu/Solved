#include <bits/stdc++.h>

using namespace std;

constexpr int N = 100000 + 7;

int n, q;
string a, b;

int sum[N][3][3];

int exc(char c) {
	if (c == 'A') return 0;
	if (c == 'T') return 1;
	if (c == 'C') return 2;
	// return -1;
}

void init(string a, string b) {
	n = a.size();
	for (int k = 1; k <= n; k++) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				sum[k][i][j] = sum[k - 1][i][j];
		sum[k][exc(a[k - 1])][exc(b[k - 1])]++;
	}
}

int get_distance(int x, int y) {
	int res = 0;
	int s[3][3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			s[i][j] = sum[y + 1][i][j] - sum[x][i][j];
	for (int i = 0; i < 3; i++)
		for (int j = i + 1; j < 3; j++) {
			int tmp = min(s[i][j], s[j][i]);
			res += tmp;
			s[i][j] -= tmp;
			s[j][i] -= tmp;
		}
	if ((s[0][1] != s[1][2]) || (s[1][2] != s[2][0]) || (s[1][0] != s[2][1]) || (s[2][1] != s[0][2]))
		return -1;
	return res + 2 * (s[0][1] + s[1][0]);
}

/* int main() {
	cin >> n >> q;
	cin >> a >> b;
	init(a, b);
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << get_distance(x, y) << "\n";
	}
	return 0;
} */
