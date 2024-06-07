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

bitset < N > mark;

void sieve() {
    mark[0] = mark[1] = 1;
    for(int i = 4; i < N; i += 2) mark[i] = 1;
    for(int i = 3; i < N; i += 2) {
        if(!mark[i]) {
            for(int j = 2 * i; j < N; j += i) {
                mark[j] = 1;
            }
        }
    }
}

int main()
{
    O_O();
    
    sieve();
    
    return 0;
}
