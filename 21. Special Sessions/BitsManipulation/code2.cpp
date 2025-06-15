#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<string> AllPossibleStrings(string s) {
        vector<string> ans;
        int len = s.length();
        int total = (1 << len);  // 2^len subsequences

        for (int mask = 1; mask < total; mask++) { // start from 1 to skip empty string
            string temp = "";
            for (int i = 0; i < len; i++) {
                if (mask & (1 << i)) {
                    temp += s[i];
                }
            }
            ans.push_back(temp);
        }

        sort(ans.begin(), ans.end()); // optional, if output needs to be sorted
        return ans;
    }
};
