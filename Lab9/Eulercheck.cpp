#include<bits/stdc++.h>

using namespace std;


bool dfs(vector<vector<int>>& adj,int i,vector<int>& vis)
{
    vis[i] = 1;
    if(adj[i].size() % 2)
    {
        return 0;
    }
    for(auto it : adj[i])
    {
        if(!vis[it]  && !dfs(adj,it,vis))
            return 0;
    }
    return 1;
}

bool isEuler(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> vis(n,0);
    for(int i = 0 ;i < n ; i++)
    {
        if(adj[i].size() >= 1)
        {
            if(!dfs(adj,i,vis))
            {
                return 0;
            }
            break;
        }
    }

    for(int i = 0 ; i < n  ; i++)
    {
        if(vis[i] == 0 && adj[i].size() > 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    // vector<vector<int>> adj={{1, 2}, {0, 2},{0, 1}, {}}; // Euler path Exist
                          
    vector<vector<int>> adj={{1, 2}, {0, 2},{0, 1,3}, {3}}; // Euler path not Exist
    if(isEuler(adj))
    {
        cout<<"Euler path Exist";
    }
    else
    {
        cout<<"Euler path not Exist";
    }
}