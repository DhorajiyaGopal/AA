#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> v ={
        {2,2},
        {4,4},
        {5,6}
    };
    int n = v.size();
    double mn =(double) INT32_MAX;
    vector<int>res1;
    vector<int>res2;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i + 1 ; j < n ; j++)
        {
            double d = sqrt(pow(v[i][0] - v[j][0] , 2) + pow(v[j][1] - v[i][1] , 2));
            if(d < mn)
            {
                res1 = v[i];
                res2 = v[j];
            }
        }
    }
    cout<<"closest Pair :"<<endl;
    cout<<"pair1 :"<<res1[0]<<" "<<res1[1]<<endl;
    cout<<"pair2 :"<<res2[0]<<" "<<res2[1]<<endl;
}