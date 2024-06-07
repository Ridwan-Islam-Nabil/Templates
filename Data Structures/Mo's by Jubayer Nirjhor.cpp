#include <bits/stdc++.h>

using namespace std;

const int B = 450;
const int N = 200005;

tuple <int, int, int, int> queries[N];
int n, q, a[N], ans[N], freq[N], distinct;

void add (int pos)
{
    int x = a[pos];
    if (freq[x] == 0) ++distinct;
    ++freq[x];
}

void remove (int pos)
{
    int x = a[pos];
    --freq[x];
    if (freq[x] == 0) --distinct;
}

int main()
{
    cin >> n ;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin>>q;

    //coordinate compression start
    vector <int> coo(a, a + n);
    sort(coo.begin(), coo.end());
    coo.erase(unique(coo.begin(), coo.end()), coo.end());
    for (int i = 0; i < n; ++i)
    {
        a[i] = lower_bound(coo.begin(), coo.end(), a[i]) - coo.begin();
    }
    //coordinate compression end

    for (int i = 0; i < q; ++i)
    {
        int l, r;
        cin >> l >> r;
        --l, --r;
        int block = l / B;
        queries[i] = make_tuple(block, (block & 1) ? -r : r, l, i);
    }
    // Mo
    sort(queries, queries + q);
    int L = 0, R = -1;
    for (int it = 0; it < q; ++it)
    {
        auto [block, r, l, i] = queries[it];
        r = abs(r);
        // block --> [l, r] jetar id i
        while (R < r) add(++R);
        while (L > l) add(--L);
        while (L < l) remove(L++);
        while (R > r) remove(R--);
        // L == l, R == r
        ans[i] = distinct;
    }
    for (int i = 0; i < q; ++i) cout << ans[i] << endl;
    return 0;
}



