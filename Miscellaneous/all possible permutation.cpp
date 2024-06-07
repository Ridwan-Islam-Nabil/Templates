#include <bits/stdc++.h>
using namespace std;
#define ll long long
void permutation() {

    ll n; cin >> n;
    int arr[n + 10];
    for(ll i = 1; i <= n; i++) {
        arr[i] = i;
    }
    do{
        ll sum = 0;
        cerr << "\t";
        for(ll i = 1; i <= n; i++) {
            cerr << arr[i] << ' ';
        } cerr << endl;

    }
    while(next_permutation(arr + 1, arr+n+1));

}

int main() {

    while(1) permutation();

    return 0;
}
