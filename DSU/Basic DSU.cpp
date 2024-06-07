#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 10;
int par[N];

ll find_par(ll u) {
    cerr << "find : " << u << endl;
    if(par[u] == u) return u;
    return par[u] = find_par(par[u]);
}
void Union(ll a, ll b) {
    ll p = find_par(a), q = find_par(b);
    if(p == q) return;
    else {
        par[p] = par[q];
    }
}

int main() {

    ll n; cin >> n;
    for(ll i = 1; i <= n; i++) par[i] = i;

    while(1) {
        char c; cin >> c;
        if(c == 'a') {
            ll n; cin >> n;
            cout << find_par(n) << endl;
        }
        else {
            ll a, b; cin >> a >> b;
            Union(a , b);
            cout << "____" << endl;
            for(ll i = 1; i <= n; i++) {
                cout << "parent of " << i << " : " << par[i] << endl;
            }
        }
    }

return 0;
}
