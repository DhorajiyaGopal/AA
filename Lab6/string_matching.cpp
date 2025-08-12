#include<bits/stdc++.h>

using namespace std;

int give_state(string s,string p)
{
    while(s != p)
    {
        p.pop_back();
        s.erase(0,1);
    }
    return p.size();
} 
map<pair<int,char>,int> mp;
void make_table(string p)
{
    int n = p.size();
    set<char> st;
    for(auto it : p)
    {
        st.insert(it);
    }
    for(int i = 0 ; i <= n ; i++ )
    {

        for(auto it : st)
        {
            string s = p.substr(0,i+1);
            string p1 = s;
            if(i  == n)
            {
                 p1.erase(0,1);
                p1.push_back(it);
            }
            else
            {
                p1.pop_back();
                p1.push_back(it);

            }
            // cout<<p1<<" ";
            mp[{i,it}] = give_state(p1,s);
            // cout<<i<<" "<<it<<" "<< mp[{i,it}]<<endl;

        }
    }
}


int string_matching(string t,string p)
{
    make_table(p);
    int s = 0;
    int count = 0;
    for(auto it : t)
    {
        s = mp[{s,it}];
        // cout<<s<<" ";
        if(s == p.size())
        {
            count++;
        }
    }
    return count;
}
int main()
{
    string t = "AAAAAAAA";
    string p = "AAAAA";
    cout<<string_matching(t,p);
    return 0;
}