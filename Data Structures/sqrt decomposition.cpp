#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;
    cin>>n>>q;

    int arr[n+10];

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    int sq = ceil(sqrt(n)); cerr<<sq<<endl;
    vector <int> v(sq);
    for(int i=0; i<n; i++) {
        v[i/sq] += arr[i];
    }
    for(auto x : v) cerr << x << ' ';
    cerr << endl;
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        l--; r--;
        int sum = 0;
        for(int i = l; i <= r; ) {
            if(i %sq ==0 && i + sq - 1 <= r) {
                cerr << i << ". " << i%sq << endl;
                sum += v[i/sq];
                i += sq;
            }
            else {
                sum += arr[i];
                i++;
            }
        }
        cout<<sum<<endl;
    }


    return 0;
}
