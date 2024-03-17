#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 7;
constexpr int BASE = 1e9;

struct BigInt {
	int len, n[N / 9 + 7];
	
	BigInt() {}
	
	BigInt(char *s) {
		int x = strlen(s);
		len = x / 9 + (x % 9 ? 1 : 0);
		int p = x - 1;
		
		for (int i = 1; i <= len; i++) {
			n[i] = 0;
			for (int j = std::min(p, 8); j >= 0; j--) {
				n[i] = n[i] * 10 + (s[p - j] & 15);
			}
			p -= 9;
		}
	}
	
	bool zero() { return len == 1 && n[1] == 0;	}
	
	bool judge() { return (!zero() && (n[1] & 1) == 0); }
	
	bool operator < (const BigInt &b) const {
		if (len != b.len) {
			return len < b.len;
		}
		
		for (int i = len; i >= 1; i--) {
			if (n[i] != b.n[i])
				return n[i] < b.n[i];
		}
		
		return 0;
	}
	
	bool operator -= (const BigInt &b) {
		for (int i = 1; i <= len; i++) {
			if (i <= b.len) {
				n[i] -= b.n[i];
				
				if (n[i] < 0) {
					n[i + 1]--;
					n[i] += BASE;
				}
			}
		}
		
		for (; !n[len] && len > 1; len--);
		
		return zero();
	}
	
	void div2() {
		for (int i = 1; i <= len; i++) {
			if (n[i] & 1) {
				n[i - 1] += BASE >> 1;
			}
			
			n[i] >>= 1;
		}
		
		for (; !n[len] && len > 1; len--);
	}
	
	void operator <<= (const int &x) {
		for (int t = 1; t <= x; t++) {
			n[len + 1] = 0;
			for (int i = len; i >= 1; i--) {
				n[i] <<= 1;
				n[i + 1] += n[i] / BASE;
				n[i] %= BASE;
			}
			
			if (n[len + 1])	len++;
		}
		
		this -> print();
	}
	
	void print() {
		for (int i = len; i >= 1; i--) {
			if (i == len) printf("%d", n[i]);
			else printf("%09d", n[i]);
		}
		printf("\n");
	}
} x, y;

int main() {
	static char A[N], B[N];
	scanf(" %s %s", A, B);
	x = BigInt(A), y = BigInt(B);
	
	if (x.zero()) {
		y.print();
		return 0;
	}
	
	if (y.zero()) {
		x.print();
		return 0;
	}
	
	int i = 0, j = 0;
	for (; x.judge(); i++)
		x.div2();
	for (; y.judge(); j++)
		y.div2();
	
	while (1) {
		if (!(x < y)) {
			if (x -= y) {
				y <<= min(i, j);
				return 0;
			}
			
			while (x.judge())
				x.div2();
		} else {
			if (y -= x) {
				x <<= min(i, j);
				return 0;
			}
			
			while (y.judge())
				y.div2();
		}
	}
	
	return 0;
}
