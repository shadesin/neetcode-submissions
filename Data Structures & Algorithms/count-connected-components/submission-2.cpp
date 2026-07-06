class Solution {
public:

    void dfs(vector<vector<int>> &adjlist, unordered_map<int, bool> &visited, int node, int n)
    {
        if(visited[node])
        {
            return;
        }
        visited[node] = true;
        for(auto x : adjlist[node])
        {
            if(!visited[x])
            {
                dfs(adjlist, visited, x, n);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adjlist(n, vector<int>());
        
        for(int i = 0; i < edges.size(); i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            adjlist[a].push_back(b);
            adjlist[b].push_back(a);
        }

        unordered_map<int, bool> visited;
        int c = 0;

        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                dfs(adjlist, visited, i, n);
                c++;
            }
        }
        return c;
    }
};
