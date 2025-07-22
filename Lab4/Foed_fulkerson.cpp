#include <bits/stdc++.h>

using namespace std;

bool findpath(vector<vector<int>>& adj,vector<int>& path,int i,vector<int> & vis)
{
    // cout<<i;
    if(i == 5)
    {
        return 1;
    }
    bool b = !true;
    for(int j = 0 ; j < 6 ; j++ )
    {
        if(adj[i][j] > 0 && vis[j] == 0)
        {
            path.push_back(j);
            vis[j] = 1;
            b = findpath(adj,path,j,vis);
            if(b == 0)
            {
                vis[j] = 0;
                path.pop_back();
            }
            else
            {
                return 1;
            }
        }

    }
    return 0;
}



int main()
{
    vector<vector<int>> adj = {
{0,16,13,0,0,0}
,{0,0,10,12,0,0}
,{0,4,0,0,14,0}
,{0,0,9,0,0,20}
,{0,0,0,7,0,4}
,{0,0,0,0,0,0}                     
};
// for(int i = 0 ; i < 6 ; i++)
// {
//     for(int j = 0 ; j < 6 ; j++)
//     {
//         cout<<adj[i][j]<<" ";
//     }
//     cout<<endl;
// }
    vector<int> vis(6,0);
    vector<int> path;
    vis[0] = 1;
    int mx = 0;

    // path.push_back(0);
    while(findpath(adj,path,0,vis))
    {

        int u = 0;
        int path_flow = INT16_MAX;
        for(int i = 0 ; i < path.size() ; i++)
        {
            int v = path[i];
            path_flow = min(path_flow,adj[u][v]); 
            u = v;
        }

        mx += path_flow;
         u = 0;
        for(int i = 0 ; i < path.size() ; i++)
        {
            int v = path[i];
            adj[u][v] -= path_flow;
            adj[v][u] += path_flow;
            u = v;
        }
        path = {};
        vis = {1,0,0,0,0,0};
    }
    cout<<mx;
}