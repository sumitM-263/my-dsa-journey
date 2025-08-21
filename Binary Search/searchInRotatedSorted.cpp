#include <bits/stdc++.h>
using namespace std;

int bs(vector<int> &nums, int target, int i, int j)
{

    while (i <= j)
    {
        int mid = i + (j - i) / 2;

        if (nums[mid] == target)
            return mid;

        else if (nums[mid] < target)
            i = mid + 1;

        else
            j = mid - 1;
    }

    return -1;
}

int findFirstPeak(vector<int> &A)
{
    int n = A.size();
    int low = 0, high = n - 1;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        // If mid element > next, mid is the peak
        if (mid < n - 1 && A[mid] > A[mid + 1])
            return mid;

        // If mid element >= low element, then peak lies to the right
        if (A[mid] >= A[low])
        {
            low = mid + 1;
        }
        else
        {
            // Otherwise, peak lies to the left
            high = mid - 1;
        }
    }

    return low; // low == high -> peak index
}
int search(vector<int> &nums, int target)
{

    int peak = findFirstPeak(nums);

    int n = nums.size();

    int ans = -1;

    ans = bs(nums, target, 0, peak);

    if (ans == -1)
    {
        ans = bs(nums, target, peak + 1, n - 1);
    }

    return ans;
}