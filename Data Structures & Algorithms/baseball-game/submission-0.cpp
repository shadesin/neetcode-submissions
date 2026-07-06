#include <bits/stdc++.h>
class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int>scores;
        for(string x : operations)
        {
            int n = scores.size();
            if(x == "+")
            {
                scores.push_back(scores[n - 1] + scores[n - 2]);
            }
            else if(x == "D")
            {
                scores.push_back(2 * scores[n - 1]);
            }
            else if(x == "C")
            {
                scores.pop_back();
            }
            else
            {
                scores.push_back(stoi(x));
            }
        }
        int sum = 0;
        for(int x : scores)
        {
            sum += x;
        }
        return sum;
    }
};