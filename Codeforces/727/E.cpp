#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e6 + 7;

int n, k, g;
std::string s;

std::pair<i64, i64> operator + (std::pair<i64, i64> a, std::pair<i64, i64> b) {
    return {a.first + b.first, a.second + b.second};
}

std::pair<i64, i64> operator - (std::pair<i64, i64> a, std::pair<i64, i64> b) {
    return {a.first - b.first, a.second - b.second};
}

std::pair<i64, i64> operator * (std::pair<i64, i64> a, std::pair<i64, i64> b) {
    return {a.first * b.first, a.second * b.second};
}

std::pair<i64, i64> operator % (std::pair<i64, i64> a, std::pair<i64, i64> b) {
    return {a.first % b.first, a.second % b.second};
}

int cot[N];
std::pair<i64, i64> _Hash[N];
std::map<std::pair<i64, i64>, int> mp;

std::random_device rdv;
std::mt19937_64 myrand(rdv());

const std::pair<i64, i64> base = {20090313, 131};
const std::pair<i64, i64> mod = {19260817, 19660813};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    std::cin >> n >> k;
    std::cin >> s;
    std::cin >> g;

    for (int i = 0; i < g; i++) {
        std::string in;
        std::cin >> in;
        std::pair<i64, i64> h = {0, 0};
        for (auto c : in) {
            std::pair<i64, i64> tmp = {c, c};
            h = (h * base % mod + tmp) % mod;
        }
        mp[h] = i;
    }

    s = s + s.substr(0, k - 1);
    int len = s.size();

    for (int i = 0; i < len; i++) {
        std::pair<i64, i64> tmp = {s[i], s[i]};
        _Hash[i + 1] = (_Hash[i] * base % mod + tmp) % mod;
    }
    
    std::pair<i64, i64> sd = {1, 1};
    for (int i = 0; i < k; i++)
        sd = sd * base % mod;
    
    for (int i = 0; i < k; i++) {
        std::set<int> st;
        for (int j = 0; j < n; j++) {
            std::pair<i64, i64> h = (_Hash[i + (j + 1) * k] - _Hash[i + j * k] * sd % mod + mod) % mod;
            if (mp.count(h))
                st.insert(mp[h]);
        }

        if (st.size() != n) continue;
        std::cout << "YES\n";
        for (int j = 0; j < n; j++) {
            std::pair<i64, i64> h = (_Hash[i + (j + 1) * k] - _Hash[i + j * k] * sd % mod + mod) % mod;
            std::cout << mp[h] + 1 << " ";
        }
        std::cout << "\n";
        exit(0);
    }

    std::cout << "NO\n";
    return 0;
}
