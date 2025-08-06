/*
Coded by Diego Cabrera
Optimized for performance using SPF (Smallest Prime Factor) and precomputed factorials/inverses
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 300010;
const ll MOD = 998244353;

ll fac[MAX], inv[MAX];
int spf[MAX];



// Modular inverse using binary exponentiation
ll modinv(ll a, ll m) {
    ll res = 1, p = m - 2;
    while (p) {
        if (p & 1) res = res * a % m;
        a = a * a % m;
        p >>= 1;
    }
    return res;
}

// Precompute factorials and inverse factorials
void init_factorials() {
    fac[0] = inv[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = inv[i - 1] * modinv(i, MOD) % MOD;
    }
}

// Precompute smallest prime factors
void compute_spf() {
    for (int i = 0; i < MAX; i++) spf[i] = i;
    for (int i = 2; i * i < MAX; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAX; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

// Compute C(n, k) modulo MOD
ll comb(ll n, ll k) {
    if (k > n || k < 0) return 0;
    return fac[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    init_factorials();
    compute_spf();

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        unordered_map<int, int> prime_count;
        for (int i = 0; i < n; i++) {
            int x = a[i];
            unordered_set<int> used;
            while (x > 1) {
                int p = spf[x];
                if (!used.count(p)) {
                    prime_count[p]++;
                    used.insert(p);
                }
                x /= p;
            }
        }

        ll total = comb(n, k);
        ll ans = 0;
        for (auto [prime, cnt] : prime_count) {
            ll excluded = comb(n - cnt, k);
            ll included = (total - excluded + MOD) % MOD;
            ans = (ans + included * prime) % MOD;
        }

        cout << ans << '\n';
    }
    return 0;
}
