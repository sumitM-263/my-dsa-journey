#include <bits/stdc++.h>
using namespace std;

// similar question is 739

// my LeetCode submission 
class StockSpanner {
public:

    vector<int> prices;
    stack<pair<int,int>> st;

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

    int next1(int price){
        int span = 1;

        while(!st.empty() && st.top().first <= price){
            span+=st.top().second;
            st.pop();
        }

        st.push({price, span});

        return span;
    }
};


int main(){

    StockSpanner st;

    cout << st.next1(100) << '\n';
    cout << st.next1(80) << '\n';
    cout << st.next1(60) << '\n';
    cout << st.next1(70) << '\n';
    cout << st.next1(60) << '\n';
    cout << st.next1(75) << '\n';
    cout << st.next1(85) << '\n';

}