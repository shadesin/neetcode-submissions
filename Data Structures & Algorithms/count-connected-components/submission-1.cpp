class Solution {
public:
    void dfs(vector<vector<int>> &adj, unordered_map<int, bool> &visited, int node, int n)
    {
        if(visited[node])
        {
            return;
        }
        visited[node] = true;
        for(int vertex : adj[node])
        {
            if(!visited[vertex])
            {
                dfs(adj, visited, vertex, n);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        unordered_map<int, bool> visited;
        int count = 0;

        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                count++;
                dfs(adj, visited, i, n);
            }
        }
        return count;
    }
};
