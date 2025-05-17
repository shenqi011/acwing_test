#include<iostream>
#include<algorithm>
#include<queue>

int n,m;
const int N = 110;
int g[N][N],d[N][N];
typedef pair<int,int> PII; // 重命名

void bfs(int x, int y)
{
    queue<PII> q;
    q.push({x,y}); // bfs用队列来做，队列是队尾进，队头出，所以是按照一层一层来遍历的

    while(!q.empty())
    {
        int start = q.front();
        q.pop(); // 第一个点pop出
        int tx = {-1,0,1,0}, ty = {0,-1,0,1}; // 用向量法来遍历四个方向
        for(int i = 0; i < 4; i++ )
        {

            int ux = start.first + tx[i];
            int uy = start.second + ty[i];
            if( g[ux][uy] == 0 )
            {
                g[ux][uy] = 1;
                f[ux][uy] = f[start.first][start.second] + 1
                q.push({ux,uy});
            }
        }
    }
    cout << d[n][m];
}


int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n ; i ++)
        for(int j = 1; j <= m; j ++ )
            cin >> g[i][j];

    bfs(1, 1);
}