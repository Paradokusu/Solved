#include <bits/stdc++.h>

using namespace std;

double a, b, c, d;

double f(double x) {
    return (a * x * x * x) + (b * x * x) + (c * x) + d;
}

void binarySearch(double l, double r) {
    if (r - l <= 0.001) {
        printf("%.2f ", l);
        return;
    }

    double mid = l + (r - l) / 2;
    double lef, rig;
    lef = f(l) * f(mid), rig = f(r) * f(mid);

    if (f(mid) == 0) printf("%.2f ", mid);
    if (f(r) == 0) printf("%.2f ", r);
    
    if (lef < 0) binarySearch(l, mid);
    else if (rig < 0) binarySearch(mid, r);
}

int main() {
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    
    for (double i = -100; i <= 99; i++)
        if (f(i) * f(i + 1.0) <= 0)
            binarySearch(i, i + 1.0);
    printf("\n");

    return 0;
}
