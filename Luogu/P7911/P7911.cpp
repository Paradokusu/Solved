#include <bits/stdc++.h>

using namespace std;

int n;

unordered_map < string, int > address;

bool check(string s) {
    int len = s.length();
    long long tmp = 0;
    int t1 = 0, t2 = 0, t3 = 0;
    for (int i = 0; i < len; i++) {
        if ((i == 0 || (s[i - 1] == '.' || s[i - 1] == ':')) && s[i] >= '0' && s[i] <= '9') t3++;
        if (s[i] == '.' || s[i] == ':') {
            if (s[i] == '.') t1++;
            else if (s[i] == ':') t2++;

            if (t1 < 3 && t2) return false;
            if (!t3) return false;
            if (tmp >= 0 && tmp <= 255) {
                tmp = 0;
                continue;
            } else return false;
        } else if (s[i] < '0' || s[i] > '9') return false;
        if (i && !tmp && s[i - 1] == '0') return false;
        tmp = tmp * 10 + s[i] - '0';
    }
    if (t1 != 3 || t2 != 1 || t3 != 5) return false;
    if (tmp >= 0 && tmp <= 65535) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        string op, ad;
        cin >> op >> ad;

        if (!check(ad)) cout << "ERR" << endl;
        else if (op == "Server") {
            if (address.count(ad)) cout << "FAIL" << endl;
            else {
                address[ad] = i;
                cout << "OK" << endl;
            }
        } else if (op == "Client") {
            if (address.count(ad)) cout << address[ad] << endl;
            else cout << "FAIL" << endl;
        }
    }
    return 0;
}
