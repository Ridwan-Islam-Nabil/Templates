#include<bits/stdc++.h>
using namespace std;

int visited[8][8];
bool valid(int x, int y)
{
    return (x>=0 && x<8 && y>=0 && y<8 && !visited[x][y]);
}
int dx[]= {-1, 1, 0, 0, -1,-1, 1, 1};
int dy[]= { 0, 0,-1, 1, -1, 1,-1, 1};

struct node
{
    int x;
    int y;
};

void bfs(int sx, int sy)
{
    visited[sx][sy]=1;

    queue<node>q;
    q.push({sx,sy});
    visited[sx][sy]=1;

    while(!q.empty())
    {
        int x=q.front().x;
        int y=q.front().y;
        q.pop();

        for(int i=0; i<8; i++)
        {
            int nextx=x+dx[i];
            int nexty=y+dy[i];

            if(valid(nextx,nexty))
            {
                visited[nextx][nexty]=1;
                q.push({nextx,nexty});
            }
        }
    }
}

int main()
{
    int sx,sy;
    cin>>sx>>sy;
    bfs(sx,sy);

    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++) cout<<visited[i][j]<<' ';
        cout<<endl;
    }

    return 0;
}
