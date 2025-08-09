#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{

    int n = strs.size();

    int x = 201;

    for (int i = 0; i < n; i++)
    {
        if (x > strs[i].size())
        {
            x = strs[i].size();
        }
    }

    string ans = "";
    bool flag = false;
    for (int i = 0; i < x; i++)
    {
        char ch = strs[0][i];
        for (int j = 1; j < n; j++)
        {
            if (ch != strs[j][i])
            {
                flag = true;
                break;
            }
        }

        if (flag)
            break;
        ans.push_back(ch);
    }

    return ans;
}

int main(){

    vector<string> A = {"flower", "flow state", "floating"};

    cout << longestCommonPrefix(A) << '\n';
}