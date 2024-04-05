#include <bits/stdc++.h>

constexpr int N = 1e5 + 7;
constexpr double eps = 1e-8;

int n;
double r;

struct point {
	double x, y;
} o, p[N];

double dpow(double x) {
	return x * x;
}

double dis(point a, point b) {
	return std::sqrt(dpow(a.x - b.x) + dpow(a.y - b.y));
}

bool cmp(double a, double b) {
	return std::fabs(a - b) < eps;
}

point Get(point a, point b, point c) {
	double a1, a2, b1, b2, c1, c2;
	point ans;

	a1 = 2 * (b.x - a.x);
	b1 = 2 * (b.y - a.y);
	c1 = dpow(b.x) - dpow(a.x) + dpow(b.y) - dpow(a.y);
	a2 = 2 * (c.x - a.x);
	b2 = 2 * (c.y - a.y);
	c2 = dpow(c.x) - dpow(a.x) + dpow(c.y) - dpow(a.y);

	if (cmp(a1, 0)) {
		ans.y = c1 / b1;
		ans.x = (c2 - ans.y * b2) / a2;
	} else if (cmp(b1, 0)) {
		ans.x = c1 / a1;
		ans.y = (c2 - ans.x * a2) / b2;
	} else {
		ans.x = (c2 * b1 - c1 * b2) / (a2 * b1 - a1 * b2);
		ans.y = (c2 * a1 - c1 * a2) / (b2 * a1 - b1 * a2);
	}

	return ans;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::mt19937_64 myrand(time(nullptr));

	std::cin >> n;

	for (int i = 1; i <= n; i++)
		std::cin >> p[i].x >> p[i].y;

	for (int i = 1; i <= n; i++)
		std::swap(p[myrand() % n + 1], p[myrand() % n + 1]);

	o = p[1];

	for (int i = 1; i <= n; i++) {
		if (dis(o, p[i]) < r || cmp(dis(o, p[i]), r))
			continue;

		o.x = (p[i].x + p[1].x) / 2;
		o.y = (p[i].y + p[1].y) / 2;
		r = dis(p[i], p[1]) / 2;

		for (int j = 2; j < i; j++) {
			if (dis(o, p[j]) < r || cmp(dis(o, p[j]), r))
				continue;

			o.x = (p[i].x + p[j].x) / 2;
			o.y = (p[i].y + p[j].y) / 2;
			r = dis(p[i], p[j]) / 2;

			for (int k = 1; k < j; k++) {
				if (dis(o, p[k]) < r || cmp(dis(o, p[k]), r))
					continue;

				o = Get(p[i], p[j], p[k]);
				r = dis(o, p[i]);
			}
		}
	}

	std::cout << std::fixed << std::setprecision(10) << r << "\n" << o.x << " " << o.y << "\n";
	return 0;
}
