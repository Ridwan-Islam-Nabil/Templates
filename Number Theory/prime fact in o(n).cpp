#include <bits/stdc++.h>
using namespace std;
#define ll long long
void p_fact(ll n)
{
    while(n % 2 == 0){
        cout << 2 << ' ';
        n /= 2;
    }
    for(ll i = 3; i <= sqrtl(n); i+= 2){
        while(n % i == 0){
            cout << i << ' ';
            n /= i;
        }
    }
    if(n > 2) cout << n;
    cout << endl;
}
int main()
{

    while(1){
        auto time = clock();
        ll n;
        cin >> n;
        p_fact(n);
        cerr << (double) (clock() - time) / CLOCKS_PER_SEC << endl;
    }

    return 0;
}
