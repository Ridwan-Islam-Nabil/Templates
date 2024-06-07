#include<bits/stdc++.h>
using namespace std;
/*
Largest common substring of two string
Timus Freedom of choice
Problem link https://acm.timus.ru/problem.aspx?space=1&num=1517
*/
const int N = 1e5 + 9;
const int p1 = 137, mod1 = 127657753, p2 = 277, mod2 = 987654319;

int power(long long n, long long k, int mod) {
  int ans = 1 % mod; n %= mod; if (n < 0) n += mod;
  while (k) {
    if (k & 1) ans = (long long) ans * n % mod;
    n = (long long) n * n % mod;
    k >>= 1;
  }
  return ans;
}

int ip1, ip2;
pair<int, int> pw[N], ipw[N];
void prec() { // O(n)
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

pair<int, int> string_hash(string s) { // O(n)
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
  void build(string s) { // O(n)
    int n = s.size();
    for (int i = 0; i < n; i++) {
      pref[i].first = 1LL * s[i] * pw[i].first % mod1;
      if (i) pref[i].first = (pref[i].first + pref[i - 1].first) % mod1;
      pref[i].second = 1LL * s[i] * pw[i].second % mod2;
      if (i) pref[i].second = (pref[i].second + pref[i - 1].second) % mod2;
    }
  }
  pair<int, int> get_hash(int i, int j) { // O(1)
    // assert(i <= j);
    pair<int, int> hs({0, 0});
    hs.first = pref[j].first;
    if (i) hs.first = (hs.first - pref[i - 1].first + mod1) % mod1;
    hs.first = 1LL * hs.first * ipw[i].first % mod1;
    hs.second = pref[j].second;
    if (i) hs.second = (hs.second - pref[i - 1].second + mod2) % mod2;
    hs.second = 1LL * hs.second * ipw[i].second % mod2;
    return hs;
  }
}A, B;
int n;
string a, b;
string res;
bool ok(int k) { // is there a k length substring that occurs in both a and b
  set<pair<int, int>> substring_hashes_in_a;
  for (int i = 0; i + k - 1 < n; i++) {
    substring_hashes_in_a.insert(A.get_hash(i, i + k - 1));
  }

  for (int i = 0; i + k - 1 < n; i++) {
    auto substring_hash_in_b = B.get_hash(i, i + k - 1);
    if (substring_hashes_in_a.find(substring_hash_in_b) != substring_hashes_in_a.end()) {
      res = b.substr(i, k);
      return true;
    }
  }
  return false;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();
  cin >> n;
  cin >> a >> b;
  A.build(a);
  B.build(b);
  int l = 1, r = n, ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ok(mid)) {
      ans = mid;
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }
  // cout << ans << '\n';
  ok(ans);
  cout << res << '\n';
  // O(n log^2 n)
  return 0;
}

