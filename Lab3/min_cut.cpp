#include<bits/stdc++.h>
using namespace std;


int find1(int a,vector<int>& arr)
{
    if(arr[a] != a)
    {
        return arr[a] = find1(arr[a],arr);
    }
    return arr[a];
}

void union1(int a,int b,vector<int>& arr)
{
    a = find1(a,arr);
    b = find1(b,arr);
    arr[a] = b;
}

int main()
{
    vector<vector<int>> adj;
    adj.push_back({0,1});
    adj.push_back({0,2});
    adj.push_back({2,3});
    adj.push_back({0,3});
    adj.push_back({1,3});

    vector<int> arr{0,1,2,3};
    int n = 4;
    srand(time(0));
    int mini = 5;
    for(int t = 0 ; t < n * n ; t++)
    {   
        arr = {0,1,2,3};
        int count = 4;
        while (count != 2)
        {
            int ind = (rand() % 5);
            if(find1(adj[ind][0],arr) != find1(adj[ind][1],arr))
            {
                union1(adj[ind][0],adj[ind][1],arr);
                count--;
            }
        }
        int r = 0;
        for(auto it: adj)
        {
            if(find1(it[0],arr) != find1(it[1],arr))
            {
                r++;
            }
        }
        mini = min(mini,r);
        
    }
    cout<<mini<<endl;
    
}