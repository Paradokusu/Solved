#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5 + 50;

ll n, ans;
ll to[N];

queue<ll> q1, q2;

inline ll read() {
    register ll x = 0, f = 1;
    register char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

inline void write(ll x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

int main() {
	n = read();
	for (ll i = 1, in; i <= n; i++) {
		in = read();
		to[in]++;
	}
	
	for (ll i = 1; i <= 100000; i++) {
		while (to[i]) {
			to[i]--;
			q1.push(i);
		}
	}
	
	for (ll i = 1; i < n; i++) {
		ll x, y;
		
		if ((q1.front() < q2.front() && !q1.empty()) || q2.empty()) {
			x = q1.front();
			q1.pop();
		} else {
			x = q2.front();
			q2.pop();
		}
		
		if ((q1.front() < q2.front() && !q1.empty()) || q2.empty()) {
			y = q1.front();
			q1.pop();
		} else {
			y = q2.front();
			q2.pop();
		}
		
		ans += (x + y);
		q2.push(x + y);
	}
	
	write(ans);
	puts("");
	return 0;
}
