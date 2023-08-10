#include <bits/stdc++.h>

using namespace std;

int n;
string s;

unordered_set<string> S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    while (n--) {
        cin >> s;
        S.insert(s);
    }

    cout << S.size() << endl;
    return 0;
}
