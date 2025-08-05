#include<bits/stdc++.h>

using namespace std;

int String_matching_BF(string& text , string& pattern)
{
    int n = text.size();
    int m = pattern.size();
    
    for(int i = 0; i <= n - m; i++)
    {
        int j;
        for(j = 0; j < m; j++)
        {
            if(text[i + j] != pattern[j])
                break;
        }
        if(j == m)
            return i;
    }
    return -1;
}


int main()
{
    string text = "This is s test text";
    string pattern = "test";
    int ind = String_matching_BF(text, pattern);
    if(ind != -1)
        cout << "Pattern found at index: " << ind << endl;
    else
        cout << "Pattern not found index" << endl;
    return 0;
}