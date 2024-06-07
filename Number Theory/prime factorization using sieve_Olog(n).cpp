#include <bits/stdc++.h>
using namespace std;
#define maxn 1000020

vector <int> v(maxn,-1);

void sieve()
{
    for(int i = 2; i <= maxn; i++){
        if(v[i] == -1){
            for(int j = i; j <= maxn; j += i){
                if(v[j] == -1){
                    v[j] = i;
                }
            }
        }
    }
}

int main()
{
    sieve();

    while(1)
    {
        int n;
        cin >> n;

        while(n!=1)
        {
            cout<< v[n] <<' ';
            n /= v[n];

        }cout << endl;
    }

    return 0;
}
