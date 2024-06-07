#include <bits/stdc++.h>
using namespace std;

typedef double T;
typedef complex<T> point;

#define x real()
#define y imag()

T dot(point a, point b) { return (conj(a) * b).x; }
T cross(point a, point b) { return (conj(a) * b).y; };
point unit(point P) { return P / abs(P); }

void getPoint(point &A)
{
    T a, b;
    cin >> a >> b;
    A = point(a, b);
}

bool lineIntersection(point A, point C, point B, point D)
{
    point dA = C - A, dB = D - B;
    T det = cross(dA, dB);
    if (det == 0)
        return 0;
    T s = cross(B - A, dB) / det;
    point ret = A + dA * s;

cerr << ret << endl;
    int cnt = 0;
    if(ret.x >= A.x and ret.x <= B.x and ret.y >= A.y and ret.y <= B.y) cnt++;
    if(ret.x >= C.x and ret.x <= D.x and ret.y >= C.y and ret.y <= D.y) cnt++;

    return (cnt == 2);
}
bool collinear(point a, point b, point p, point q) {
    
    vector < pair <int, int> > v;
    v.push_back({a.y, 1});
    v.push_back({b.y, 1});
    v.push_back({p.y, 2});
    v.push_back({q.y, 2});
    sort(v.begin(), v.end());

    return (v[0].second != v[1].second);
}
bool intersection(point a, point b, point p, point q)
{
    double c1 = cross(p - a, b - a), c2 = cross(q - a, b - a);
    if(!(c1 - c2)) {
        point nw1(unit(b - a));
        point nw2(unit(q - p));
        point center(0, 0);

        if(arg(nw1 - center) != arg(nw2 - center)) return 0;
        return collinear(a, b, p, q);
    }
    point ret = (c1 * q - c2 * p) / (c1 - c2); // undefined if parallel

    int cnt = 0, x1 = min(a.x, b.x), y1 = min(a.y, b.y), x2 = max(a.x, b.x), y2 = max(a.y, b.y);
    if (ret.x >= x1 and ret.x <= x2 and ret.y >= y1 and ret.y <= y2)
        cnt++;
    x1 = min(p.x, q.x), y1 = min(p.y, q.y), x2 = max(p.x, q.x), y2 = max(p.y, q.y);
    if (ret.x >= x1 and ret.x <= x2 and ret.y >= y1 and ret.y <= y2)
        cnt++;

    return (cnt == 2);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        point a, b, c, d;
        getPoint(a);
        getPoint(b);
        getPoint(c);
        getPoint(d);

        if(intersection(a, b, c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}