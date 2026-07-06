class Solution {
public:
    string foreignDictionary(vector<string>& words) {

        // consecutive duplicate removal
        vector<string>unique_words;

        unique_words.push_back(words[0]);
        for(int i = 1; i < words.size(); i++)
        {
            if(words[i] != words[i - 1])
            {
                unique_words.push_back(words[i]);
            }
        }

        int n = unique_words.size();

        unordered_map<char, int>nodenum_letter;
        unordered_map<int ,char>letter_nodenum;
        unordered_set<char>distinct_letters;

        for(int i = 0; i < n; i++)
        {
            for(char ch : unique_words[i])
            {
                distinct_letters.insert(ch);
            }
        }

        int m = distinct_letters.size();

        vector<vector<int>>adjlist(m, vector<int>());

        int idx = 0;
        for(char ch : distinct_letters)
        {
            nodenum_letter[idx] = ch;
            letter_nodenum[ch] = idx++;
        }

        
        for(int i = 0; i < n - 1; i++)
        {
                int j = i + 1;
                int idx_i = 0, idx_j = 0;
                while(idx_i < unique_words[i].size() && idx_j < unique_words[j].size() && unique_words[i][idx_i] == unique_words[j][idx_j])
                {
                    idx_i++;
                    idx_j++;
                }
                if(idx_j == unique_words[j].size())
                {
                    return "";
                }
                if(idx_i == unique_words[i].size())
                {
                    continue;
                }
                char u = unique_words[i][idx_i];
                char v = unique_words[j][idx_j];
                int nodenum_u = letter_nodenum[u];
                int nodenum_v = letter_nodenum[v];
                adjlist[nodenum_u].push_back(nodenum_v);
        }

        vector<int>indegree(m, 0);
        string topo = "";

        for(int i = 0; i < m; i++)
        {
            for(int x : adjlist[i])
            {
                indegree[x]++;
            }
        }

        queue<int>q;

        for(int i = 0; i < m; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int node = q.front();
            topo += nodenum_letter[node];
            for(int x : adjlist[node])
            {
                indegree[x]--;
                if(indegree[x] == 0)
                {
                    q.push(x);
                }
            }
            q.pop();
        }

        if(topo.size() != m)
        {
            return "";
        }

        else
        {
            return topo;
        }
    }
};
