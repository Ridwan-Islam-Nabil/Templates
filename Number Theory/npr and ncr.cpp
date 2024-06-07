#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, mod = 1e9 + 7;
int f[N], invf[N];
long long power(long long n, long long k) {
    int ans = 1 % mod; n %= mod; if(n < 0) n += mod;
    while(k) {
        if(k & 1) ans = 1LL * ans * n % mod;
        n = 1LL * n * n % mod;
        k >>= 1;
    }
    return ans;
}
void prec() {
    f[0] = 1;
    for(int i = 1; i < N; i++) {
        f[i] = 1LL * f[i - 1] * i % mod;
    }
    invf[N - 1] = power(f[N - 1], mod - 2);
    for(int i = N - 2; i >= 0; i--) {
        invf[i] = 1LL * (i + 1) * invf[i + 1] % mod;
    }
}
int ncr(int n, int r) {
    if(n < r or n < 0) return 0;
    return 1LL * f[n] * invf[r] % mod * invf[n - r] % mod;
}
int npr(int n, int r) {
    if(n < r or n < 0) return 0;
    return 1LL * f[n] * invf[n - r] % mod;
}
int main() {

    prec();

    while(1) {
        int n, k; cin >> n >> k;
        cout << "npr : " << npr(n, k) << endl;
        cout << "ncr : " << ncr(n, k) << endl;
    }

return 0;
}
