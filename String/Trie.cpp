#include <bits/stdc++.h>
using namespace std;

const int N = 27;

int get_char(char c)
{
    return (c - 'a') + 1;
}
int cnt;
struct node
{
    vector<int> nxt;
    node()
    {
        nxt.resize(27);
    }
    bool end = 0;
};

vector<node> edge;

void insert(string str, int curr = 0)
{
    for (auto it : str)
    {
        if (edge[curr].nxt[get_char(it)])
        {
            curr = edge[curr].nxt[get_char(it)];
        }
        else
        {
            cnt++;
            edge[curr].nxt[get_char(it)] = cnt;
            node val;
            edge.push_back(val);
            curr = cnt;
        }
    }
    edge[curr].end = 1;
}
int search(string str, int curr = 0)
{
    int n = str.size(), i = 0;
    while (i < n)
    {
        if (edge[curr].nxt[get_char(str[i])])
        {
            curr = edge[curr].nxt[get_char(str[i])];
        }
        else
            break;
        i++;
    }
    if (i < n)
        curr = 0;
    return curr;
}

int main()
{
    // freopen("input.txt","r",stdin);

    int n;
    cin >> n;
    node val;
    edge.push_back(val);

    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        insert(str);
    }

    int q;
    cin >> q;
    while (q--)
    {
        string str;
        cin >> str;
        if (edge[search(str)].end)
        {
            cout << "found" << endl;
        }
        else
            cout << "Not found" << endl;
    }

    return 0;
}
