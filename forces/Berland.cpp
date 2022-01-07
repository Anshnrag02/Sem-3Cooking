#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    string s;
    cin >> s;
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
        if (s[i] != s[j]) return s[i] < s[j];
        else
            return v[i] < v[j];
    });
    int pos = 1;
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        res[order[i]] = pos++;
    }
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << '\n';
}

int main() {
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}