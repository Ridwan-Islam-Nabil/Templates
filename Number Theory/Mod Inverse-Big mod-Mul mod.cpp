#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastIO() ({\
ios_base::sync_with_stdio(false);\
cin.tie(NULL);\
})

ll bigmod(ll a, ll b, ll p){

    if(b <= 1) return a % p;
    ll val = bigmod(a, b / 2, p);

    if(b % 2 == 0) return ((__int128)(val % p) * (val % p)) % p;
    else{
        ll ans = ((__int128)(val % p) * (val % p)) % p;
        return ((__int128)(ans % p) * (a % p)) % p;
    }
}
ll mulmod(ll a, ll b, ll p){

    if(b <= 1) return a % p;
    ll val = mulmod(a, b / 2, p);

    if(b % 2 == 0) return ((__int128)(val % p) + (val % p)) % p;
    else{
        ll ans = ((__int128)(val % p) + (val % p)) % p;
        return ((__int128)(ans % p) + (a % p)) % p;
    }
}
ll modInverse(ll a, ll b, ll p){
    return mulmod(a , bigmod(b , p - 2, p) , p);
}
int main(void)
{
    //freopen("input.txt","r",stdin);
    fastIO();

    ll a, b, p; cin >> a >> b >> p;

    cout << bigmod(a , b, p) << endl;
    cout << mulmod(a , b, p) << endl;
    cout << modInverse(a, b, p) << endl;

    return 0;
}


