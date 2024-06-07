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
struct node {
    int val, cost;
};
vector < node > g[N];
int main()
{
    fastIO();
    int test = 1;
    for(int tc = 1; tc <= test; tc++){

        bitset <N> vis;
        vector <int> dis(N), par(N);
        ll n, m;
        cin >> n >> m;
        while(m --) {
            ll a, b, c; cin >> a >> b >> c;
            g[b].push_back({a , c});
            g[a].push_back({b , c});
        }
        set < pair <int , pair <int , int>> > st;
        st.insert({0 , make_pair(1 , 1)});
        while(!st.empty()) {
            auto it = st.begin();
            ll uval = it -> second . first, ucost = it -> first, prnt = it -> second.second;
            st.erase(it);
            if(!vis[uval])  {
                dis[uval] = ucost;
                par[uval] = prnt;
            }
            else continue;
            vis[uval] = 1;
            for(auto itr : g[uval]) {
                ll nxtval = itr.val;
                ll nxtcost = itr.cost;
                if(!vis[itr.val])  {
                    st.insert({itr.cost + ucost , make_pair(nxtval , uval)});
                }
            }
        }
        if(vis[n]) {
            vector <int> ans;
            ll path = n;
            while(path != 1) {
                ans.push_back(path);
                path = par[path];
            }
            reverse(all(ans));
            cout << 1 << ' ';
            for(auto it : ans) cout << it << ' ';
            cout << endl;
        }
        else cout << -1 << endl;
    }

    return 0;
}




