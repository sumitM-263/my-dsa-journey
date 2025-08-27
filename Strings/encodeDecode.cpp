#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string encode(vector<string> &strs)
    {

        if (strs.empty())
            return "";

        string s = "";

        int n = strs.size();

        for (int i = 0; i < n; i++)
        {
            string t = "" + (to_string(strs[i].size()));
            s = s + t + "#" + strs[i];
        }

        return s;
    }

    vector<string> decode(string s)
    {

        if (s.empty())
            return {};

        vector<string> ans;

        for (int i = 0; i < s.size(); i++)
        {
            string curr = "";

            while (s[i] != '#')
            {
                curr += s[i];
                i++;
            }

            int x = stoi(curr);
            ans.push_back(s.substr(i + 1, x));
            i = i + x;
        }

        return ans;
    }
};
