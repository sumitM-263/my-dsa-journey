#include <bits/stdc++.h>
using namespace std;


bool isAnagram(string s, string t) {
        
        vector<int> hash(26,0);

        int m = s.size();
        int n = t.size();

        if(m!=n) return false;

        for(auto& i: s){
            hash[i-'a']++;
        }

        for(auto& i: t){
            hash[i-'a']--;
            if(hash[i-'a']<0) return false;
        }

        return true;

        
    }