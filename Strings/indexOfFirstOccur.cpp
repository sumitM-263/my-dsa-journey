#include <bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle)
{

    int m = haystack.size();
    int n = needle.size();

    if (m < n)
        return -1;

    int i = 0;
    int j = 0;
    int start = 0;
    while (i < m && j < n)
    {

        // cout << haystack[i] << ' ' << needle[j] << '\n';
        if (haystack[i] == needle[j])
        {
            i++, j++;
        }

        else
        {
            i = start + 1;
            start = i;
            j = 0;
        }

        if (j == n)
            return start;
    }

    return -1;
}

int strStr1(string hayStack, string needle){

    int m = hayStack.size();

    int ind = hayStack.find(needle);

    if(ind < m) return ind;

    return -1;
}



int main(){

    string s1 = "sadbutsad";
    string s2 = "uts";

    cout << strStr1(s1,s2) << '\n';
}