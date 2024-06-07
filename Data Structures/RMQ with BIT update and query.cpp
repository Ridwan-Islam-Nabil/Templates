#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;

int seg[3 * N];

void update(int k, int x)
{
    k += N;
    seg[k] = x;
    k >>= 1;
    while (k > 0)
    {
        seg[k] = max(seg[2 * k], seg[2 * k + 1]);
        k >>= 1;
    }
}

int query(int a, int b)
{
    a += N, b += N;
    int s = INT_MIN;              // set appropriate value
    while (a <= b)
    {
        if (a & 1)
        {
            s = max(s, seg[a]);
            a++;
        }
        if (~b & 1)
        {
            s = max(s, seg[b]);
            b--;
        }
        a >>= 1, b >>= 1;
    }
    return s;
}

int main() {

    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        update(i, x);
    }
    while(q--) {
        int typ, a, b; cin >> typ >> a >> b;
        if(typ == 1)         // Updates value of index a to b
        {      
            update(a, b);
        }
        else 
        {          
            cout << query(a, b) << endl;
        }
    }

    return 0;
}