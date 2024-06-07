#include <bits/stdc++.h>
using namespace std;

int visited[5][5];
bool valid(int x, int y)
{
    return (x>=0 && x<5 && y>=0 && y<5 && !visited[x][y]);
}
int dx[]= {-1, 1, 0, 0, -1,-1, 1, 1};
int dy[]= { 0, 0,-1, 1, -1, 1,-1, 1};


void dfs(int sx,int sy)
{
    if(visited[sx][sy]) return;

    visited[sx][sy]=1;

    for(int i=0; i<8; i++)
    {
        int nextx=sx+dx[i];
        int nexty=sy+dy[i];

        if(valid(nextx, nexty))
        {
            dfs(nextx, nexty);
        }
    }
}


int main()
{
    int sx, sy;
    cin>>sx>>sy;

    dfs(sx,sy);

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++) cout<<visited[i][j]<<' ';
        cout<<endl;
    }

    return 0;
}
