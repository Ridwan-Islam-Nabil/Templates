#include <bits/stdc++.h>
using namespace std;

int main() {

    int n; cin >> n;
    int arr[n + 9];
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector <int> v, lis(n + 9, 0);

    // if strictly increasin then use lower_bound
    for(int i = 1; i <= n; i++) {   
        auto it = upper_bound(v.begin(), v.end(), arr[i]);
        if(it == v.end()) {
            v.push_back(arr[i]);
            lis[i] = v.size();
        }
        else {
            int ind = it - v.begin();
            v[ind] = arr[i];
            lis[i] = ind + 1;
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << lis[i] << ' ' ;
    }
    cout << endl;

    return 0;
}