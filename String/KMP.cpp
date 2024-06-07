#include <bits/stdc++.h>
using namespace std;

vector <int> calculate_prefix(string str) {
    int n = str.size();
    vector <int> res(n, 0);
    for(int i = 1; i < n; i++) {
        int j = res[i - 1];

        while(j > 0 and str[j] != str[i]) j--;
        if(str[j] == str[i]) j++;
        
        res[i] = j;
    }
    return res;
}
int main() {

    string pat;
    string txt; cin >> txt;
    cin >> pat;
    vector <int> prefix = calculate_prefix(pat), pos;

    int i(0), j(0), cnt(0);
    while(i < (int)txt.size()) {
        if(txt[i] == pat[j]) i++, j++;
        else {
            if(j != 0) {
                j = prefix[j - 1];
            }
            else i++;
        }
        if(j == (int)pat.size()) {
            ++cnt;
            pos.push_back(i - (pat.size()));
        }
    }
    cout << cnt << endl;
    // for(auto it : pos) cout << it << ' ' ;
    // cout << endl;

    return 0;
}