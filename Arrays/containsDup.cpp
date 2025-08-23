#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int> &nums)
{

    sort(nums.begin(), nums.end());

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[i - 1])
            return true;
    }

    return false;
}

bool containsDuplicate1(vector<int> &nums)
{

    unordered_map<int, int> mpp;

    for (auto &i : nums)
    {
        if (mpp[i] > 0)
            return true;

        mpp[i]++;
    }

    return false;
}