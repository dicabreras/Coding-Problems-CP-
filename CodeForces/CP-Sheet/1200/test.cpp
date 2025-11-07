/*
Coded by Diego Cabrera
Codeforces username : GAL1LEO-DC
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(ll x) {
    string s = to_string(x);
    reverse(s.begin(), s.end());
    return stoll(s);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll X, Y;
    cin >> X >> Y;

    vector<ll> a(11);
    a[1] = X;
    a[2] = Y;

    for (int i = 3; i <= 10; i++) {
        a[i] = f(a[i-1] + a[i-2]);
    }

    cout << a[10] << "\n";
    return 0;
}
