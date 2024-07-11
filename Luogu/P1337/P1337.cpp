#include <bits/stdc++.h>

constexpr int N = 1e4 + 7;
constexpr double MAX_TIME = 0.95;

int n;
int x[N], y[N], w[N];
double ansx, ansy, dis;

double myrand() { return (double)rand() / RAND_MAX; }

double calc(double fx, double fy) {
    double res = 0;
    for (int i = 1; i <= n; ++i) {
        double dx = x[i] - fx, dy = y[i] - fy;
        res += sqrt(dx * dx + dy * dy) * w[i];
    }
    if (res < dis) { dis = res, ansx = fx, ansy = fy; } // S' better than S
    return res;
}

void simulateAnneal() {
    double t = 100000;  // T0
    double nx = ansx, ny = ansy;
    while (t > 0.001) { // T !< Tk
        double nxtx = nx + t * (myrand() * 2 - 1);
        double nxty = ny + t * (myrand() * 2 - 1);
        double delta = calc(nxtx, nxty) - calc(nx, ny);
        if (std::exp(-delta / t) > myrand())   // e^{frac{delta}{T}}
            nx = nxtx, ny = nxty;
        t *= 0.9989;  // T = T * d
    }
    for (int i = 1; i <= 1000; ++i) {   // 末温处理
        double nxtx = ansx + t * (myrand() * 2 - 1);
        double nxty = ansy + t * (myrand() * 2 - 1);
        calc(nxtx, nxty);
    }
}

int main() {
    srand(time(nullptr));
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d", &x[i], &y[i], &w[i]);
        ansx += x[i], ansy += y[i];
    }
    ansx /= n, ansy /= n, dis = calc(ansx, ansy);
    while ((double) std::clock() / CLOCKS_PER_SEC < MAX_TIME)
        simulateAnneal();

    printf("%.3lf %.3lf\n", ansx, ansy);
    return 0;
}
