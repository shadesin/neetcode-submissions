class Solution {
public:
    string foreignDictionary(vector<string>& words) {

        int n = words.size();

        unordered_map<char, int>nodenum_letter;
        unordered_map<int ,char>letter_nodenum;
        unordered_set<char>distinct_letters;

        for(int i = 0; i < n; i++)
        {
            for(char ch : words[i])
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
                while(idx_i < words[i].size() && idx_j < words[j].size() && words[i][idx_i] == words[j][idx_j])
                {
                    idx_i++;
                    idx_j++;
                }
                if(idx_i < words[i].size() && idx_j == words[j].size())
                {
                    return "";
                }
                if(idx_i == words[i].size() && idx_j <= words[j].size())
                {
                    continue;
                }
                char u = words[i][idx_i];
                char v = words[j][idx_j];
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
