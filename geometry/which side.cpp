#include <bits/stdc++.h>
using namespace std;

typedef double T;
typedef complex <T> point;

#define x real()
#define y imag()

T dot(point a, point b) { return (conj(a) * b).x; }
T cross(point a, point b) { return (conj(a) * b).y; };

void getPoint(point &A) {
    T a, b; cin >> a >> b;
    A = point(a, b);
}
int whichSide(point a, point b, point c) {
    T det = cross(b - a, c - a);
    if(det == 0.0) return 0;
    return det < 0 ? -1 : 1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        point a, b, c;
        getPoint(a);
        getPoint(b);
        getPoint(c);

        int side = whichSide(a, b, c);
        if(side == 0) cout << "TOUCH" << endl;
        else if(side == -1) cout << "RIGHT" << endl;
        else cout << "LEFT" << endl;
    }

    return 0;
}