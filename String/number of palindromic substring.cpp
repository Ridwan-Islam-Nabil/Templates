#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define endl  '\n'
#define ll long long
#define mod 1000000007
#define all(x) x.begin(), x.end()
template<typename T> using super_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define fastIO() ({\
ios_base::sync_with_stdio(false);\
cin.tie(NULL);\
})
/*
No of palindromic substring
Problem name : Sub-palindromes
Link : https://acmp.ru/asp/do/index.asp?main=task&id_course=2&id_section=18&id_topic=43&id_problem=285
*/
const int N = 1e5 + 100;
const int p1 = 137, mod1 = 127657753, p2 = 277, mod2 = 987654319;

int power(long long n, long long k, int md) {
  int ans = 1 % md; n %= md; if (n < 0) n += md;
  while (k) {
    if (k & 1) ans = (long long) ans * n % md;
    n = (long long) n * n % md;
    k >>= 1;
  }
  return ans;
}

int ip1, ip2;
pair<int, int> pw[N], ipw[N];
void prec() {
  pw[0] =  {1, 1};
  for (int i = 1; i < N; i++) {
    pw[i].first = 1LL * pw[i - 1].first * p1 % mod1;
    pw[i].second = 1LL * pw[i - 1].second * p2 % mod2;
  }
  ip1 = power(p1, mod1 - 2, mod1);
  ip2 = power(p2, mod2 - 2, mod2);
  ipw[0] =  {1, 1};
  for (int i = 1; i < N; i++) {
    ipw[i].first = 1LL * ipw[i - 1].first * ip1 % mod1;
    ipw[i].second = 1LL * ipw[i - 1].second * ip2 % mod2;
  }
}

pair<int, int> string_hash(string s) {
  int n = s.size();
  pair<int, int> hs({0, 0});
  for (int i = 0; i < n; i++) {
    hs.first += 1LL * s[i] * pw[i].first % mod1;
    hs.first %= mod1;
    hs.second += 1LL * s[i] * pw[i].second % mod2;
    hs.second %= mod2;
  }
  return hs;
}
struct Hashing {
    pair<int, int> pref[N];
    void build(string s) {
      int n = s.size();
      for (int i = 0; i < n; i++) {
        pref[i].first = 1LL * s[i] * pw[i].first % mod1;
        if (i) pref[i].first = (pref[i].first + pref[i - 1].first) % mod1;
        pref[i].second = 1LL * s[i] * pw[i].second % mod2;
        if (i) pref[i].second = (pref[i].second + pref[i - 1].second) % mod2;
      }
    }
    pair<int, int> get_hash(int i, int j) {
      assert(i <= j);
      pair<int, int> hs({0, 0});
      hs.first = pref[j].first;
      if (i) hs.first = (hs.first - pref[i - 1].first + mod1) % mod1;
      hs.first = 1LL * hs.first * ipw[i].first % mod1;
      hs.second = pref[j].second;
      if (i) hs.second = (hs.second - pref[i - 1].second + mod2) % mod2;
      hs.second = 1LL * hs.second * ipw[i].second % mod2;
      return hs;
    }
}soja, ulta;

int main()
{
    //freopen("input.txt","r",stdin);
    fastIO();
    int test = 1;
    //cin >> test;
    for(int tc = 1; tc <= test; tc++){

        prec();
        string str; cin >> str;
        string rev = str;
        reverse(all(rev));
        soja.build(str);
        ulta.build(rev);
        ll ans = 0, n = str.size();
        for(int i = 0; i < n; i++) {
            int l = i, r = i;
            int mx = min(l, (int)n - r - 1);
            int L = 0, R = mx + 1, mid;
            while(R > L + 1) {
                mid = (L + R) >> 1;
                int newl = l - mid, newr = r + mid;
                if(soja.get_hash(newl, newr) == ulta.get_hash(n - newr - 1, n - newl - 1)) {
                    L = mid;
                }
                else R = mid;
            }
            l -= L, r += L;
            ans += (r - l + 1) / 2;
            ans++;
        }
        for(int i = 0; i < n; i++) {
            if(str[i] == str[i + 1]) {
                int l = i, r = i + 1;
                int mx = min(l, (int)n - r - 1);
                int L = 0, R = mx + 1, mid;
                while(R > L + 1) {
                    mid = (L + R) >> 1;
                    int newl = l - mid, newr = r + mid;
                    if(soja.get_hash(newl, newr) == ulta.get_hash(n - newr - 1, n - newl - 1)) {
                        L = mid;
                    }
                    else R = mid;
                }
                l -= L, r += L;
                ans += (r - l + 1) / 2;
            }
        }

        cout << ans << endl;
    }

    return 0;
}




