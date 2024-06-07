#include <bits/stdc++.h>
using namespace std;

/*
Problem Link: https://cses.fi/problemset/task/2420/
*/

const int N = 2e5 + 9;
const int p1 = 137, mod1 = 127657753, p2 = 277, mod2 = 987654319;

int power(long long n, long long k, int md)
{
    int ans = 1 % md;
    n %= md;
    if (n < 0)
        n += md;
    while (k)
    {
        if (k & 1)
            ans = (long long)ans * n % md;
        n = (long long)n * n % md;
        k >>= 1;
    }
    return ans;
}

int ip1, ip2;
pair<int, int> pw[N], ipw[N];
void prec()
{
    pw[0] = {1, 1};
    for (int i = 1; i < N; i++)
    {
        pw[i].first = 1LL * pw[i - 1].first * p1 % mod1;
        pw[i].second = 1LL * pw[i - 1].second * p2 % mod2;
    }
    ip1 = power(p1, mod1 - 2, mod1);
    ip2 = power(p2, mod2 - 2, mod2);
    ipw[0] = {1, 1};
    for (int i = 1; i < N; i++)
    {
        ipw[i].first = 1LL * ipw[i - 1].first * ip1 % mod1;
        ipw[i].second = 1LL * ipw[i - 1].second * ip2 % mod2;
    }
}

struct ST
{
#define lc (n << 1)
#define rc ((n << 1) + 1)
    pair<int, int> arr[N * 4];
    string str;
    ST()
    {
    }
    ST(string s)
    {
        str = s;
    }
    void build(int n, int b, int e)
    {
        if (b == e)
        {
            arr[n].first = 1LL * str[b] * pw[b].first % mod1;
            arr[n].second = 1LL * str[b] * pw[b].second % mod2;
            return;
        }
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        build(l, b, mid);
        build(r, mid + 1, e);
        arr[n].first = (1LL * arr[l].first + arr[r].first) % mod1;    // change this
        arr[n].second = (1LL * arr[l].second + arr[r].second) % mod2; // change this
    }
    void upd(int n, int b, int e, int i, int x)
    {
        if (b > i || e < i)
            return;
        if (b == e && b == i)
        {
            arr[n].first = 1LL * x * pw[b].first % mod1;
            arr[n].second = 1LL * x * pw[b].second % mod2;
            return;
        }
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        upd(l, b, mid, i, x);
        upd(r, mid + 1, e, i, x);

        arr[n].first = (1LL * arr[l].first + arr[r].first) % mod1;    // change this
        arr[n].second = (1LL * arr[l].second + arr[r].second) % mod2; // change this
    }
    pair<int, int> query(int n, int b, int e, int i, int j)
    {
        if (b > j || e < i)
            return {0, 0}; // return appropriate value
        if (b >= i && e <= j)
            return arr[n];

        int mid = (b + e) >> 1, l = n << 1, r = l | 1;

        auto left = query(l, b, mid, i, j);
        auto right = query(r, mid + 1, e, i, j);

        pair<int, int> ans;

        ans.first = (1LL * left.first + right.first) % mod1;
        ans.second = (1LL * left.second + right.second) % mod2;

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    prec();

    int n, m;
    string str;
    cin >> n >> m;
    cin >> str;

    string rev = str;
    reverse(rev.begin(), rev.end());
    n -= 1;

    ST soja(str);
    ST ulta(rev);

    soja.build(1, 0, n);
    ulta.build(1, 0, n);

    while (m--)
    {
        int ty;
        cin >> ty;
        if (ty == 1)
        { // update
            int ind;
            char c;
            cin >> ind >> c;
            ind--;
            soja.upd(1, 0, n, ind, (int)c);
            ulta.upd(1, 0, n, n - ind, (int)c);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l--, r--;
            auto forw = soja.query(1, 0, n, l, r);
            auto back = ulta.query(1, 0, n, n - r, n - l);

            forw.first = 1LL * forw.first * ipw[l].first % mod1;
            forw.second = 1LL * forw.second * ipw[l].second % mod2;

            back.first = 1LL * back.first * ipw[n - r].first % mod1;
            back.second = 1LL * back.second * ipw[n - r].second % mod2;

            if (forw == back)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}