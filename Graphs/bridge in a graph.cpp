#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 800;
int intime[N], low[N];
multiset < pair <int, int> > ans;
vector <int> g[N];
ll n, m;
void dfs(int st, int par, int time) {
    intime[st] = low[st] = time;
    for(auto it : g[st]) {
        if(!intime[it]) {
            dfs(it, st, time + 1);
            low[st] = min(low[it] , low[st]);
            if(low[it] > intime[st]) {
                ans.insert({min(st , it) , max(st , it)});
            }
        }
        else if(it != par) {
            low[st] = min(intime[it] , low[st]);
        }
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    while(m--) {
        ll a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 1, 1);
    if(!ans.empty()) {
        cout << "Number of bridges : ";
        cout << ans.size() << endl;
        for(auto it : ans) cout << it.first << ' ' << it.second << endl;
    }
    else cout << "Sin bloqueos" << endl;


    return 0;
}
