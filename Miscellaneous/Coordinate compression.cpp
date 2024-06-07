#include <bits/stdc++.h>
using namespace std;

void compress(vector <int>& v) {
    vector <int> coor = v;
    sort(coor.begin(), coor.end());
    coor.resize(unique(coor.begin(), coor.end()) - coor.begin());
    for(auto& it : v) {
        it = lower_bound(coor.begin(), coor.end(), it) - coor.begin() + 1;
    }
}

int main() {

    vector <int> v({99, 1, 100, 99, 10, 10});
    compress(v);
    for(auto it : v) cerr << it << ' ';

return 0;
}
