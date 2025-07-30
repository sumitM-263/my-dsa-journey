#include <bits/stdc++.h>
using namespace std;

// similar question is 739

// my LeetCode submission 
class StockSpanner {
public:

    vector<int> prices;

    StockSpanner() {
        
    }
    
    int next(int price) {
        prices.push_back(price);

        int n = prices.size();

        

        int p = n-1;

        while(prices[p]<=price){
            p--;
        }

        if(p==-1){
            return n;
        }

        
        return n-p-1;
    }
};


int main(){

    StockSpanner st;

    cout << st.next(100) << '\n';
    cout << st.next(80) << '\n';
    cout << st.next(60) << '\n';
    cout << st.next(70) << '\n';
    cout << st.next(60) << '\n';
    cout << st.next(75) << '\n';
    cout << st.next(85) << '\n';

}