#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3;
ll par[N], depth[N];
void init() {
    for(ll i = 0; i < N; i++) {
        par[i] = i;
        depth[i] = 1;
    }
}
ll find(ll u) {
    if(par[u] == u) return u;
    return par[u] = find(par[u]);
}
void Union(ll a, ll b) {
    ll A = find(a), B = find(b);
    if(A == B) return;
    else if(depth[A] > depth[B]) {
        par[B] = A;
        depth[A] += depth[B];
    }
    else {
        par[A] = B;
        depth[B] += depth[A];
    }
}
int main() {

    init();
    while(1) {
        ll a, b; cin >> a >> b;
        Union(a , b);
        for(ll i = 1; i <= 8; i++) {
cout << "group size of " << i << " = " << depth[find(i)] << " parent = " << find(i) << endl;
        }
    }

return 0;
}
