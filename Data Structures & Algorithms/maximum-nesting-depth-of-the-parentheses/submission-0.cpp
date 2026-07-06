class Solution {
public:
    int maxDepth(string s) {
        stack<int>stk;
        int size = 0;
        int global = 0;
        for(int ch : s)
        {
            if(ch == '(')
            {
                stk.push(ch);
                size++;
            }
            else if(ch == ')')
            {
                global = max(global, size);
                stk.pop();
                size--;
            }
        }
        return global;
    }
};