#include<bits/stdc++.h>

using namespace std;
int n,m;
const int N = 110;

int bfs(string ss)
{
    queue<string> q;
    string end = "123456789x";
    unordered_map<string,int> string_map;
    string_map[ss] = 0;
    q.push(ss);
    while(!q.empty())
    {
        string sss = q.front();
        q.pop();
        
        int dx[4] = {0,-1,0,1}, dy[4] = {-1,0,1,0};
        int t = sss.find('x');
        int x = t / 3, y = t % 3;
        int len = string_map[sss];

        for(int i = 0; i < 4; i ++ )
        {
            int ux = x + dx[i], uy = y + dy[i];
            if(ux >= 0 && ux < 3 && uy >= 0 && uy < 3){
                swap(sss[t],sss[ux*3+uy]);
                if( !string_map[sss] )
                {
                    string_map[sss] = len + 1;
                    if( sss == end ){
                        return string_map[sss];
                    }
                    q.push(sss);
                }
                swap(sss[t],sss[ux*3+uy]);
            }
        }
    }
    return -1;
}


int main()
{
    string ss, c;
    //输入起始状态
    for(int i = 0; i < 9; i++)
    {
        cin >> c;
        ss += c;
    }

    cout << bfs(ss) << endl;

    return 0;
}