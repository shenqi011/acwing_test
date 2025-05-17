#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;
const int N = 1e5 + 10; //数据范围是10的5次方

int n,m;
int d[N]; //记录节点是否被访问过，访问过则标记为true
vector<int> g[N];

int bfs()
{
    memset(d,-1,sizeof(d));
    
    queue<int> q;
    q.push(1);
    d[1] = 0;
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        
        for(int i:g[t])
        {
            if(d[i] == -1)
            {
                q.push(i);
                d[i] = d[t] + 1;
            }
        }
    }
    return d[n];

}

int main()
{
    cin >> n >> m;
    for( int i = 0; i < m; i ++) // 读的是图！
    {
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    cout << bfs();
}