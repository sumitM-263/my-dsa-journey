#include <bits/stdc++.h>
using namespace std;


vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    int n = strs.size();

    unordered_map<string, vector<string>> mpp;

    for (int i = 0; i < n; i++)
    {
        string s = strs[i];

        sort(s.begin(), s.end());

        if (mpp.find(s) == mpp.end())
        {
            mpp[s] = {};
        }

        if (mpp.find(s) != mpp.end())
        {
            mpp[s].push_back(strs[i]);
        }
    }

    vector<vector<string>> ans;
    for (auto &i : mpp)
    {
        ans.push_back(i.second);
    }

    return ans;
}