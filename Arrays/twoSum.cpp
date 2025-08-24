#include <bits/stdc++.h>
using namespace std;


vector<int> twoSum(vector<int> &nums, int target)
{

    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                return {i, j};
            }
        }
    }

    return {-1, -1};
}

vector<int> twoSum(vector<int> &nums, int target)
{

    int n = nums.size();

    vector<pair<int, int>> A;
    for (int i = 0; i < n; i++)
    {
        A.push_back({nums[i], i});
    }

    sort(A.begin(), A.end());

    int i = 0;
    int j = n - 1;

    int x = -1, y = -1;

    while (i < j)
    {
        int sum = A[j].first + A[i].first;

        if (sum == target)
        {
            x = A[i].second;
            y = A[j].second;
            break;
        }

        else if (sum < target)
            i++;

        else
            j--;
    }

    if (x < y)
        return {x, y};
    return {y, x};
}

vector<int> twoSum(vector<int> &nums, int target)
{

    int n = nums.size();

    unordered_map<int, int> mpp;

    int a = -1, b = -1;

    for (int i = 0; i < n; i++)
    {

        int x = nums[i];

        int y = target - nums[i];

        if (mpp.find(y) != mpp.end())
        {
            a = i;
            b = mpp[y];
            break;
        }

        mpp[nums[i]] = i;
    }

    if (a < b)
        return {a, b};
    return {b, a};
}