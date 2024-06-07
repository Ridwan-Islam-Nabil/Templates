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
// int dx[]= {-1, 1, 0, 0, -1,-1, 1, 1};
// int dy[]= { 0, 0,-1, 1, -1, 1,-1, 1};

const int N = 2e5 + 9;

bool fun(ll mid) {
    
    return ;    // return true/false
}

void solve()
{
    int n; cin >> n;
    ll l = 0, r = n, mid;
    while(r > l + 1) {
        mid = (l + r) >> 1;
        if(fun(mid)) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    cout << l << endl;
}

int main()
{
    // freopen("input.txt","r",stdin);
    O_O();
    int test = 1;
    cin >> test;
    for (int tc = 1; tc <= test; tc++)
    {
        solve();
    }

    return 0;
}
