#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n = weight.size();

        int maxWt = INT_MIN;

        int ans = 0;

        for(int i=0;i<n;i++){
            maxWt = max(maxWt, weight[i]);
            if(maxWt > weight[i]){
                ans++;
                maxWt = INT_MIN;
            }
        }

        return ans;
    }
};


int main(){

    Solution s;

    vector<int> A = {2,5,1,4,3};

    cout << s.maxBalancedShipments(A) << '\n';
}