#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, ans;

priority_queue<ll, vector<ll>, greater<ll>> pq;

int main() {
    scanf("%lld", &n);
    for (ll i = 1, in; i <= n; i++) {
        scanf("%lld", &in);
        pq.push(in);
    }

    while (!(pq.size() == 1)) {
        ll a, b;
        a = pq.top();
        pq.pop();

        b = pq.top();
        pq.pop();

        pq.push(a + b);
        ans += (a + b);
    }

    printf("%lld\n", ans);
    return 0;
}
