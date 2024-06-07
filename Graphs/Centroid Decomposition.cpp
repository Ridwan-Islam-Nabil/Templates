// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define endl '\n'
#define ll long long
#define mod 1000000007
#define all(x) x.begin(), x.end()
template <typename T>
using super_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define O_O() ({                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
})
void clearr(int n);
const int N = 2e5 + 9;

int n, siz[N];
ll ans;
vector<int> g[N];
bitset <N> dead;

void dfs(int bap, int dada)
{
    siz[bap] = 1;
    for (auto cld : g[bap])
    {
        if (cld == dada or dead[cld])
            continue;
        dfs(cld, bap);
        siz[bap] += siz[cld];
    }
}

int find(int bap, int dada, int sz)
{
    for (auto cld : g[bap])
    {
        if (cld == dada or dead[cld])
            continue;
        if (siz[cld] > sz)
            return find(cld, bap, sz);
    }
    return bap;
}
int timer = 0, curr_size;
int in[N], out[N], flat[N];

void euler(int bap, int dada)
{
    in[bap] = ++timer;
    flat[timer] = ;              // Change it || Change it || Change it
    for (auto cld : g[bap])
    {
        if (cld == dada or dead[cld])
            continue;
        euler(cld, bap);
    }
    out[bap] = timer;
}

void calculate(int king)
{
    timer = 0;
    euler(king, king);

    for(auto cld : g[king]) {
        if(dead[cld]) continue;
                                                    
        for(int i = in[cld]; i <= out[cld]; i++)    // Query
        {

        }
                                
        for(int i = in[cld]; i <= out[cld]; i++)    // Update
        {
            
        }
    }
}

void decompose(int curr = 1)
{
    dfs(curr, curr);
    int king = find(curr, curr, siz[curr] / 2);
    dead[king] = 1;

    calculate(king);

    for (auto cld : g[king])
    {
        if (!dead[cld])
        {
            decompose(cld);
        }
    }
}

int main()
{
    O_O();
    int test = 1;
    //cin >> test;
    for (int tc = 1; tc <= test; tc++)
    {
        cin >> n;
        clearr(n);
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        decompose();

        cout << ans << endl;
    }

    return 0;
}

void clearr(int x) {
    ans = 0;
    for(int i = 0; i <= x; i++) {
        g[i].clear();
        dead[i] = 0;
    }
}
