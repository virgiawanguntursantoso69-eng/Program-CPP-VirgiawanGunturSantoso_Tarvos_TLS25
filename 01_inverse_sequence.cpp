#include <bits/stdc++.h>
using namespace std;

long long reverseDigits(long long x) {
    if (x == 0) return 0;
    long long sign = (x < 0 ? -1 : 1);
    x = llabs(x);
    long long r = 0;
    while (x > 0) {
        r = r * 10 + (x % 10);
        x /= 10;
    }
    return sign * r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i < n; ++i) {
        long long rev = reverseDigits(a[i]);
        if (i) cout << ' ';
        cout << rev;
    }
    cout << "\n";
    return 0;
}
