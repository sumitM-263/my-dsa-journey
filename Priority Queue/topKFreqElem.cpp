#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    // counting the frequency
    unordered_map<int, int> mpp;
    for (auto &i : nums)
    {
        mpp[i]++;
    }

    vector<pair<int, int>> A;
    for (auto &p : mpp)
    {
        A.push_back({p.second, p.first});
    }

    // sort in decreasing order
    sort(A.rbegin(), A.rend());

    vector<int> ans;

    for (int i = 0; i < k; i++)
    {
        ans.push_back(A[i].second);
    }

    return ans;
}

vector<int> topKFrequent(vector<int> &nums, int k)
{
    // counting the frequency
    unordered_map<int, int> mpp;
    for (auto &i : nums)
    {
        mpp[i]++;
    }

    // priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (auto &p : mpp)
    {

        pq.push({p.second, p.first});

        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    vector<int> ans;

    while (!pq.empty())
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;
}