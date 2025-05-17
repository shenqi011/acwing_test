#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 1e5 + 10; //数据范围是10的5次方
const int M = 2 * N; //以有向图的格式存储无向图，所以每个节点至多对应2n-2条边

int h[N]; //邻接表存储树，有n个节点，所以需要n个队列头节点
int e[M]; //存储元素
int ne[M]; //存储列表的next值
int idx; //单链表指针
int n; //题目所给的输入，n个节点
int ans = N; //表示重心的所有的子树中，最大的子树的结点数目

bool st[N]; //记录节点是否被访问过，访问过则标记为true

void add(int a,int b)
{
    e[idx] = b, ne[idx] =  h[a], h[a] = idx ++;
}

int dfs(int u)
{
    int res = 0; //存储 删掉某个节点之后，最大的连通子图节点数
    st[u] = true; //标记访问过u节点
    int sum = 1; //存储 以u为根的树 的节点数, 包括u，如图中的4号节点

    for(int i = h[u]; i != -1; i = ne[i])
    {
         int j = e[i];
        //因为每个节点的编号都是不一样的，所以 用编号为下标 来标记是否被访问过
        if(!st[j]){
            int s = dfs(j);
            sum += s; // 所有子树的总结点（其实就是这颗树的全部节点
            res = max(res,s); // 子树最大的节点数
        }
    }

    res = max(res,n-sum); // 选择u节点为重心，最大的连通子图节点数(除了这颗树之外的部分是n-sum，这个节点的子树最大是res)
    ans = min(ans,res);//遍历过的假设重心中，最小的最大联通子图的 节点数
    return sum; // 返回以该节点为根的树的节点总数

}

int main()
{
    cin >> n;
    memset(h,-1,sizeof(h));
    for( int i = 0; i < n; i ++)
    {
        int x,y;
        cin >> x >> y;
        add(x,y),add(y,x);
    }
    dfs(1);
    cout << ans << endl;
}