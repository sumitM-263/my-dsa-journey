#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();

    vector<int> ans(n);

    int pfx = 1;

    ans[0] = pfx;

    for (int i = 1; i < n; i++)
    {
        pfx = pfx * nums[i - 1];
        ans[i] = pfx;
    }

    int sfx = 1;

    ans[n - 1] = ans[n - 1] * sfx;

    for (int i = n - 2; i >= 0; i--)
    {
        sfx = sfx * nums[i + 1];
        ans[i] = ans[i] * sfx;
    }

    return ans;
}

vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();

    vector<int> pfx(n, 1);
    vector<int> sfx(n, 1);

    for (int i = 1; i < n; i++)
    {
        pfx[i] = pfx[i - 1] * nums[i - 1];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        sfx[i] = sfx[i + 1] * nums[i + 1];
    }

    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        ans[i] = pfx[i] * sfx[i];
    }

    return ans;
}