#include <bits/stdc++.h>

extern "C" int Seniorious(int);

extern "C" int Chtholly(int n, int OvO) {
	int res = 1;
	int l = 1, r = n;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (Seniorious(mid) >= 0) {
			r = (res = mid) - 1;
		} else l = mid + 1;
	}
	return res;
}
