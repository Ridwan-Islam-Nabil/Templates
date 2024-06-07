#include <bits/stdc++.h>
using namespace std;
long long power(long long n, long long k, long long mod) {
    int ans = 1 % mod; n %= mod; if(n < 0) n += mod;
    while(k) {
        if(k & 1) ans = 1LL * ans * n % mod;
        n = 1LL * n * n % mod;
        k >>= 1;
    }
    return ans;
}
int main() {

    int md = 1e9 + 7;
    cout << power(3, 4, md) << endl;

return 0;
}
