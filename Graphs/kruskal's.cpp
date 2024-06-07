#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1010;
ll n, m;
int par[N], depth[N];
ll findd(ll u) {
    if(par[u] == u) return u;
    return par[u] = findd(par[u]);
}
void Union(ll a, ll b) {
    ll A = findd(a), B = findd(b);
    if(A == B) return;
    if(depth[A] > depth[B]) {
        par[B] = A;
        depth[A]++;
    }
    else {
        par[A] = B;
        depth[B]++;
    }
}
tuple <int , int, int> inp[N];
vector < pair <int , int> > ans[N];
int main() {

    for(ll i = 0; i < N; i++) par[i] = i;
    cin >> n >> m;
    for(ll i = 0; i < m; i++) {
        ll u, v, c; cin >> u >> v >> c;
        inp[i] = make_tuple(c , u, v);
    }
    sort(inp, inp + m);
    ll totcost = 0;
    // Connecting edges which will not create any loop
    for(ll i = 0; i < m; i++) {
        auto[cost, u, v] = inp[i];
        ll A = findd(u), B = findd(v);
        if(A != B) {
            Union(u , v);
            ans[u].push_back({v, cost});
            //ans[v].push_back({u, cost});
            totcost += cost;
        }
    }
    cerr << endl;
    for(ll i = 0; i <= n; i++) {
        for(auto it : ans[i]) {
            cout << i << " -> ";
            cout << it.first << ' ' << it.second << ' ' << endl;;
        }
    }
    cout << "Total cost : " << totcost << endl;

return 0;
}
