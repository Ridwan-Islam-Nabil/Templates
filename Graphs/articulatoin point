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
//int dx[]= {-1, 1, 0, 0, -1,-1, 1, 1};
//int dy[]= { 0, 0,-1, 1, -1, 1,-1, 1};
const int N = 1e5 + 100;
vector <int> g[N];
ll n, m;
int in[N], low[N];
set <int> ans;
void dfs(int node, int par, int time) {
    in[node] = low[node] = time;
    ll subtree = 0;
    for(auto child : g[node]) {
        if(child == par) continue;
        if(!in[child]) {
            dfs(child, node, time + 1);
            subtree++;
            low[node] = min(low[node] , low[child]);
            if(in[node] <= low[child] && par != -1) ans.insert(node);
        }
        else {
            low[node] = min(low[node] , in[child]);
        }
    }
    if(par == -1 && subtree > 1) ans.insert(node);
}
void clearr() {
    ans.clear();
    for(ll i = 0; i <= n; i++) g[i].clear();
    memset(in, 0, sizeof in);
}
int main()
{
    //freopen("input.txt","r",stdin);
    fastIO();
    while(1) {
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        clearr();
        while(m--) {
            ll a, b; cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs(1 , -1, 1);
//        for(auto it : ans) cerr << it << ' ' ;
//        cerr << endl;
        cout << ans.size() << endl;
    }

    return 0;
}



